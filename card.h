#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

enum face {/*NULL = NULL, */A = 1, J = 11, Q, K};
enum suit {D,C,H,S};

class card{
public:
    card();
    card(int, char);
    void setCard(int, char);
    friend ostream& operator<<(ostream &out, const card &c);
// protected:
    char suit;
    int num;
};

#endif /* end of include guard: CARDS.H */
