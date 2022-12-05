#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include "card.h"
#include "freecell.h"

using namespace std;


class board: Public freecell{
public:
    board();
    void shuffle();
    string moveCard(card, int);
    friend ostream& operator<<(ostream &, const board &);
// protected:
    card cascades[7+12][8]; //Maximum length of cards at the start is 7, but if the last is a King, then theoretically, you could get up to 12 more. 8 Collums in the Cascades.
    card cells[4];
    card foundations[4];
// private:
    card all[52]; //Diamonds 13 + Clubs 13 + Hearts 13 + Spades 13 = 52
};

#endif /* end of include guard: BOARD_H */
