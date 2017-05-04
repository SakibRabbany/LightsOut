#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
	isOn = true;
	notifyAllObservers();
}

void Cell::toggle() {
	if (isOn == true) {
		isOn = false;
	} else {
		isOn = true;
	}
	notifySwitchObservers();
	notifyAllObservers();
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) { 
	observers.push_back(o);
}

void Cell::notify(Cell &) {
	if (isOn == true) {
		isOn = false;
	}
	else {
		isOn = true;
	}
	notifyAllObservers();
}

SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
	for (auto it : observers) {
		if (it->subType() == SubscriptionType::All) {
			it->notify(*this);
		}
	}
}

void Cell::notifySwitchObservers() {
	for (auto it : observers) {
		if (it->subType() == SubscriptionType::SwitchOnly) {
			it->notify(*this);
		}
	}
}
