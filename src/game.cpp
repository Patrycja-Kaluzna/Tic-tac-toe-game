#include "ai_player.cpp"
#include "game.hh"

// Sprawdza czy pole planszy o zadanych 
// współrzędnych jest puste
bool game::is_correct_move (unsigned int x, unsigned int y) {
    if ((*actual_board)(x, y) == ' ') {
        return true;
    } else {
        return false;
    }
}

// Sprawdza czy jest remis
bool game::is_tie () const {
    int size = actual_board->get_size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((*actual_board)(i, j) == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Sprawdza czy zadany gracz wygral 
// w poziomie
bool game::is_horizontal (char player) {
    unsigned int to_win = actual_state->get_to_win();
    unsigned int size = actual_board->get_size();
    unsigned int occurred = 0;

    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < (size - to_win + 1); j++) {
            if ((*actual_board)(j, i) == player) {
                occurred++;
                for (unsigned int k = (j + 1); k < (j + to_win); k++) {
                    if ((*actual_board)(k, i) == player) {
                        occurred++;
                    }
                }
                if (occurred == to_win) {
                    return true;
                } else {
                    occurred = 0;
                }
            }
        }
    }
    return false;
}

// Sprawdza czy zadany gracz wygral
// w pionie
bool game::is_vertical (char player) {
    unsigned int to_win = actual_state->get_to_win();
    unsigned int size = actual_board->get_size();
    unsigned int occurred = 0;

    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < (size - to_win + 1); j++) {
            if ((*actual_board)(i, j) == player) {
                occurred++;
                for (unsigned int k = (j + 1); k < (j + to_win); k++) {
                    if ((*actual_board)(i, k) == player) {
                        occurred++;
                    }
                }
                if (occurred == to_win) {
                    return true;
                } else {
                    occurred = 0;
                }
            }
        }
    }
    return false;
}

// Sprawdza czy zadany gracz wygral
// po skosie z góry na dół
bool game::is_diagonal (char player) {
    unsigned int to_win = actual_state->get_to_win();
    unsigned int size = actual_board->get_size();
    unsigned int occurred = 0;

    for (unsigned int i = 0; i < (size - to_win + 1); i++) {
        for (unsigned int j = 0; j < (size - to_win + 1); j++) {
            if ((*actual_board)(i, j) == player) {
                occurred++;
                for (unsigned int k = 1; k < to_win; k++) {
                    if ((*actual_board)((i + k), (j + k)) == player) {
                        occurred++;
                    }
                }
                if (occurred == to_win) {
                    return true;
                } else {
                    occurred = 0;
                }
            }
        }
    }
    return false;
}

// Sprawdze czy zadany gracz wygrał
// po skosie z dołu do góry
bool game::is_inverse_diagonal (char player) {
    unsigned int to_win = actual_state->get_to_win();
    unsigned int size = actual_board->get_size();
    unsigned int occurred = 0;

    for (unsigned int i = 0; i < (size - to_win + 1); i++) {
        for (unsigned int j = (size - 1); j > (to_win - 2); j--) {
            if ((*actual_board)(i, j) == player) {
                occurred++;
                for (unsigned int k = 1; k < to_win; k++) {
                    if ((*actual_board)((i + k), (j - k)) == player) {
                        occurred++;
                    }
                }
                if (occurred == to_win) {
                    return true;
                } else {
                    occurred = 0;
                }
            }
        }
    }
    return false;
}

// Sprawdza czy jest koniec gry - 
// czy jest remis lub ktoś wygrał i 
// "zwraca" zwycięzcę przez argument
bool game::is_end (char* winner) {
    if (is_horizontal('X')) {
        *winner = 'X';
        return true;
    } else if (is_horizontal('O')) {
        *winner = 'O';
        return true;
    }
    if (is_vertical('X')) {
        *winner = 'X';
        return true;
    } else if (is_vertical('O')) {
        *winner = 'O';
        return true;
    }
    if (is_diagonal('X')) {
        *winner = 'X';
        return true;
    } else if (is_diagonal('O')) {
        *winner = 'O';
        return true;
    }
    if (is_inverse_diagonal('X')) {
        *winner = 'X';
        return true;
    } else if (is_inverse_diagonal('O')) {
        *winner = 'O';
        return true;
    }
    if (is_tie()) {
        //delete winner; //
        winner = nullptr; 
        return true; 
    }
    return false;
}

// Rozpoczyna i przeprowadza grę
void game::start () {
    char* winner = new char;
    unsigned int x, y;

    actual_board->display();
    do {
        if (actual_state->get_whose_turn() == players[0]) {
            do {
                cout << "Enter coordinates (x, y): ";
                cin >> x >> y;
                if (!is_correct_move(x, y)) {
                    cout << "This square isn't empty." << endl;
                }
            } while (!is_correct_move(x, y));
            actual_board->set_square(x, y, players[0]);
            actual_state->set_whose_turn(players[1]);
            actual_board->display();
        } else if (actual_state->get_whose_turn() == players[1]) {
            make_best_move(this);
            actual_board->display();     
        }
    } while (!is_end(winner));
    if (*winner == 'X' || *winner == 'O') {
        cout << "The winner is " << *winner << "." << endl;
    } else {
        cout << "It is a tie." << endl;
    }
}