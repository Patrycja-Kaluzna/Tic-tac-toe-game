#ifndef GAME_HH
#define GAME_HH

#include "board.hh"
#include "state.hh"

// Klasa modelująca pojęcie gry,
// którą cechują jej gracze,
// plansza i stan
class game {

    // Gracze
    char players[2] = {'X', 'O'};

    // Plansza
    board* actual_board;

    // Stan gry
    state* actual_state;

    public:

    // Tworzy grę z planszą o zadanym rozmiarze i 
    // zadanym warunkiem wygranej oraz ustawia
    // aktualną turę, na turę gracza X
    game (unsigned int new_size, unsigned int new_rule) {
        actual_board = new board(new_size);
        actual_state = new state(players[0], new_rule);
    }

    // Usuwa grę
    ~game () {}

    // Zwraca graczy 
    char* get_players () {
        return players;
    }

    // Zwraca planszę
    board* get_actual_board () {
        return actual_board;
    }

    // Zwraca stan gry
    state* get_actual_state () {
        return actual_state;
    }

    // Sprawdza czy pole planszy o zadanych 
    // współrzędnych jest puste
    bool is_correct_move (unsigned int x, unsigned int y);

    // Sprawdza czy jest remis
    bool is_tie () const;

    // Sprawdza czy zadany gracz wygral 
    // w poziomie
    bool is_horizontal (char player);

    // Sprawdza czy zadany gracz wygral
    // w pionie
    bool is_vertical (char player);

    // Sprawdza czy zadany gracz wygral
    // po skosie z góry na dół
    bool is_diagonal (char player);

    // Sprawdze czy zadany gracz wygrał
    // po skosie z dołu do góry
    bool is_inverse_diagonal (char player);

    // Sprawdza czy jest koniec gry - 
    // czy jest remis lub ktoś wygrał i
    // "zwraca" zwycięzce przez argument
    bool is_end (char* winner);

    // Rozpoczyna i przeprowadza grę
    void start ();

};

#endif