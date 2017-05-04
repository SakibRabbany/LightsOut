#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.
  bool won;        // Grid in winning state
  TextDisplay *td; // The text display.

  void wonUpdate();   // checks if the grid is in a winning state

  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();
  

  bool isWon() const; // Call to determine if grid is in a winning state.
  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);  // Sets cell at row r, col c to On.
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
