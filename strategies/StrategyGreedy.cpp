#include "StrategyGreedy.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_, card muestra) {
    return new STRATEGY_NAME(cards_, muestra);
}
/*
  If you can win, win. Otherwise, throw a card with low value
  which is not muestra.
*/
card STRATEGY_NAME::play(card card_) {
    int selection = rand() % cards.size();
    int minValue = 24;
    for (int i = 0; i < cards.size(); i++){
        int points = POINTS[cards[i].value];
        if (cards[i].palo == muestra.palo){
            points += 12; // We don't want to throw muestra if we have other cards
        }
        if (points < minValue){
            minValue = points;
            selection = i;
        }
    }
    if (card_.palo.size() > 0){
        if (POINTS[card_.value] >= 10){ // Cortar
            int min = 12;
            for (int i = 0; i < cards.size(); i++){
                if (cards[i].palo == muestra.palo){
                    int points = POINTS[cards[i].value];
                    if (points < min){
                        min = points;
                        selection = i;
                    }
                }
            }
        } else {
            int max = -1;
            for (int i = 0; i < cards.size(); i++){ // Cargar
                int points = POINTS[cards[i].value];
                if (points > max and cards[i].palo == card_.palo 
                    and POINTS[cards[i].value] >= 10){
                    max = points;
                    selection = i;
                }                
            }
        }
    }
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