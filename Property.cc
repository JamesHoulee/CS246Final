#include "Property.h"
#include "Player.h"

#include <iostream>

using namespace std;

Property::Property (const string & name, int purchase, vector<string> set):
       	Cell{name}, purchase_cost{purchase} {

	owned = false;
	mortgaged = false;
	
	for (auto it = set.begin(); it != set.end(); ++it){
		set_ownership.emplace ((*it), 'z'); //'z' is the default/null owner
	}
}

int Property::getPrice () const {
	return purchase_cost;
}

bool Property::is_mortgaged () const {
	return mortgaged;
}

/* the commented is moved to Cell
void Property::setOwner (shared_ptr<Player> p){
	owner = p;
}

shared_ptr<Player> Property::getOwner () {
	return owner;
}
*/

void Property::mortgage () {
	owner->addMoney(purchase_cost/2);
	mortgaged = true;
}

void Property::unmortgage () {
	owner->removeMoney(purchase_cost/2);
	mortgaged = false;
}

int Property::getValue () const {
	return purchase_cost;
}

void Property::upgrade (int num){
        cout << name << " Cannot be upgraded" << endl;
}

void Property::downgrade (int num){
        cout << name << " Cannont be downgraded" << endl;
}


void Property::setOwner (shared_ptr<Player> p) {
	owner = p;
}

void Property::action (shared_ptr<Player> p, bool b) {
	on_cell.at(p->getPlayerChar()) = true;

	if (!owned) {
		cout << "Would you like to buy " << name << "? (Y/N)" << endl;
		string in;
		cin >> in;
		while (true){
			if (in == "Y" || in == "y"){
				try {
					p->buy(this);
				}
				catch (...) {
					cout << "Not enough money" << endl;
					break;
				}
				owned = true;
				owner = p;
				set_ownership.at(name) = p->getPlayerChar();
				notifyObservers();
				break;
			}
			else if (in == "N" || in == "n"){
				break;
				// auction the property
			}
			else {
				cout << "Please enter Y/N" << endl;
			}
		}
	}
	else if (p->getPlayerChar() == owner->getPlayerChar()){
		return;
	}
	else {
		cout << p->getPlayerName () << " is paying " << owner->getPlayerName() << " $" << getRent() << endl;
		p->pay(owner, getRent());
	}
}



// Observer and Subject method implementations
void Property::attach(Property * o) {
	observers.push_back(o);
}

void Property::notifyObservers() {

	for (int i = 0; i < observers.size(); i++) {
		observers[i]->notify(*this);
	}
}

void Property::notify (Property & whoNotified) {
	set_ownership.at(whoNotified.getName()) = whoNotified.getOwner()->getPlayerChar();
}
