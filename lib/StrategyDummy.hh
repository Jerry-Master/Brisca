#pragma once
#include "Strategy.hh"

#define STRATEGY_NAME StrategyDummy
class STRATEGY_NAME: public Strategy{

    public:
        /* Constructors */
        using Strategy::Strategy;
        /**
        * Factory: returns a new instance of this class.
        */
        static Strategy* factory (const Deck& cards_);

        /* Play: returns the move in the next turn */
        void play();
};

RegisterStrategy(STRATEGY_NAME);