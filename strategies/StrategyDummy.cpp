#include "StrategyDummy.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_, card muestra) {
    return new STRATEGY_NAME(cards_, muestra);
}

card STRATEGY_NAME::play(card card_) {
    int selection = rand() % cards.size();
    Deck new_deck;
    for (int i = 0; i < cards.size(); i++){
        if (i != selection){
            new_deck.push_back(cards[i]);
        }
    }
    card res = cards[selection];
    cards = new_deck;
    return res;
}

string STRATEGY_NAME::name(){
    return _stringify(STRATEGY_NAME);
}