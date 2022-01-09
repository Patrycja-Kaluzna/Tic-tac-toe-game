#include "board.hh"

// Tworzy planszę o zadanym rozmiarze
board::board (unsigned int new_size) {
    board_tab = new char* [new_size];

    for (unsigned int i = 0; i < new_size; i++) {
        board_tab[i] = new char [new_size];
    }
    for (unsigned int i = 0; i < new_size; i++) {
        for (unsigned int j = 0; j < new_size; j++) {
            board_tab[i][j] = ' ';
        }
    }
    size = new_size;
}

// Usuwa planszę 
board::~board() {
    for (unsigned int i = 0; i < size; i++) {
        delete [] board_tab[i];
    }
    delete [] board_tab;
}

// Wstawia zadany znak w polu planszy 
// o zadanych współrzędnych
void board::set_square (unsigned int x, unsigned int y, char character) {
    board_tab[x][y] = character;
}

// Usuwa znak z pola planszy
// o zadanych współrzędnych
void board::reset_square (unsigned int x, unsigned int y) {
    board_tab[x][y] = ' ';
}

// Wyświetla planszę na standardowym wyjściu
void board::display () const {
    for (unsigned int i = 0; i < size; i++) {
        if (i != (size - 1)) {
            cout << " " << i;
        } else {
            cout << " " << i << endl;
        }
    }
    for (unsigned int i = 0; i < size; i++) {
        cout << i;
        for (unsigned int j = 0; j < size; j++) {
            if (j != (size - 1)) {
                cout << board_tab[j][i] << "|";
            } else {
                cout << board_tab[j][i] << endl;
            }    
        }
    }
}

// Zwraca znak znajdujący się w polu planszy 
// o zadanych współrzędnych
char board::operator () (unsigned int x, unsigned int y) const {
    return board_tab[x][y];
}