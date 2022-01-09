#include "game.hh"

int main () {
    unsigned int size, to_win; // Rozmiar planszy i warunek wygranej
    char option = 'P'; // Opcja (P - rozpoczęcie gry, Q - koniec działania programu)

    do {
        // Jeśli wybrano opcję oznaczającą rozpoczęcie gry
        if (option == 'P') {
            // Wczytanie rozmiaru planszy ze standardowego wejścia
            cout << "Enter a size of a board: ";
            cin >> size;
            // Wczytanie warunku wygranej ze standardowego wejścia
            cout << "Enter a number of characters needed to win: ";
            cin >> to_win;
            // Tworzy grę z planszą o wczytanym rozmiarze i wczytanym warunkiem wygranej
            game tictactoe(size, to_win);
            // Rozpoczyna i przeprowadza grę 
            tictactoe.start();
            // Wczytanie opcji
            cout << "Do you want to play again? (Enter P)" << endl;
            cout << "Or do you want do quit the game? (Enter Q)" << endl;
            cin >> option;
        } else { // Jeśli wybrano błędną opcję
            cout << "Wrong option! Enter it again: ";
            cin >> option;
        }
    } while (option != 'Q'); // Dopóki nie wybrano opcji kończoncej działanie programu
}