#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "observer.h"

class Cell : public Observer {
  bool isOn = false;
  std::vector<Observer*> observers;
  int r, c;


 public:
  Cell();  // Default constructor

  bool getState() const; // Returns the value of isOn.
  int getRow() const; // Returns the value of r.
  int getCol() const; // Returns the value of c.
  void setOn();          // Explicitly sets me to on.
  void toggle();         // Toggles me between on and off.
  void setCoords(int r, int c);  // Tells me my row and column number.

  void attach(Observer *o);

  SubscriptionType subType() override;
  void notify(Cell &c) override;  // My neighbours will call this, to let me
                                  // know they've been switched.

  void notifyAllObservers();   // Alert observers whose subType is All
                               // Tell the display my new state.

  void notifySwitchObservers(); // Alert observers whose subType is Switch
                                // Tell all of my neighbours that I have been
                                // switched.
};
#endif
