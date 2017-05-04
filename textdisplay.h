#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;	// text display grid
  const int gridSize;							// size of the grid
 public:
  TextDisplay(int n);							// constructor

  void notify(Cell &c) override;				// notifies the grid when cell c is toggled
  SubscriptionType subType() override;			// returns the subscription type of the grid

  ~TextDisplay();								// destructor

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);	// prints the grid
};

#endif
