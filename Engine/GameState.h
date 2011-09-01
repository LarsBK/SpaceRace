#ifndef GAMESTATE
#define GAMESTATE

class GameState {

	public:

	/** Perform step.
	* returnvalue != 0 indicates failure.
	*/
	virtual int step();
	
	virtual void getName() =0;

};


#endif
