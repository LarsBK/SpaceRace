import javax.swing.JPanel;
import java.awt.Dimension;

class ShipBuilder extends JPanel{
    Ship ship;

    ShipBuilder(Ship s){
	ship = s;
	setBackground(java.awt.Color.red);
	setPreferredSize(new Dimension(50,50));
	//	setVisible(true);
    }


}


