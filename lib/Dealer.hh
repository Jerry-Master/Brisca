#pragma once
#include "Structs.hh"

class Dealer{
    public:
        Deck deck;
        card muestra;
        Dealer(int seed);
        Deck starter_cards();
        card give_card();
        int remaining_cards();
};