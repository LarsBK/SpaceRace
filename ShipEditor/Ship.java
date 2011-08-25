import java.awt.*;

class Ship {

	ShipComponent[][] array = new ShipComponent[20][20];
	int budget = 5000;
	int thrust = 0;
	int mass = 0;
	int power = 0;
	int population = 0;

	Ship() {
		System.out.println(this);
	}


	public void remove(int x, int y) {
	
		ShipComponent c = array[x][y];
		budget += c.getType().getCost();
		thrust -= c.getType().getThrust();
		mass -= c.getType().getMass();
		power -= c.getType().getPower();
		population -= c.getType().getPopulation();

		System.out.println(this);
		array[x][y] = null;
	}

	public void add(int x, int y, ShipComponent c) {
		if(c.getType().getCost() < budget) {
		if(array[x][y] != null) {
			remove(x,y);
		}
		array[x][y] = c;
		budget -= c.getType().getCost();
		thrust += c.getType().getThrust();
		mass += c.getType().getMass();
		power += c.getType().getPower();
		population += c.getType().getPopulation();
		System.out.println(this);
		}
	}

	public String toString() {
		return new String("$ left: " + budget + "\n" + "Acceleration: " + (double)thrust/mass +
			"\nPower: " + power + "\nMax population: " + population);
	}

	public void paintArray(Graphics g) {
		////System.out.println("Painting array");
		for(int i = 0; i<array.length; i++) {
			for(int u=0; u<array[0].length; u++) {
				if(array[i][u] != null) {
					array[i][u].paintComponent(g);
				}
			}
		}
	}

}
