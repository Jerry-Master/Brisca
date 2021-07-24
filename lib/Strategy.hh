#pragma once
#include "Registry.hh"

class Strategy{
    private:
        Deck cards, pile;
        card muestra;
    public:
        Strategy(const Deck& cards_, card muestra_);
        /* 
            Play: returns the move in the next turn 
            It will be overwritten, thus virtual
        */
        virtual void play (){};

        /* Shows the cards in console */
        void show();

        /* Counts the point currently in the pile */
        int count();
};