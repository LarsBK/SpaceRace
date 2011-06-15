
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
		add(new componentList());
		//setPreferredSize(new Dimension(300,300));
		setVisible(true);
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
		ShipComponentType[] c = new ShipComponentType[5];
		c[0] = new ShipComponentType("engine");
		c[1] = new ShipComponentType("railgun");
		c[2] = new ShipComponentType("sickbay");
		c[3] = new ShipComponentType("Combat Information Center");
		c[4] = new ShipComponentType("Helm");

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
		add(new JLabel("Cost: " + c.cost)); //, BorderLayout.CENTER);
		add(new JLabel("Weight: " + c.weight + "kg")); //, BorderLayout.CENTER);
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
