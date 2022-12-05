// #include <curses.h>
#include <iostream>
#include "board.h"
#include "card.h"
#include "freecell.h"

using namespace std;

int main() {
    board b;
    b.shuffle();
    do {
        /* code */
    } while(user != QUIT);
    cout << b << endl;
    return 0;
}
