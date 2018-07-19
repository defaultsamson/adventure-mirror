#include "Observer.h"

using namespace std;

//Call the notify function on every observers in the observer vector
void Observer::notifyObservers(){
	for (Observer *ob = observers.begin(); ob != observers.end(); ++ob){
		notifty(*ob);
	}
}

//Add a new observer to this subject
void Observer::attach(Observer *ob){
	observers.push_back(ob);
}
