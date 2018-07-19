#include "Observer.h"

using namespace std;

//Call the notify function on every observers in the observer vector
void Observer::notifyObservers(){
	for (Observer *ob: observers){
		ob->notify(*this);
	}
}

//Add a new observer to this subject
void Observer::attach(Observer *ob){
	observers.emplace_back(ob);
}

StateType Observer::getState(){
	return state;
}

void Observer::setState(StateType type){
	state = type;
}