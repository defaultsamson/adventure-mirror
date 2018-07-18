#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>

enum class StateType {Moving, Attack, Pickup};

class Observer {
        vector<Observer*> observers;
	StateType state;
public:
	//getter and setter functions for state
        stateType getState(){
		return state;
	}

	void setState(stateType type){
		state = type;
	}

	void notifyObservers();

	void attach(Observer *ob);

	virtual void notify(Observer &ob) = 0;
}

#endif
~           
