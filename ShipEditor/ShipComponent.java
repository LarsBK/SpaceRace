
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ShipComponentType extends JPanel {
	String name;
	int cost;
	int mass;
	int thrust;
	int power;
	int population;
	Color color;

	ShipComponentType(String s) {
		name = s;
		cost = (int) (500*Math.random());
		mass = (int) (500*Math.random());
		//thrust = (int) (500*Math.random());
		power = (int) (500*Math.random());
		population = (int) (3*Math.random());
		color = new Color((float)Math.random(),(float)Math.random(),(float)Math.random());
	}

	ShipComponentType(String n, int c, int w, int t, int p, int pop, Color o) {
		name = n;
		cost = c;
		mass = w;
		thrust = t;
		power = p;
		population = pop;
		color = o;
	}

	public ShipComponent getInstance(Ship p) {
		return new ShipComponent(this, p);
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

	public int getCost() {
		return cost;
	}

	public int getMass() {
		return mass;
	}

	public int getThrust() {
		return thrust;
	}

	public int getPower() {
		return power;
	}

	public int getPopulation() {
		return population;
	}

}

class ShipComponent {

	ShipComponentType type;
	int x = 0;
	int y = 0;
	Ship ship;

	ShipComponent(ShipComponentType t, Ship p) {
		type = t;
		ship = p;
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
