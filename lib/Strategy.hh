#pragma once
#include "Registry.hh"

class Strategy{
    public:
        Deck cards;
        Strategy(const Deck& cards);
        /* 
            Play: returns the move in the next turn 
            It will be overwritten, thus virtual
        */
        virtual void play (){};
};