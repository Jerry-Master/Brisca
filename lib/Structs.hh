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
static const vector<int> POINTS = {-1,11,0,10,0,0,0,0,0,0,2,3,4};

inline void print_card(card C, ostream& os=cout){
    os << C.value << " de " << C.palo << endl;
}

inline void show_deck(const Deck& deck, ostream& os=cout){
    os << "Showing full deck: " << endl;
    string tab(4, ' ');
    for (int i = 0; i < deck.size(); i++){
        os << tab;
        print_card(deck[i], os);
    }
}

inline void print_card_json(card C, ostream& os=cout){
    json j;
    j["palo"] = C.palo;
    j["value"] = C.value;
    os << j;
}

inline void print_deck_json(const Deck& deck, ostream& os=cout){
    json j;
    for (int i = 0; i < deck.size(); i++){
        j[int_to_string(i)] = {{"palo", deck[i].palo}, {"value", deck[i].value}};
    }
    os << j;
}

// Returns 0 if the first player wins and 1 otherwise 
// In case of tie, first player wins
inline bool winner(card card1, card card2, card muestra){
    int value1 = POINTS[card1.value];
    int value2 = POINTS[card2.value];

    int is_muestra1 = (card1.palo == muestra.palo);
    int is_muestra2 = (card2.palo == muestra.palo);

    if (is_muestra1 and not is_muestra2)
        return 0;
    if (not is_muestra1 and is_muestra2)
        return 1;
    if (is_muestra1 and is_muestra1){
        if (value1 == 0 and value2 == 0)
            return card1.value < card2.value;
        return value1 < value2;
    }
    else if (card1.palo == card2.palo){
        if (value1 == 0 and value2 == 0)
            return card1.value < card2.value;
        return value1 < value2;
    }
    else
        return 0;
        
}

#endif
