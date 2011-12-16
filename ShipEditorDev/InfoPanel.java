import javax.swing.JPanel;
import java.awt.Dimension;

class InfoPanel extends JPanel{
    Ship ship;

    InfoPanel(Ship s){
	ship = s;
	setPreferredSize(new Dimension(400,200));
	setBackground(java.awt.Color.magenta);
	setVisible(true);
    }
}