#include <iostream>
#include <vector>

namespace z {
	using namespace std;
	
	class EventListener;
	class Action;
	class ActionHandler;

	class Event {
		string s;
		public:
		Event(string s);
		bool equals(Event* e);
		string getString();
	}

	//Only in Engine
	class EventListener {
		vector<Action*> actionList;
		Event* event; //if recived event returns true for equals(event):

		public:
		EventListener(Event* e);
		void addAction(Action* a);
		bool equals(Event* e);
		void fire();
	};

	class Action {
		string name; //ie "Jump"
		ActionHandler* handler;
		public:
		Action(string n, ActionHandler* h);
		fire();
		equals(string s);
	};

	//ActionHandler interface
	class ActionHandler {
		public:
		virtual void handleAction(Action a) =0;
	};
}
