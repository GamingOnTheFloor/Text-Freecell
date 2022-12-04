// #include <curses.h>
#include <iostream>
#include "board.h"

using namespace std;

int main() {
    board b;
    b.shuffle();
    cout << b << endl;
    return 0;
}
