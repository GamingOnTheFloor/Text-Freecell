#include "board.h"
#include "card.h"
#include <time.h>
#include <iterator>
#include <iostream>

using namespace std;

board::board(){
    card temp;
    for (int i = 0; i < 52; i++) {
        if (i < 13) {
            temp.setCard(i + 1, 'D');
            all[i] = temp;
        }
        else if (i < 26) {
            temp.setCard(i - 13 + 1, 'C');
            all[i] = temp;
        }
        else if (i < 39) {
            temp.setCard(i - 26 + 1, 'H');
            all[i] = temp;
        }
        else {
            temp.setCard(i - 39 + 1, 'S');
            all[i] = temp;
        }
    }
    // for (size_t i = 0; i < 52; i++) {
    //     for (int j = 0; j < 13; j++) {
    //         card temp = {'D',j};
    //         all[i] = temp;
    //     }
    //     for (int j = 0; j < 13; j++) {
    //         card temp = {'C',j};
    //         all[i] = temp;
    //     }
    //     for (int j = 0; j < 13; j++) {
    //         card temp = {'H',j};
    //         all[i] = temp;
    //     }
    //     for (int j = 0; j < 13; j++) {
    //         card temp = {'S',j};
    //         all[i] = temp;
    //     }
    // }
}

void board::shuffle(){
    card temp;
    bool in;
    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            do {
                temp = all[rand() % 52];
                in = false;
                for (int k = 0; k < i; k++) {
                    for (int l = 0; l < j; l++) {
                        if(cascades[k][l].suit == temp.suit && cascades[k][l].num == temp.num){
                            in = true;
                        }
                    }
                }
            } while(in);
            cascades[i][j] = temp;
        }
    }
}

string board::moveCard(card c, int pos){
    return "Temp";
}

ostream& operator<<(ostream &out, const board &b){
    out << endl;
    out << "Cells | Cascades | Foundations" << endl;
    out << "------|----------|------------" << endl;
    out << "      |12345678|" << endl;
    out << "     " << b.cells[0] << "|";
    for (int i = 0; i < 8; i++) {
        out << b.cascades[0][i];
    }
    out << b.foundations[0] << "♦" << endl;
    out << "     " << b.cells[1] << "|";
    for (int i = 0; i < 8; i++) {
        out << b.cascades[1][i];
    }
    out << b.foundations[1] << "♣" << endl;
    out << "     " << b.cells[2] << "|";
    for (int i = 0; i < 8; i++) {
        out << b.cascades[2][i];
    }
    out << b.foundations[2] << "♥" << endl;
    out << "     " << b.cells[3] << "|";
    for (int i = 0; i < 8; i++) {
        out << b.cascades[3][i];
    }
    out << b.foundations[3] << "♠" << endl;
    out << "      |";
    for (int i = 0; i < 8; i++) {
        out << b.cascades[4][i];
    }
    out << "|" << endl;
    for (int j = 5; j < 19; j++) {
        out << "      |";
        for (int i = 0; i < 8; i++) {
            out << b.cascades[j][i];
        }
        out << "|" << endl;
    }
    return out;
}
