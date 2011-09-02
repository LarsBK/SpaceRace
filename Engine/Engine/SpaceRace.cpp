#include "SpaceRace.h"

string SpaceRace::getName() {
	string s;
	s += "Space Race! built: ";
	s += __DATE__;
	s += " ";
	s += __TIME__;
	return s;
}
