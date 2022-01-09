#ifndef STATE_HH
#define STATE_HH

// Klasa modelująca pojęcie stanu
// gry, którego cechami są zmienne
// przechowujące informacje o tym 
// czyja jest aktualna tura i ile
// znaków w jednej linii potrzeba 
// do wygranej
class state {

    // Aktaulna tura
    char whose_turn;

    // Liczba znaków w jednej linii
    // potrzebna do wygranej
    unsigned int to_win;

    public:

    // Tworzy stan gry
    state () {}

    // Tworzy stan gry z zadanym warunkiem wygranej
    // i ustawia czyja jest aktualna tura
    state (char new_turn, unsigned int new_rule):
        whose_turn(new_turn), to_win(new_rule) {}

    // Usuwa stan gry
    ~state () {}

    // Ustawia czyja jest aktualna tura
    void set_whose_turn (char new_turn) {
        whose_turn = new_turn;
    }

    // Zwraca czyja jest aktualna tura
    char get_whose_turn () {
        return whose_turn;
    }

    // Zwraca jaki jest warunek wygranej
    unsigned int get_to_win () {
        return to_win;
    }

};

#endif 