#include "SpaceRace.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	Game* game = new SpaceRace();
	cout << game->getName() << endl;
	int i = game->run();
	delete game;
	return i;
}
