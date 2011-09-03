#ifndef GAMESTATE
#define GAMESTATE

#include "Game.h"
#include <string>
using namespace std;

class Game;

/** The gamestate class
* Loading should be done in load()
* NOT in the constructor or run().
*/
class GameState {

	public:

	/** Run gamestate.
	* This gamestate will be removed up
	* on return returnvalue != 0 indicates
	* failure.
	*/
	virtual int run();

	/** Preform any time-consuming
	* work here
	*/
	virtual int load(Game* game);

	virtual string getName() =0;

};


#endif
