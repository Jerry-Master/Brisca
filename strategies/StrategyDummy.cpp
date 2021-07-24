#include "StrategyDummy.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_) {
    return new STRATEGY_NAME(cards_);
}

void STRATEGY_NAME::play() {
    cout << _stringify(STRATEGY_NAME) << endl;
}