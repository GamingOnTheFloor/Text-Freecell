#include <curses.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    initscr();
    // cbreak();
    noecho();
    mvaddstr(15,15,"Maybe this will work?");
    // cout << "Maybe this will work?" << endl;
    getch();
    refresh();
    // usleep(40000);
    return 0;
}
