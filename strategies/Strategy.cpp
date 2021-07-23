#include "Strategy.hh"

Strategy::Strategy(const Deck& cards_){
    cards = cards_;
    for (int i = 0; i < 6; i++){
        _my_assert(cards[i].palo.size()>0, "Void palo.(strategy)");

    }
}