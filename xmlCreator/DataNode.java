import java.util.ArrayList;

import org.w3c.dom.*;


class DataNode{

    ArrayList <DataNode> children;

    String value;

    public DataNode(String v){
	children = new ArrayList<DataNode>();
	value = v;
    }

    String getValue(){
	return value;
    }

    public void addChild(DataNode dn){
	children.add(dn);
    }

    public DataNode getChild(int i){
	return children.get(i);
    }

    /**
     *creates a copy of the DataNode tree consisting
     * of Elements with TextNodes.
     *this is in a format that can be added to the xml root with
     *use of appendChild()
     *returns the root of the new tree, the root beeing this DataNode
     *
     *does requre that XmlCreator.doc is exists. 
     *This tree will be based on the that document.
     **/
    public Element getElementTree(){
	Element toReturn = XmlCreator.doc.createElement(getValue());

	for(DataNode dn : children){

	    dn.addThis(toReturn);
	}
	return toReturn;
    }
	
    private void addThis(Element parrent){

	if(children.isEmpty()){

	    parrent.appendChild(XmlCreator.doc.createTextNode(getValue()));

	}else{

	    Element e = XmlCreator.doc.createElement(getValue());
	    parrent.appendChild(e);

	    for(DataNode dn : children){

		dn.addThis(e);
	    }
	}
    }


}