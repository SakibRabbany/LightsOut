#include <iostream>
#include <string>
#include "grid.h"
using namespace std;


void usage () {
	cout <<  "commands:" << endl <<
		 "new number: where number is the dimention of the board" << endl << 
		 "game number: where number is the number of moves the game has to be finished by" << endl << 
		 "switch number number: the coordinate of the light to be toggled" << endl; 
}


int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;

 usage();

  while (true) {
    try {
      cin >> cmd;
    }
    catch (ios::failure &) {
      return 0;
    }
    if (cmd == "new") {
      int n;
      try {
        cin >> n;
      }
      catch (ios::failure &) {
        return 0;
      }
      g.init(n);
    }
    else if (cmd == "init") {
      int r = 0, c = 0;
      while (true) {
        try {
          cin >> r >> c;
        }
        catch (ios::failure &) {
          return 0;
        }
      	if ((r == -1) && (c == -1)) break;
      	g.turnOn(r, c);
      }
      cout << g;
    }
    else if (cmd == "game") {
      try {
        cin >> moves;
      }
      catch (ios::failure &) {
        return 0;
      }
      cout << moves << " moves left" << endl;
    }
    else if (cmd == "switch") {
      int r = 0, c = 0;
      try {
        cin >> r >> c;
      }
      catch (ios::failure &) {
        return 0;
      }
      g.toggle(r, c);
      cout << g;
      moves--;
      cout << moves << " moves left" << endl;
      if (g.isWon()) {
      	cout << "Won" << endl;
      	break;
      }
      if (moves == 0) {
      	cout << "Lost" << endl;
      	break;
      }
    }
  }
}
