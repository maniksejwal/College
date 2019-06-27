import java.applet.Applet;
import java.awt.*;

public class Practical7b extends Applet {
    public void paint(Graphics graphics){
        graphics.setFont(new Font("Times new roman", Font.BOLD, 23));
        graphics.setColor(Color.RED);
        graphics.drawString("Always keep smiling", 30, 30);
        graphics.drawOval(60, 60, 200, 200);
        graphics.fillOval(90, 120, 50, 20);
        graphics.fillOval(190, 120, 50, 20);
        graphics.drawLine(165, 125, 165, 175);
        graphics.drawArc(110, 130, 95, 95, 0, -180);
        graphics.drawLine(165, 175, 150, 150);
    }
}
