#include "Strategy.hh"

Strategy::Strategy(const Deck& cards_, card muestra_){
    cards = cards_;
    muestra = muestra_;
    _my_assert(cards.size()==3, "Three cards to start with.");
    for (int i = 0; i < 3; i++){
        _my_assert(cards[i].palo.size()>0, "Void palo.(strategy)");
    }
}

void Strategy::show() {
    show_deck(cards);
}

/*
  Remember (value->points):
    1->11 // 3->10
    10->2 // 11->3 // 12->4
*/
int Strategy::count() {
    int points = 0;
    for (card c : pile){
        _my_assert(c.value <= 12, "Too high of a value.");
        _my_assert(c.value >= 1, "Too low of a value.");
        points += POINTS[c.value-1];
    }
    return points;
}