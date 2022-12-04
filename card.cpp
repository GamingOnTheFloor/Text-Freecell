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
    switch (static_cast<face>(c.num)) {
        case K: out << "K"; break;
        case Q: out << "Q"; break;
        case J: out << "J"; break;
        case 10: out << "0"; break;
        case A: out << "A"; break;
        case NULL: out << "\u0020"; break;
        default: out << c.num;
    }
    
    // if (c.num == 13) {
    //     out << "K";
    // } else if (c.num == 12) {
    //     out << "Q";
    // } else if (c.num == 11) {
    //     out << "J";
    // } else if (c.num == 10) {
    //     out << "0";
    // } else if (c.num == NULL) {
    //     out << "\u0020"; // \U0001F0BF \u0020
    // } else {
    //     out << c.num;
    // }

    // switch (static_cast<suit>(c.suit)) {
    //     case D: out << "♦"; break; // \u2666
    //     case C: out << "♣"; break; // \u2663
    //     case H: out << "♥"; break; // \u2665
    //     case S: out << "♠"; break; // \u2660
    //     default: out << "\u0020"; break; // 🂿 \U0001F0BF \u0020
    // }

    if (c.suit == 'D') {
        out << "♦"; // \u2666
    } else if (c.suit == 'C') {
        out << "♣"; // \u2663
    } else if (c.suit == 'H'){
        out << "♥"; // \u2665
    } else if (c.suit == 'S'){
        out << "♠"; // \u2660
    } else {
        out << "\u0020"; // 🂿 \U0001F0BF \u0020
    }
    return out;
}
