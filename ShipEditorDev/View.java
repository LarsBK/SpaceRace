import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JPanel;
import javax.swing.JFrame;

class View extends JFrame{

    View(Ship s){
	super("SpaceRace");
	setDefaultCloseOperation(EXIT_ON_CLOSE);
	setPreferredSize(new Dimension(1200,800));
	setLayout(new BorderLayout());
	add(new LeftPanel(s) , BorderLayout.CENTER);
	add(new RightPanel(s) , BorderLayout.LINE_END);
	setBackground(java.awt.Color.black);
	pack();
	setVisible(true);
    }
}


class LeftPanel extends JPanel{

    LeftPanel(Ship s){
	setLayout(new BorderLayout());
	setBackground(java.awt.Color.pink);
	add(new ShipBuilder(s), BorderLayout.CENTER);
	add(new ShipComponentsPanel(s), BorderLayout.PAGE_END);
    }
}

class RightPanel extends JPanel{
    RightPanel(Ship s){
	setLayout(new BorderLayout());
	setBackground(java.awt.Color.blue);
	add(new ResearchTree(s), BorderLayout.CENTER);
	add(new InfoPanel(s), BorderLayout.PAGE_END);
	setVisible(true);
    }

}