import java.util.Stack;

import java.io.*;

import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

/*
//try 2
import sun.*;//org.apache.xerces.dom.*;
*/

import org.w3c.dom.*;

//guide at: http://www.javablogging.com/read-and-write-xml/

class XmlCreator{

    static Document doc;
    static Element root;

    final private static boolean testing = true;

    /**
     *used for testing
     **/
    public static void main(String[] args) throws Exception{
	String saveFile = "Test.xml"; 

	String[][] input = new String[2][];
	
	
	//used for testing of string arguments
	input[0] = new String[5];
	input[0][0] = "armor";
	input[0][1] = "health";
	input[0][2] = "15";
	input[0][3] = "texture";
	input[0][4] = "testjpg";

	input[1] = new String[7];
	input[1][0] = "living";
	input[1][1] = "health";
	input[1][2] = "15";
	input[1][3] = "population";
	input[1][4] = "10";
	input[1][5] = "texture";
	input[1][6] = "lqpic.jpg";

	addToFile(input);
	

	//testTree
	DataNode e = new DataNode("engine");
	DataNode eh = new DataNode("health");
	DataNode ehv = new DataNode("15");
	DataNode et = new DataNode("texture");
	DataNode etv = new DataNode("enginejpg");

	DataNode c = new DataNode("command");
	DataNode ch = new DataNode("health");
	DataNode chv = new DataNode("20");
	DataNode cp = new DataNode("crew");
	DataNode cpv = new DataNode("5");
	DataNode ct = new DataNode("texture");
	DataNode ctv = new DataNode("compic.jpg");

	e.addChild(eh);
	eh.addChild(ehv);
	e.addChild(et);
	et.addChild(etv);

	c.addChild(ch);
	ch.addChild(chv);
	c.addChild(cp);
	cp.addChild(cpv);
	c.addChild(ct);
	ct.addChild(ctv);

	addToFile(e);
	addToFile(c);

	createFile(saveFile);
    }
    
    private static void checkInit(){
	if(doc == null){
	    try{
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		DocumentBuilder builder = factory.newDocumentBuilder();
		
		doc = builder.newDocument();
		
		root = doc.createElement("ship");

		doc.appendChild(root);

	    }catch(Exception e){
		//burde ikke skje
		if(testing){
		    System.out.println("Failed to make a xml DocumentBuilder");
		}
	    }
	}
    }

    public static void addToFile(DataNode dn){
	checkInit();
	root.appendChild(dn.getElementTree());

    }

    public static void addToFile(String[][] data){
	checkInit();

	for(int i = 0; i < data.length; i++){
	    System.out.println("data: "+i + " "); //-------

	    Element cur = doc.createElement(data[i][0]);

	
	    for(int j = 1; j < (data[i].length -1); j+= 2){
		System.out.println(""+i + " " + j);

		Element el = doc.createElement(data[i][j]);

		el.appendChild(doc.createTextNode(data[i][j+1]));

		cur.appendChild(el);

	    }

	    root.appendChild(cur);
	}
    }

    public static void createFile(String fileName){

	try{
	
	    DOMSource source = new DOMSource(doc);

	    PrintStream ps = new PrintStream(fileName);
	    StreamResult result = new StreamResult(ps);

	    TransformerFactory transFac = TransformerFactory.newInstance();
	    Transformer transformer = transFac.newTransformer();

	    transformer.transform(source,result);

	}catch(Exception e){
	    //noe gikk galt
	    if(testing){
		System.out.println("Failed to create file");
	    }
	}
    }
}