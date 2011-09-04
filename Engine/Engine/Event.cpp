#include "Event.h"

namespace z {

	Event::Event(string st) {
		s = st;
	}

	bool Event::equals(Event* e) {
		return (e->getString() == s);
	}

	string Event::getString() {
		return s;
	}

	ErrorEvent::ErrorEvent(string s) : Event("ERROR: " + s) {
		cout << "ERROR: " << s;
	}

	EventListener::EventListener(Event* e) {
		event = e;
	}

	void EventListener::fire(Event* e) {
		if(e->equals(event)) {
			for(unsigned int i = 0; i < actionList.size(); i++) {
				actionList[i]->fire(e);
			}
		}
	}

	void EventListener::addAction(Action* a) {
		actionList.push_back(a);
	}

	Action::Action(string n, ActionHandler* h) {
		name = n;
		handler = h;
	}

	void Action::fire(Event* e) {
		event = e;
		handler->handleAction(this);
	}

	Event* Action::getEvent() {
		return event;
	}

	bool Action::equals(string s) {
		return (s == name);
	}

	string Action::getName() {
		return name;
	}

}
