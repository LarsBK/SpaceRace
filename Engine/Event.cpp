#include "Event.h"

namespace z {

	Event::Event(string s) {
		eventString = s;
		std::cout << "added event " << s << std::endl;
	}

	void Event::addEventListener(EventListener* e) {
		listenerList.push_back(e);
	}

	bool Event::equals(Event* e) {
		return (e->getString() == s);
	}

	string Event::getString() {
		return s;
	}

	void EventListener::fire() {
		for(unsigned int i = 0; i < handlerList.size(); i++) {
			handlerList[i]->handleAction(action);
		}
	}

	EventListener::EventListener(Event* e) {
		event = e;
	}

	bool EventListener::equals(string l) {
		return (name == l);
	}

	void EventListener::fire() {
		std::cout << "fire! " << name << std::endl;
		callBack();
	}
}
