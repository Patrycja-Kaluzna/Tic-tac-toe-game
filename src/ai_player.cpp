#include "game.hh"
#include <limits>

// Funkcja pomocnicza dla funkcji realizujacej
// algorytm sztucznej inteligencji MinMax - 
// funkcja jest krokiem podstawowym 
// rekurencji i ocenia ruch
int evaluate (game* tictactoe) {
    if (tictactoe->is_horizontal(tictactoe->get_players()[0])) {
        return -10;
    } else if (tictactoe->is_horizontal(tictactoe->get_players()[1])) {
        return 10;
    } else if (tictactoe->is_vertical(tictactoe->get_players()[0])) {
        return -10;
    } else if (tictactoe->is_vertical(tictactoe->get_players()[1])) {
        return 10;
    } else if (tictactoe->is_diagonal(tictactoe->get_players()[0])) {
        return -10;
    } else if (tictactoe->is_diagonal(tictactoe->get_players()[1])) {
        return 10;
    } else if (tictactoe->is_inverse_diagonal(tictactoe->get_players()[0])) {
        return -10;
    } else if (tictactoe->is_inverse_diagonal(tictactoe->get_players()[1])) {
        return 10;
    }
    return 0;
}

// Funkcja realizująca algorytm 
// sztucznej inteligencji MinMax
int minimax (game* tictactoe, unsigned int depth, bool is_maximizing) {
    unsigned int size = tictactoe->get_actual_board()->get_size();
    int value = evaluate(tictactoe);
    int best_score, score;
    
    if (value == 10 || value == -10) {
        return value;
    } else if (tictactoe->is_tie()) {
        return 0;
    }
    if (is_maximizing) {
        best_score = numeric_limits<int>::min();
        for (unsigned int i = 0; i < size; i++) {
            for (unsigned int j = 0; j < size; j++) {
                if (tictactoe->is_correct_move(i, j)) {
                    tictactoe->get_actual_board()->set_square(i, j, tictactoe->get_players()[1]);
                    score = minimax(tictactoe, (depth + 1), false);
                    best_score = max(score, best_score);
                    tictactoe->get_actual_board()->set_square(i, j, ' ');
                }
            }
        }
        return best_score;
    } else {
        best_score = numeric_limits<int>::max();
        for (unsigned int i = 0; i < size; i++) {
            for (unsigned int j = 0; j < size; j++) {
                if (tictactoe->is_correct_move(i, j)) {
                    tictactoe->get_actual_board()->set_square(i, j, tictactoe->get_players()[0]);
                    score = minimax(tictactoe, (depth + 1), true);
                    best_score = min(score, best_score);
                    tictactoe->get_actual_board()->set_square(i, j, ' ');
                }
            }
        }   
        return best_score;
    }
}

// Funkcja wykorzystująca funkcję realizującą
// algorytm sztucznej inteligencji MinMax w 
// celu wyboru najlepszego ruchu. Funkcja 
// wykonuje wspomniany najlepszy ruch
void make_best_move (game* tictactoe) {
    unsigned int size = tictactoe->get_actual_board()->get_size();
    int best_score = numeric_limits<int>::min();
    pair<unsigned int, unsigned int> move;
    int score;

    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (tictactoe->is_correct_move(i, j)) {
                tictactoe->get_actual_board()->set_square(i, j, tictactoe->get_players()[1]);
                score = minimax(tictactoe, 0, false);
                tictactoe->get_actual_board()->set_square(i, j, ' ');
                if (score > best_score) {
                    best_score = score;
                    move.first = i;
                    move.second = j;
                }
            }
        }
    }
    tictactoe->get_actual_board()->set_square(move.first, move.second, tictactoe->get_players()[1]);
    tictactoe->get_actual_state()->set_whose_turn(tictactoe->get_players()[0]);
}