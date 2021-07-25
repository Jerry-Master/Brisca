#pragma once
#include "Strategy.hh"

#define STRATEGY_NAME StrategyGordas
class STRATEGY_NAME: public Strategy{
    private:
        set<string> used3, used1;
        int num_muestra;

    public:
        /* Constructors */
        using Strategy::Strategy;
        /**
        * Factory: returns a new instance of this class.
        */
        static Strategy* factory (const Deck& cards_, card card_);

        /* Play: returns the move in the next turn */
        card play(card card_ = card());
        void update (card first = card(), card second = card());

        /* Returns name */
        string name();
};

RegisterStrategy(STRATEGY_NAME);