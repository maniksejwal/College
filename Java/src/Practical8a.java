import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Practical8a extends Applet implements MouseListener{
    private String str = "";
    int i;
    @Override
    public void paint(Graphics graphics) {
        super.paint(graphics);
        graphics.drawString(str, 10 *i++, 100);
    }

    @Override
    public void init() {
        super.init();
        addMouseListener(this);
    }

    @Override
    public void mouseClicked(MouseEvent mouseEvent) {
        str += "mouseClicked";
        repaint();
    }

    @Override
    public void mousePressed(MouseEvent mouseEvent) {
        str += "mousePressed";
        repaint();
    }

    @Override
    public void mouseReleased(MouseEvent mouseEvent) {
        str += "mouseReleased";
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent mouseEvent) {
        str += "mouseEntered";
        repaint();
    }

    @Override
    public void mouseExited(MouseEvent mouseEvent) {
        str += "mouseExited";
        repaint();
    }
}