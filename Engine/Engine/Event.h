#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>

namespace z {
	using namespace std;
	
	class EventBinding;//Listener;
	class Action;
	//class ActionHandler;

	class Event {
		string s;
		public:
		Event(string s);
		//bool equals(Event* e);
		string toString();
		enum EventState {UNDEFINED, STARTED, STOPPED};
		EventState state;
	};
/*
	class ErrorEvent : public Event {
		ErrorEvent(string s);
	};
*/
	/** EventListener (Internal)
	*/
	class EventBinding {
		vector<Action*> actionList;
		//Event* event; //if recived event returns true for equals(event):
		string event;

		public:
		EventBinding(string event); //Event* e);
		void addAction(Action* a);
		bool equals(string e);
		void fire(Event* e);
	};

	/** An action that can be performed
	* Create an action to represent an action
	* you class can perform and add it to the
	* engine with Engine::addAction()
	*/
	class Action {
		//string name; //ie "Jump"
		//ActionHandler* handler;
		//Event* event;
		public:
		//Action(string n, ActionHandler* h);
		virtual void fire(Event* e) =0;
		//bool equals(string s);
		virtual string getName(); //returns toString() by default
		virtual string toString() =0;
		//Event* getEvent();
	};
/*
	*ActionHandler interface
	* Internal
	
	class ActionHandler {
		public:
		virtual void handleAction(Action* a) =0;
	};
*/

}

#endif
