// #include <curses.h>
#include <iostream>
#include "board.h"
#include "card.h"

using namespace std;

int main() {
    board b;
    string user;
    b.shuffle();
    do {
        cout << b << endl;
        user = b.menu();
        cout << user << endl;
    } while(user != "QUIT" && !b.won());
    cout << b << endl;
    cout << "You won! Good Job!" << endl;
    return 0;
}
