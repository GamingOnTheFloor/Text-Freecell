// #include <curses.h>
#include <iostream>
#include "board.h"

using namespace std;

int main() {
    board b;
    cout << "all cards" << endl;
    for (size_t i = 0; i < 52; i++) {
        cout << i+1 << ": " << b.all[i] << endl;
    }
    b.shuffle();
    cout << "cascades" << endl;
    // for (size_t i = 0; i < 8; i++) {
    //     for (size_t j = 0; j < 8; j++) {
    //         cout << i+1 << " " << j+1 << ": " << b.cascades[i][j].suit << b.cascades[i][j].num << endl;
    //     }
    // }
    // cout << b << endl;
    return 0;
}
