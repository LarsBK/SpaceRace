
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ShipComponentType extends JPanel {
	String name;
	int cost;
	int weight;
	Color color;

	ShipComponentType(String s) {
		name = s;
		cost = (int) (500*Math.random());
		weight = (int) (500*Math.random());
		color = new Color((float)Math.random(),(float)Math.random(),(float)Math.random());
	}

	ShipComponentType(String n, int c, int w, Color o) {
		name = n;
		cost = c;
		w = w;
		color = o;
	}

	public ShipComponent getInstance() {
		return new ShipComponent(this);
	}

	protected void paintComponent(Graphics g) {
		g.setColor(color);
		g.fillRect(0,0,32,32);
	}

	public String toString() {
		return name;
	}

	public Color getColor() {
		return color;
	}
}

class ShipComponent {

	ShipComponentType type;
	int x = 0;
	int y = 0;

	ShipComponent(ShipComponentType t) {
		type = t;
	}

	public ShipComponentType getType() {
		return type;
	}
	
	protected void paintComponent(Graphics g) {
		g.setColor(type.getColor());
		//System.out.println("Painting @ " + x + " " + y);
		g.fillRect(x,y,32,32);
	}

	public void setX(int xi) {
		x = xi;
	}
	public void setY(int yi) {
		y = yi;
	}

}
