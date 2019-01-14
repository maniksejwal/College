import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Practical8b extends Applet implements ActionListener {
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

    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {

    }
}
