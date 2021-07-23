#ifndef Structs_hh
#define Structs_hh
#include "Utils.hh"

/** \file
 * Contains structs representing cards and deck
 * Together with some functions
 */

struct card{
    string palo;
    int value;

    card(string palo, int value) : palo(palo), value(value) {}
    card() {}
};

#define Deck vector<card>
static const vector<string> PALOS = {"bastos", "espadas", "oros", "copas"};

inline void print_card(card C){
    _my_assert(C.palo.size()>0, "Void palo.");
    cout << C.value << " de " << C.palo << endl;
}

inline void show_deck(const Deck& deck){
    cout << "Showing full deck: " << endl;
    string tab(4, ' ');
    for (int i = 0; i < deck.size(); i++){
        cout << tab;
        print_card(deck[i]);
    }
}

#endif
