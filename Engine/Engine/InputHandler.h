#include "Engine.h"
#include <vector>
#include <SFML/System.hpp>


namespace z {

	class InputHandler : public Module {
		
		vector<string> names;
		vector<sf::Key::Code> codes;
		vector<void (*f)(bool press)> callBack;

		void addCallBack(string name, void (*func)(bool pressed));
	}
}
