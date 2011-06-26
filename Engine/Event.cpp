#include "Event.h"

namespace z {

	Event::Event(string s) {
		eventString = s;
		std::cout << "added event " << s << std::endl;
	}

	bool Event::equals(Event* e) {
		return (e->getString() == s);
	}

	string Event::getString() {
		return s;
	}

	EventListener::EventListener(Event* e) {
		event = e;
	}

	bool EventListener::equals(Event* e) {
		return (event->equals(e));
	}

	void EventListener::fire() {
		std::cout << "fire! " << event->getString() << std::endl;
		for(unsigned int i = 0; i < actionList.size(); i++) {
			actionList[i]->fire();
		}
	}

	void EventListener::addAction(Action* a) {
		actionList.push_back(a);
	}

	Action::Action(string n, ActionHandler* h) {
		name = n;
		handler = h;
	}

	void Action::fire() {
		handler->handleAction(this);
	}

	bool Action::equals() {
		return (s == name);
	}

	string Action::getName() {
		return name;
	}

}
