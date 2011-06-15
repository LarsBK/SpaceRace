import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class View extends JPanel {
	
	Ship ship = new Ship();
	//ShipComponent root = new ShipComponent("Root");
	static ShipComponentType current;
	int x;
	int y;
	int tileSize = 32;
	//ShipComponent[][] array = new ShipComponent[20][20];

	View() {
		super();
		JLabel label = new JLabel("View");
		//place(200,200,root);
		//label.setBackground(Color.GREEN);
		//label.setOpaque(true);
		setPreferredSize(new Dimension(400, 400));
		add(label);
		addMouseMotionListener(new mouseListener());
		addMouseListener(new mouseListener());
		setVisible(true);
	}

	static public void setCurrent(ShipComponentType c) {
		current = c;
	}

	private int toCor(int c) {
		return c/tileSize;
	}

	private void remove(int xi, int yi) {
		ship.remove(toCor(xi),toCor(yi));
	}

	private void place(int xi, int yi, ShipComponentType c) {
		int cx = xi/tileSize;
		int cy = yi/tileSize;
		ShipComponent s = c.getInstance(ship);
		s.setX(cx*tileSize);
		s.setY(cy*tileSize);
		ship.add(cx,cy,s);
		//repaint(0,0,getWidth(),getHeight());
	}

	public void paintComponent (Graphics g) {
		g.setColor(Color.black);
		g.fillRect(0,0,getWidth(),getHeight());
		
		ship.paintArray(g);
		/*if(current != null) {
			current.setX(x);
			current.setY(y);
			current.paintComponent(g);
		}*/
	}


	class mouseListener extends MouseAdapter {
		public void mouseMoved(MouseEvent e) {
			x = (int) e.getPoint().getX();
			y = (int) e.getPoint().getY();
			//System.out.println("x: " + x/tileSize + "y: " + y/tileSize);
			//repaint();//repaint(0,0,getWidth(),getHeight());
		}
		public void mouseReleased(MouseEvent e) {
			//System.out.println("lksdjf");
			if(e.getButton() == MouseEvent.BUTTON1){
				place(x,y,current);
				repaint();
			} else if (e.getButton() == MouseEvent.BUTTON3) {
				remove(x,y);
				repaint();
			}
		}
	}
}

