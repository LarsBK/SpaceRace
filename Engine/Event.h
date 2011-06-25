#include <iostream>
#include <vector>

namespace z {
	using namespace std;
	
	class EventListener;
	class Action;
	class ActionHandler;

	class Event {
		protected:
		string s;
		public:
		Event(string s);
		bool equals(Event* e);
		string getString();
	}

	//Only in Engine
	class EventListener {
		string eventString;
		vector<ActionHandler*> HandlerList;
		Event* event; //if recived event returns true for equals(event):
		Action* action; //this action is sent to every EventHandler in list

		public:
		EventListener(Event* e);
		void addActionHandler(ActionHandler* e);
		bool equals(string s);
		void fire();
	};

	class Action {
		string name; //ie "Jump"
	};

	//ActionHandler interface
	class ActionHandler {
		public:
		virtual void handleAction(Action a) =0;
	};
}
