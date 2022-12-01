// #include <curses.h>
#include <iostream>
#include "board.h"

using namespace std;

int main() {
    board b;
    cout << "all cards" << endl;
    for (size_t i = 0; i < 52; i++) {
        cout << i << ": " << b.all[i].suit << b.all[i].num << endl;
    }
    b.shuffle();
    cout << "cascades" << endl;
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            cout << i << " " << j << ": " << b.cascades[i][j].suit << b.cascades[i][j].num << endl;
        }
    }
    return 0;
}
