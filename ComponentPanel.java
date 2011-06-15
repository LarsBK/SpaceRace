
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ComponentPanel extends JPanel {

	ComponentPanel() {
		super();
		setLayout(new BoxLayout(this,BoxLayout.PAGE_AXIS));
		setBorder(BorderFactory.createLineBorder(Color.black));
		//add(new JSeparator(SwingConstants.VERTICAL));
		//add(new JLabel("tools"));
		//add(new JLabel("tools"));
		//add(new JLabel("tools"));
		//add(new JPanel());
		add(new componentListScroll());
		//setPreferredSize(new Dimension(300,300));
		setVisible(true);
	}
}

class componentListScroll extends JScrollPane {

	componentListScroll() {
		super(new componentList());
	}
}

class componentList extends JPanel {

	componentElement selected = null;

	public void select(componentElement c) {
		if(selected != null)
			selected.unselect();
		selected = c;
		selected.select();
		View.setCurrent(c.getComponent());
	}

	public componentElement getSelected() {
		return selected;
	}

	componentList() {
		super();
		setLayout(new BoxLayout(this,BoxLayout.PAGE_AXIS));
		add(new JLabel("Components:"));
		ShipComponentType[] c = new ShipComponentType[8];
		c[0] = new ShipComponentType("engine", 100, 100, 800, 200, 0, Color.red);
		c[1] = new ShipComponentType("railgun");
		c[2] = new ShipComponentType("sickbay");
		c[3] = new ShipComponentType("CIC");
		c[4] = new ShipComponentType("Helm");
		c[5] = new ShipComponentType("Armor", 50, 300, 0, 0, 0, Color.white);
		c[6] = new ShipComponentType("Hallway", 20, 50, 0, 20, 3, Color.blue);
		c[7] = new ShipComponentType("Fusion Reactor", 500, 1000, 0, -1000, 0, Color.yellow);

		componentElement l = new componentElement(c[0],this);
		add(l);
		select(l);

		for(int i = 1; i < c.length; i++) {
			add(new componentElement(c[i],this));
		}
		
		//JList list = new JList(c);
		//add(list);

	}
}

class componentElement extends JPanel implements ActionListener {
	ShipComponentType c;
	boolean selected = false;
	componentList list;
	Color old;

	componentElement(ShipComponentType comp, componentList l) {
		list = l;
		//setPreferredSize(new Dimension(200,200));
		c = comp;
		setBorder(BorderFactory.createTitledBorder(c.toString()));//Color.black));
		setLayout(new BoxLayout(this, BoxLayout.PAGE_AXIS));
		//add(new JLabel(c.toString())); //, BorderLayout.PAGE_START);
		add(new JLabel("Cost: " + c.getCost())); //, BorderLayout.CENTER);
		add(new JLabel("Weight: " + c.getMass() + "kg"));
		add(new JLabel("Thrust: " + c.getThrust() + "N"));
		add(new JLabel("Power: " + c.getPower() + "kw"));
		add(new JLabel("Population: " + c.getPopulation()));
		add(c);
		JButton button = new JButton("Select");
		button.addActionListener(this);
		add(button);
		//add(new JSeparator(SwingConstants.HORIZONTAL));
	}
	
	public void actionPerformed(ActionEvent e) {
		list.select(this);
	}

	public ShipComponentType getComponent() {
		return c;
	}

	public void select() {
		selected = true;
		old = getBackground();
		setBackground(Color.lightGray);
	}
	public void unselect() {
		selected = false;
		setBackground(old);
	}
}
