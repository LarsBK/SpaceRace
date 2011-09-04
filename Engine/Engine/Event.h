#ifndef EVENT
#define EVENT

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
		enum EventState {UNDEFINED, STARTED, STOPPED};
		EventState state;
	};

	class ErrorEvent : public Event {
		ErrorEvent(string s);
	};

	/** EventListener (Internal)
	*/
	class EventListener {
		vector<Action*> actionList;
		Event* event; //if recived event returns true for equals(event):

		public:
		EventListener(Event* e);
		void addAction(Action* a);
		bool equals(Event* e);
		void fire(Event* e);
	};

	/** An action that can be performed
	* Create an action to represent an action
	* you class can perform and add it to the
	* engine with Engine::addAction()
	*/
	class Action {
		string name; //ie "Jump"
		ActionHandler* handler;
		Event* event;
		public:
		Action(string n, ActionHandler* h);
		void fire(Event* e);
		bool equals(string s);
		string getName();
		Event* getEvent();
	};

	/**ActionHandler interface
	* Internal
	*/
	class ActionHandler {
		public:
		virtual void handleAction(Action* a) =0;
	};


}

#endif
