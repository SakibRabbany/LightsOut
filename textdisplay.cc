#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n):gridSize{n} {
	for (int r = 0 ; r < gridSize ; ++r) {
		vector<char> Col;
		theDisplay.push_back(Col);
		for (int c = 0 ; c < gridSize ; ++c) {
			theDisplay.at(r).push_back('_');
		}
	}
}

void TextDisplay::notify(Cell &c) {
	int i = c.getRow();
	int j = c.getCol();
	bool state = c.getState();
	if (state) {
		theDisplay[i][j] = 'X';
	}
	else {
		theDisplay[i][j] ='_';
	}
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int r = 0 ; r < td.gridSize ; ++r) {
		for (int c = 0 ; c < td.gridSize ; ++c) {
			out << td.theDisplay[r][c];
		}
		out << endl;
	}
	return out;
}
