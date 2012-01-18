import java.awt.Dimension;

import javax.swing.JPanel;


class ShipComponentsPanel extends JPanel{
    Ship ship;

    ShipComponentsPanel(Ship s){
	ship = s;
	setBackground(java.awt.Color.green);
	setPreferredSize(new Dimension(600,200));
	setVisible(true);
    }

}