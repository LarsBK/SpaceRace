#include "Event.h"

namespace z {

	Event::Event(string st) {
		s = st;
	}

	string Event::toString() {
		return s;
	}

	bool EventBinding::equals(string e) {
		return event == e;
	}

	EventBinding::EventBinding(string e) { //: actionList(1) {
		event = e;
	}

	void EventBinding::fire(Event* e) {
		//if(e->equals(event)) {
			for(unsigned int i = 0; i < actionList.size(); i++) {
				actionList[i]->fire(e);
			}
		//}
		
	}

	void EventBinding::addAction(Action* a) {
		actionList.push_back(a);
	}

	string Action::getName() {
		return toString();
	}
}
