#pragma once
#include "Structs.hh"

class Dealer{
    private:
        Deck deck;
        card muestra;
    public:
        Dealer(int seed);
        Deck starter_cards();
        card give_card();
        int remaining_cards();
        card show_muestra();
};