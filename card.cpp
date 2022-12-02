#include "card.h"


card::card(){
    suit = NULL;
    num = NULL;
}

card::card(int n, char s){
    if (n > 0 && n <= 13) {
        num = n;
    }
    else {
        num = NULL;
    }
    if (s == 'D' || s == 'C' || s == 'H' || s == 'S'){
        suit = s;
    } else {
        suit = NULL;
    }
}

void card::setCard(int n, char s){
    if (n > 0 && n <= 13 || n == NULL) {
        num = n;
    }
    if (s == 'D' || s == 'C' || s == 'H' || s == 'S' || s == NULL){
        suit = s;
    }
}

ostream& operator<<(ostream &out, const card &c){
    if (c.num == 13) {
        out << "K";
    } else if (c.num == 12) {
        out << "Q";
    } else if (c.num == 11) {
        out << "J";
    } else if (c.num == 10) {
        out << "0";
    } else {
        out << c.num;
    }
    if (c.suit == 'D') {
        out << "♦"; // \u2666
    } else if (c.suit == 'C') {
        out << "♣"; // \u2663
    } else if (c.suit == 'H'){
        out << "♥"; // \u2665
    } else {
        out << "♠"; // \u2660
    }
    return out;
}
