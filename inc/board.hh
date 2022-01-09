#ifndef BOARD_HH
#define BOARD_HH

#include <iostream>

using namespace std;

// Klasa modelująca pojęcie kwadratowej
// planszy, którą cechują 2-wymiarowa 
// tablica reprezaentująca planszę 
// i zmienna przechowująca jej 
// rozmiar
class board {

    // Reprezentacja planszy
    char** board_tab;
    
    // Rozmiar planszy
    unsigned int size;

    public:

    // Tworzy planszę
    board () {}

    // Tworzy planszę o zadanym rozmiarze
    board (unsigned int new_size);

    // Usuwa planszę 
    ~board ();

    // Wstawia zadany znak w polu planszy 
    // o zadanych współrzędnych
    void set_square (unsigned int x, unsigned int y, char character);

    // Usuwa znak z pola planszy
    // o zadanych współrzędnych
    void reset_square (unsigned int x, unsigned int y);

    // Zwraca rozmiar planszy
    unsigned int get_size () const {
        return size;
    }

    // Wyświetla planszę na standardowym wyjściu
    void display () const;

    // Zwraca znak znajdujący się w polu planszy 
    // o zadanych współrzędnych
    char operator () (unsigned int x, unsigned int y) const;

};

#endif