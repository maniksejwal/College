import java.applet.Applet;
import java.awt.*;

public class Practical7a extends Applet {
    public void init(){
        setBackground(Color.CYAN);
        setForeground(Color.GRAY);
    }

    public void paint(Graphics graphics){
        graphics.fillRect(20, 50, 300, 300);

        Font f1 = new Font("Sansserif", Font.BOLD, 20);
        graphics.setFont(f1);
        graphics.setColor(Color.RED);
        graphics.drawString("My first applet", 50, 100);

        Font f2 = new Font("Arial", Font.ITALIC, 35);
        graphics.setFont(f2);
        graphics.setColor(Color.BLACK);
        graphics.drawString("2nd string", 50, 200);

        Color c = new Color(10, 20, 250);
        Font f3 = new Font("Times New Roman", Font.PLAIN, 50);
        graphics.setFont(f3);
        graphics.setColor(c);
        graphics.drawString("Hello", 50, 300);
    }
}
