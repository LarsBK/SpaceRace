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
    final private static String rootName = "Ship";

    /**
     *used for testing
     **/
    public static void main(String[] args) throws Exception{
	String saveFile = "Test.xml"; 

	mergeFile("Test2.xml");


	/*
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
	*/

	createFile(saveFile);
    }
    
    private static void checkInit(){
	if(doc == null){
	    try{
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		DocumentBuilder builder = factory.newDocumentBuilder();
		
		doc = builder.newDocument();
		
		root = doc.createElement(rootName);

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

    /**
     *will merge data in in  xml-file
     *with teh data allready existing in the data structure.
     *the file most have a "root" named ship
     *any simulare names found in the existing tree and the file will 
     *be considered the same, and not be duplicated.
     *If there in storage or in the infile exists siblings with the same tagName 
     *then this method will merge into all of the siblings, there should therefor
     *not be sibling with equal names when this method is called.
     *returns false if merge failed.
     **/
    public static boolean mergeFile(String infilePos){
	checkInit();

	try{
	    File inFile = new File(infilePos);
	    DocumentBuilderFactory indbf = DocumentBuilderFactory.newInstance();
	    DocumentBuilder indb = indbf.newDocumentBuilder();
	    Document inDoc = indb.parse(inFile);
	    Element inAt = inDoc.getDocumentElement();
	    inAt.normalize();

	    //is the file compatable
	    if(inAt.getTagName().compareTo(rootName) != 0){
		if(testing){
		    System.out.println("rootName in " + infilePos + "is not " + rootName);
		}
		return false;
	    }

	    recursiveMerge(root, inAt);

	    return true;

	}catch(Exception e){
	    System.out.println("Failed to read file: " + infilePos);

	    if(testing){
		System.out.println("Error: " + e.getMessage());
	    }
	    return false;
	}

    }

    /**
     *recursivly merges every element in "inAt" into "storageAt"
     *used by mergeFile()
     **/
    private static void recursiveMerge(Element storageAt, Element inAt){
	System.out.println("--new revursivemerge call!");//----------
	if(testing){
	    if(storageAt.getTagName().compareTo(inAt.getTagName()) != 0){
		System.out.println("Doing recurcive merge and found a fault in the call of this method where storageAt.getTagName() is: " + storageAt.getTagName() + " and " + inAt.getTagName() + "is called with recurciveMerge(), they should be the same");
	    }
	}

	NodeList inNl = inAt.getElementsByTagName("*");

	for(int i = 0; i < inNl.getLength(); i++){
	    System.out.println("in "+ inAt.getNodeName() + ":");//---------

	    Element inAtChild = (Element)inNl.item(i);
	    System.out.println(" found "+ inAtChild.getNodeName() + ":");//---------
	 
	    //if its a attribute (leafnode)
	    if(inAtChild.getElementsByTagName("*").getLength() == 0 /*.hasChildNodes()*/){
		System.out.println(" found a attribute: '" + inAtChild.getNodeName()+"'");//----------
		System.out.println("    found attribute: '" + inAtChild.getTextContent()+"'");//----------




		storageAt.appendChild(doc.createElement(inAtChild.getNodeName()));

	    }else{

		NodeList storageNl = storageAt.getElementsByTagName(inAtChild.getTagName());

		//if its a non-attribute (node) that dont exist in the storage
		if(storageNl.getLength() == 0){

		    Element newStorageElement = doc.createElement(inAtChild.getNodeName());
		    storageAt.appendChild(newStorageElement);

		    recursiveMerge(newStorageElement, inAtChild);

		}else{//if its a non-attribute (node) that exists in the storage
		    
		    for(int j = 0; j < storageNl.getLength();j++){

			recursiveMerge((Element)storageNl.item(j), inAtChild);
		    }
		}
	    }
	}
    }


    /**
     *returns the Element that is a child of par with getTagName() equal to name
     *returns null if no fitting child was found
     **/
    private static Element getElement(Element par, String name){
	Element toReturn = null;

	NodeList nl = par.getElementsByTagName(name);

	if(nl.getLength() > 0){
	    toReturn = (Element)nl.item(0);
	}
	
	return toReturn;    
    }

}