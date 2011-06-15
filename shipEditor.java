import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class shipEditor {
	 public static void main(String[] args) {
		new editorWindow("Ship Editor");
	 }

}

class editorWindow extends JFrame {
	
	editorWindow(String s) {
		super(s);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setPreferredSize(new Dimension(800,600));
		add(new View(),BorderLayout.CENTER);
		add(new ComponentPanel(), BorderLayout.LINE_END);
		//add(new Toolbox(), BorderLayout.PAGE_END);
		pack();
		setVisible(true);
	}
}








