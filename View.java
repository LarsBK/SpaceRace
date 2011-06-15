import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class View extends JPanel {

	//ShipComponent root = new ShipComponent("Root");
	static ShipComponentType current;
	int x;
	int y;
	int tileSize = 32;
	ShipComponent[][] array = new ShipComponent[20][20];

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

	private void place(int xi, int yi, ShipComponentType c) {
		int cx = xi/tileSize;
		int cy = yi/tileSize;
		ShipComponent s = c.getInstance();
		s.setX(cx*tileSize);
		s.setY(cy*tileSize);
		array[cx][cy] = s;
		//repaint(0,0,getWidth(),getHeight());
	}

	public void paintComponent (Graphics g) {
		g.setColor(Color.black);
		g.fillRect(0,0,getWidth(),getHeight());
		
		paintArray(g);
		/*if(current != null) {
			current.setX(x);
			current.setY(y);
			current.paintComponent(g);
		}*/
	}

	private void paintArray(Graphics g) {
		System.out.println("Painting array");
		for(int i = 0; i<array.length; i++) {
			for(int u=0; u<array[0].length; u++) {
				if(array[i][u] != null) {
					array[i][u].paintComponent(g);
				}
			}
		}
	}

	class mouseListener extends MouseAdapter {
		public void mouseMoved(MouseEvent e) {
			x = (int) e.getPoint().getX();
			y = (int) e.getPoint().getY();
			System.out.println("x: " + x/tileSize + "y: " + y/tileSize);
			repaint();//repaint(0,0,getWidth(),getHeight());
		}
		public void mouseReleased(MouseEvent e) {
			System.out.println("lksdjf");
			place(x,y,current);
			repaint();
		}
	}
}

