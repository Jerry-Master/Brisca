#include "Strategy.hh"

Strategy::Strategy(const Deck& cards_, card muestra_){
    cards = cards_;
    muestra = muestra_;
    _my_assert(cards.size()==3, "Three cards to start with.");
    for (int i = 0; i < 3; i++){
        _my_assert(cards[i].palo.size()>0, "Void palo.(strategy)");
    }
}

void Strategy::show(ostream& os) {
    show_deck(cards, os);
}
void Strategy::show_pile(ostream& os) {
    show_deck(pile, os);
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
        points += POINTS[c.value];
    }
    return points;
}

void Strategy::add_to_pile(card c1, card c2){
    pile.push_back(c1);
    pile.push_back(c2);
}
void Strategy::take_card(card c){
    cards.push_back(c);
}