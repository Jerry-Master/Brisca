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
static const vector<int> POINTS = {11,0,10,0,0,0,0,0,0,2,3,4};

inline void print_card(card C){
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

// Returns 0 if the first player wins and 1 otherwise 
// In case of tie, first player wins
inline bool winner(card card1, card card2, card muestra){
    int value1 = POINTS[card1.value-1];
    int value2 = POINTS[card2.value-1];

    int is_muestra1 = (card1.palo == muestra.palo);
    int is_muestra2 = (card2.palo == muestra.palo);

    if (is_muestra1 and not is_muestra2){
        return 0;
    }
    if (not is_muestra1 and is_muestra2){
        return 1;
    }
    return value1 < value2;
}

#endif
