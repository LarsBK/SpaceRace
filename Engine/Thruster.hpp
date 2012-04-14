#ifndef THRUSTER_GVIK24SS
#define THRUSTER_GVIK24SS

#include "Engine/TexturedGameObject.h"

using namespace z;

class Thruster;

class ThrustAction : public Action {
	Thruster* thruster;

	public:
	ThrustAction(Thruster* t);

	virtual string toString() {return "thrust";}
	virtual void fire(Event* e);
};

class Thruster : public TexturedGameObject {
	
	ThrustAction ta;

	public:

	Thruster(Engine* e);
	virtual float shapeWidth(){return 10;}
	virtual float shapeHeight(){return 10;}

};

#endif /* end of include guard: PLANET_XGKTBIM */
