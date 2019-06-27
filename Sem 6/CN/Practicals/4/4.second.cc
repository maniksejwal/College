/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/netanim-module.h"
#include "ns3/mobility-module.h"
 
// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1   n2   n3   n4
//    point-to-point  |    |    |    |
//                    ================
//                      LAN 10.1.2.0
 
 
using namespace ns3;
 
NS_LOG_COMPONENT_DEFINE ("SecondScriptExample");
 
int
main (int argc, char *argv[])
{
  bool verbose = true;
 
// Number of Nodes in CSMA, If we make it 4 then Channel of 5 will be made.
  uint32_t nCsma = 3;
 
  CommandLine cmd;
  cmd.AddValue ("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
  cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);
 
  cmd.Parse (argc,argv);
 
  if (verbose)
    {
      LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
      LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);
    }
 
// Check if user sends value 0 change it to 1
  nCsma = nCsma == 0 ? 1 : nCsma;
 
 
  NodeContainer p2pNodes;
// 2 Nodes n0, n1
  p2pNodes.Create (2);
 
  NodeContainer csmaNodes;
// Add the second node of P2P to CSMA 
  csmaNodes.Add (p2pNodes.Get (1));
  csmaNodes.Create (nCsma);
 
  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));
 
  NetDeviceContainer p2pDevices;
  p2pDevices = pointToPoint.Install (p2pNodes);
 
  CsmaHelper csma;
// 100Mbps is the default DataRate of Ethernet 
  csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
  csma.SetChannelAttribute ("Delay", TimeValue (NanoSeconds (6560)));
 
  NetDeviceContainer csmaDevices;
  csmaDevices = csma.Install (csmaNodes);
 
// Protocol Stack 
  InternetStackHelper stack;
 
  stack.Install (p2pNodes.Get (0));
// Install CSMA Media Access Control Protocol at all Nodes 
  stack.Install (csmaNodes);
 
  Ipv4AddressHelper address;
// Base address given to first one, i.e. P2P
  address.SetBase ("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer p2pInterfaces;
  p2pInterfaces = address.Assign (p2pDevices);
 
// Address given to CSMA, i.e. P2P
  address.SetBase ("10.1.2.0", "255.255.255.0");
  Ipv4InterfaceContainer csmaInterfaces;
  csmaInterfaces = address.Assign (csmaDevices);
 
  UdpEchoServerHelper echoServer (9);
 
  ApplicationContainer serverApps = echoServer.Install (csmaNodes.Get (nCsma));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));
 
// Is at last node of CSMA 
  UdpEchoClientHelper echoClient (csmaInterfaces.GetAddress (nCsma), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));
 
// CLient is at 0th Node of P2P
  ApplicationContainer clientApps = echoClient.Install (p2pNodes.Get (0));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (10.0));
 
  Ipv4GlobalRoutingHelper::PopulateRoutingTables ();
 
  pointToPoint.EnablePcapAll ("Aniruddha");
  csma.EnablePcap ("Aniruddha", csmaDevices.Get (1), true);
/*
  MobilityHelper mob;
  mob.SetMobilityModel("ns3::ConstantPositionMobilityModel");
  mob.Install(p2pNodes);
  mob.Install(csmaNodes);
   
  AnimationInterface anim("second.xml");
  AnimationInterface::SetConstantPosition (p2pNodes.Get(0),10,20);
  AnimationInterface::SetConstantPosition (p2pNodes.Get(1),30,20);
  AnimationInterface::SetConstantPosition (csmaNodes.Get(1),40,20);
  AnimationInterface::SetConstantPosition (csmaNodes.Get(2),50,20);
  AnimationInterface::SetConstantPosition (csmaNodes.Get(3),60,20);
  anim.EnablePacketMetadata(true);*/
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
