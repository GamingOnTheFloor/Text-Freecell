#include "board.h"
#include "card.h"
#include <time.h>
#include <iterator>
#include <iostream>
#include <iomanip>

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
    empty.setCard(NULL, NULL);
    foundations[0].setCard(NULL, 'D');
    foundations[1].setCard(NULL, 'C');
    foundations[2].setCard(NULL, 'H');
    foundations[3].setCard(NULL, 'S');
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
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 6 && j >= 4) {
                cascades[i][j] = empty;
            } else {
                do {
                    temp = all[rand() % 52];
                    in = false;
                    for (int k = 0; k <= i; k++) {
                        for (int l = 0; l < 8; l++) {
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
    for (int i = 7; i < 7+12; i++) {
        for (int j = 0; j < 8; j++) {
            cascades[i][j] = empty;
        }
    }
}

string board::moveCard(card c, int pos){
    for (int i = 0; i < 7+12; i++) {
        for (int j = 0; j < 8; j++) {
            if (cascades[i][j].num == c.num && cascades[i][j].suit == c.suit) {
                // cout << "DEBUG A: " << cascades[i][j] << endl;
                if (cascades[i+1][j].num != NULL && cascades[i+1][j].suit != NULL) {
                    // cout << "DEBUG B: " << cascades[i][j+1] << endl;
                    return "ERROR";
                }
            }
        }
    }



    for (int i = 18; i >= 0; i--) {
        // cout << "DEBUG 0" << endl;
        if (cascades[i][pos - 1].num != NULL && cascades[i][pos - 1].suit != NULL) {
            // cout << "DEBUG 1" << endl;
            if (c.suit == 'D' || c.suit == 'H') {
                // cout << "DEBUG 2" << endl;
                if (cascades[i][pos - 1].num - 1 == c.num && (cascades[i][pos - 1].suit == 'S' || cascades[i][pos - 1].suit == 'C')) {
                    // cout << "DEBUG 3" << endl;

                    for (int j = 0; j < 4; j++) {
                        // cout << "DEBUG 4" << endl;
                        if (cells[j].num == c.num && cells[j].suit == c.suit){
                            // cout << "DEBUG 5" << endl;
                            cells[j] = empty;
                            // return "Done";
                        }
                    }
                    for (int j = 0; j < 7+12; j++) {
                        // cout << "DEBUG 6" << endl;
                        for (int k = 0; k < 8; k++) {
                            // cout << "DEBUG 7" << endl;
                            if (cascades[j][k].num == c.num && cascades[j][k].suit == c.suit){
                                // cout << "DEBUG 8" << endl;
                                cascades[j][k] = empty;
                                // return "Done";
                            }
                        }
                    }
                    // cout << "DEBUG 8.5" << endl;
                    cascades[i+1][pos - 1] = c;
                    return "Done";
                }
            }
            if (c.suit == 'S' || c.suit == 'C') {
                // cout << "DEBUG 9" << endl;
                if (cascades[i][pos - 1].num - 1 == c.num && (cascades[i][pos - 1].suit == 'D' || cascades[i][pos - 1].suit == 'H')) {
                    // cout << "DEBUG 10" << endl;

                    for (int j = 0; j < 4; j++) {
                        // cout << "DEBUG 11" << endl;
                        if (cells[j].num == c.num && cells[j].suit == c.suit){
                            // cout << "DEBUG 12" << endl;
                            cells[j] = empty;
                            // return "Done";
                        }
                    }
                    for (int j = 0; j < 7+12; j++) {
                        // cout << "DEBUG 13" << endl;
                        for (int k = 0; k < 8; k++) {
                            // cout << "DEBUG 14" << endl;
                            if (cascades[j][k].num == c.num && cascades[j][k].suit == c.suit){
                                // cout << "DEBUG 15" << endl;
                                cascades[j][k] = empty;
                                // return "Done";
                            }
                        }
                    }
                    // cout << "DEBUG 15.5" << endl;
                    cascades[i+1][pos - 1] = c;
                    return "Done";
                }
            }
        }
        if (i == 0) {
            if (cascades[0][pos - 1].num != NULL && cascades[0][pos - 1].suit != NULL) {
                return "ERROR";
            }
            for (int j = 0; j < 4; j++) {
                // cout << "DEBUG 16" << endl;
                if (cells[j].num == c.num && cells[j].suit == c.suit){
                    // cout << "DEBUG 17" << endl;
                    cells[j] = empty;
                    // return "Done";
                }
            }
            for (int j = 0; j < 7+12; j++) {
                // cout << "DEBUG 18" << endl;
                for (int k = 0; k < 8; k++) {
                    // cout << "DEBUG 19" << endl;
                    if (cascades[j][k].num == c.num && cascades[j][k].suit == c.suit){
                        // cout << "DEBUG 20" << endl;
                        cascades[j][k] = empty;
                        // return "Done";
                    }
                }
            }
            cascades[0][pos - 1] = c;
            return "Done";
        }
    }
    return "ERROR";
}

string board::moveCard(card c, char pos){
    string freecellRule;
    for (int i = 0; i < 4; i++) {
        if (cells[i].num == c.num && cells[i].suit == c.suit){
            freecellRule = "True";
        }
    }

    for (int i = 0; i < 7+12; i++) {
        for (int j = 0; j < 8; j++) {
            if ((cascades[i][j].num == c.num && cascades[i+1][j].num == empty.num) && (cascades[i][j].suit == c.suit && cascades[i+1][j].suit == empty.suit)){
                freecellRule = "True";
                }
            }
        }

    if (freecellRule == "True" && (pos == 'c' || pos == 'C')) {
        for (int i = 0; i < 4; i++) {
            if (cells[i].num == empty.num && cells[i].suit == empty.suit) {
                for (int i = 0; i < 4; i++) {
                    if (cells[i].num == c.num && cells[i].suit == c.suit){
                        cells[i] = empty;
                    }
                }
                cells[i] = c;
                for (int i = 0; i < 7+12; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (cascades[i][j].num == c.num && cascades[i][j].suit == c.suit){
                            cascades[i][j] = empty;
                            }
                        }
                    }
                break;
            }
        }
    }

    if (freecellRule == "True" && (pos == 'f' || pos == 'F')) {
        for (int i = 0; i < 4; i++) {
            if (foundations[i].suit == c.suit && (foundations[i].num + 1 == c.num || (foundations[i].num == NULL && c.num == 1))){
                foundations[i] = c;
                for (int i = 0; i < 7+12; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (cascades[i][j].num == c.num && cascades[i][j].suit == c.suit){
                            cascades[i][j] = empty;
                        }
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (cells[i].num == c.num && cells[i].suit == c.suit){
                        cells[i] = empty;
                    }
                }
            }
        }
    }

    return "Done";
}

string board::menu(){
    string num;
    string place;
    string temp;
    card tempCard;
    char tempChar;
    // cout << "Type the card plus where you want the card to go (ex. 10S 8): ";
    cout << "Type the card you want to move: ";
    cin >> num;
    if (num == "q" || num == "Q" || num == "Quit" || num == "quit") {
        return "QUIT";
    }

    tempChar = num[1];
    if (num[0] == 'K') {
        num = "13";
        num = num.append(1, tempChar);
        // cout << "Debug 1: " << num << endl;
    } else if (num[0] == 'Q') {
        num = "12";
        num = num.append(1, tempChar);
        // cout << "Debug 1: " << num << endl;
    } else if (num[0] == 'J') {
        num = "11";
        num = num.append(1, tempChar);
        // cout << "Debug 1: " << num << endl;
    } else if (num[0] == 'A') {
        num = "1";
        num = num.append(1, tempChar);
        // cout << "Debug 1: " << num << endl;
    } else {
        num = num;
    }

    // cout << num << endl;
    for (int i = 0; i < 52; i++) {
        temp = to_string(all[i].num).append(1, all[i].suit);
        // cout << temp << endl;
        if (num == temp) {
            tempCard = all[i];
            break;
        }
    }
    if (num != temp) {
        return "ERROR";
    }
    cout << "Type the place you want to move the card to: ";
    cin >> place;
    if (place == "C" || place == "F" || place == "c" || place == "f") {
        return moveCard(tempCard, place[0]);
    } else if (stoi(place) > 0 && stoi(place) < 9){
        return moveCard(tempCard, place[0] - '0');
    } else {
        return "ERROR";
    }
    return "DONE";
}

bool board::won(){
    if (foundations[0].num == 13 && foundations[1].num == 13 && foundations[2].num == 13 && foundations[3].num == 13) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream &out, const board &b){
    out << endl;
    out << right << setw(5)  << "Cells " << "|";
    out << right << setw(32) << "Cascades            " << "|";
    out << left  << setw(12) << " Foundations" << "\n";
    out << right << setw(5)  << "------" << "|";
    out << right << setw(16) << "--------------------------------" << "|";
    out << left  << setw(12) << "------------" << "\n";
    out << right << setw(7)  << "|";
    out << right << setw(16) << " 1   2   3   4   5   6   7   8  " << "|" << "\n";
    // out << "Cells | Cascades | Foundations" << endl;
    // out << "------|----------|------------" << endl;
    // out << "      | 12345678 |" << endl;

    // This part of this function could be condensed into another for loop probably. 

    if (b.cells[0].num == 10) {
        out << b.cells[0] << right << setw(4) << "|";
    } else if (b.cells[0].num != b.empty.num && b.cells[0].suit != b.empty.suit) {
        out << b.cells[0] << right << setw(5) << "|";
    } else {
        out << right << setw(4) << b.cells[0] << "|";
    }
    for (int i = 0; i < 8; i++) {
        out << " " << b.cascades[0][i] << " ";
    }
    out << "|" << b.foundations[0] << endl;
    if (b.cells[1].num == 10) {
        out << b.cells[1] << right << setw(4) << "|";
    } else if (b.cells[1].num != b.empty.num && b.cells[1].suit != b.empty.suit) {
        out << b.cells[1] << right << setw(5) << "|";
    } else {
        out << right << setw(4) << b.cells[1] << "|";
    }
    for (int i = 0; i < 8; i++) {
        out << " " << b.cascades[1][i] << " ";
    }
    out << "|" << b.foundations[1] << endl;
    if (b.cells[2].num == 10) {
        out << b.cells[2] << right << setw(4) << "|";
    } else if (b.cells[2].num != b.empty.num && b.cells[2].suit != b.empty.suit) {
        out << b.cells[2] << right << setw(5) << "|";
    } else {
        out << right << setw(4) << b.cells[2] << "|";
    }
    for (int i = 0; i < 8; i++) {
        out << " " << b.cascades[2][i] << " ";
    }
    out << "|" << b.foundations[2] << endl;
    if (b.cells[3].num == 10) {
        out << b.cells[3] << right << setw(4) << "|";
    } else if (b.cells[3].num != b.empty.num && b.cells[3].suit != b.empty.suit) {
        out << b.cells[3] << right << setw(5) << "|";
    } else {
        out << right << setw(4) << b.cells[3] << "|";
    }
    for (int i = 0; i < 8; i++) {
        out << " " << b.cascades[3][i] << " ";
    }
    out << "|" << b.foundations[3] << endl;
    // out << "      |";
    // for (int i = 0; i < 8; i++) {
    //     out << " " << b.cascades[4][i];
    // }
    // out << "|" << endl;
    for (int j = 4; j < 19; j++) {
        out << "      |";
        for (int i = 0; i < 8; i++) {
            out << " " << b.cascades[j][i] << " ";
        }
        out << "|" << endl;
    }
    return out;
}
