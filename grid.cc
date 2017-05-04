#include <iostream>
#include "grid.h"
#include <string>
using namespace std;

Grid::Grid():gridSize{0}, won{false}, td{nullptr} {}

Grid::~Grid() {
	delete td;
}

void Grid::clearGrid() { 
	delete td;
	for (int r = 0 ; r < gridSize ; ++r) {
			theGrid.at(r).clear();
	}
	gridSize = 0;
}

void Grid::wonUpdate() {
	won = true;
	for (int i = 0 ; i < gridSize ; ++i) {
		for (int j = 0 ; j < gridSize ; ++j) {
			if (theGrid[i][j].getState()) won = false;
		}
	}
}

bool Grid::isWon() const { return won; }

void Grid::init(int n) {
	clearGrid();
	gridSize = n;
	td = new TextDisplay(gridSize);
	won = false;
	// filling the grid with cells
	for (int r = 0 ; r < gridSize ; ++r) {
		vector<Cell> Col;
		theGrid.push_back(Col);
		for (int c = 0 ; c < gridSize ; ++c) {
			Cell sel;
			sel.setCoords(r, c);
			theGrid.at(r).push_back(sel);
		}
	}

	// adding neighbours
	for (int r = 0 ; r < gridSize ; ++r) {
		for (int c = 0 ; c < gridSize ; ++c) {
			if ((r == 0) && (c == 0)) {						// top left corner case
				Cell *nbor1 = &theGrid[r][c+1];
				Cell *nbor2 = &theGrid[r+1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(td);
			}
			else if ((r == 0) && (c == gridSize - 1)){		// top right corner case
				Cell *nbor1 = &theGrid[r][c-1];
				Cell *nbor2 = &theGrid[r+1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(td);
			}
			else if ((r == gridSize - 1) && (c == 0)) {		// bottom left corner case
				Cell *nbor1 = &theGrid[r-1][c];
				Cell *nbor2 = &theGrid[r][c+1];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(td);
			}
			else if ((r == gridSize - 1) && (c == gridSize - 1)) {		// bottom right corner case
				Cell *nbor1 = &theGrid[r][c-1];
				Cell *nbor2 = &theGrid[r-1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(td);
			}
			else if ((r == 0) && ((c != 0) || (c != gridSize - 1))) {	// top row case except the corners
				Cell *nbor1 = &theGrid[r][c+1];
				Cell *nbor2 = &theGrid[r][c-1];
				Cell *nbor3 = &theGrid[r+1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(nbor3);
				theGrid[r][c].attach(td);
			}
			else if ((r == gridSize - 1) && ((c != 0) || (c != gridSize - 1))) {	// bottom row case except the corners
				Cell *nbor1 = &theGrid[r][c+1];
				Cell *nbor2 = &theGrid[r][c-1];
				Cell *nbor3 = &theGrid[r-1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(nbor3);
				theGrid[r][c].attach(td);
			}
			else if ((c == 0) && ((r != 0) || (r != gridSize - 1))) {		// left-most column case except the corners
				Cell *nbor1 = &theGrid[r+1][c];
				Cell *nbor2 = &theGrid[r-1][c];
				Cell *nbor3 = &theGrid[r][c+1];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(nbor3);
				theGrid[r][c].attach(td);
			}
			else if ((c == gridSize - 1) && ((r != 0) || (r != gridSize - 1))) {		// right-most column case except the corners
				Cell *nbor1 = &theGrid[r+1][c];
				Cell *nbor2 = &theGrid[r-1][c];
				Cell *nbor3 = &theGrid[r][c-1];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(nbor3);
				theGrid[r][c].attach(td);
			}
			else {										// case where the cells will have 4 neighbours
				Cell *nbor1 = &theGrid[r][c+1];
				Cell *nbor2 = &theGrid[r][c-1];
				Cell *nbor3 = &theGrid[r+1][c];
				Cell *nbor4 = &theGrid[r-1][c];
				theGrid[r][c].attach(nbor1);
				theGrid[r][c].attach(nbor2);
				theGrid[r][c].attach(nbor3);
				theGrid[r][c].attach(nbor4);
				theGrid[r][c].attach(td);
			}
		}
	} 
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  wonUpdate();
}

ostream &operator<<(ostream &out, const Grid &g) {
  cout << *(g.td);
}
