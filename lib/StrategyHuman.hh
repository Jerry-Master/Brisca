#pragma once
#include "Strategy.hh"

#define STRATEGY_NAME StrategyHuman
class STRATEGY_NAME: public Strategy{

    public:
        /* Constructors */
        using Strategy::Strategy;
        /**
        * Factory: returns a new instance of this class.
        */
        static Strategy* factory (const Deck& cards_, card card_);

        /* Play: returns the move in the next turn */
        card play(card card_ = card());

        /* Returns name */
        string name();
};

RegisterStrategy(STRATEGY_NAME);