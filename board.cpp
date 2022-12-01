#include "board.h"
#include <time.h>
#include <iterator>
#include <iostream>

using namespace std;

board::board(){
    card temp;
    for (int i = 0; i < 52; i++) {
        if (i > 0) {
            temp = {'D', i + 1};
            all[i] = temp;
        }
        else if (i > 13) {
            temp = {'C', i - 13 + 1};
            all[i] = temp;
        }
        else if (i > 26) {
            temp = {'H', i - 26 + 1};
            all[i] = temp;
        }
        else {
            temp = {'S', i - 39 + 1};
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
