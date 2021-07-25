#include "StrategyGreedyMax.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_, card muestra) {
    return new STRATEGY_NAME(cards_, muestra);
}
/*
  If you can win, win. Otherwise, throw a card with high value
  which is not muestra.
*/
card STRATEGY_NAME::play(card card_) {
    int selection = rand() % cards.size();
    int maxValue = -1;
    for (int i = 0; i < cards.size(); i++){
        int points = POINTS[cards[i].value];
        if (cards[i].palo == muestra.palo){
            points -= 4; // We don't want to throw muestra if we have other cards
        }
        if (points > maxValue){
            maxValue = points;
            selection = i;
        }
    }
    if (card_.palo.size() > 0){
        if (POINTS[card_.value] >= 10 and card_.palo != muestra.palo){ // Cortar con la más chica o el 1
            int min = 12;
            for (int i = 0; i < cards.size(); i++){
                int points = POINTS[cards[i].value];
                if (cards[i].palo == muestra.palo){
                    if (points < min){
                        min = points;
                        selection = i;
                    }
                } else if (cards[i].palo == card_.palo and points == 11){
                    selection = i;
                    min = -1;
                }
            }
        } else if (card_.palo != muestra.palo){ // Si es muestra echamos mierda
            int max = 0;
            for (int i = 0; i < cards.size(); i++){ // Cargar
                int points = POINTS[cards[i].value];
                if (points > max and cards[i].palo == card_.palo){
                    max = points;
                    selection = i;
                }                
            }
        } else if (POINTS[card_.value] == 10) {
            for (int i = 0; i < cards.size(); i++){ // Rematar el 3 de la muestra con el 1
                if (POINTS[cards[i].value] == 11 
                    and cards[i].palo == muestra.palo){
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
    _my_assert(selection < cards.size(), "Wrong card selection.");
    card res = cards[selection];
    cards = new_deck;
    return res;
}

string STRATEGY_NAME::name(){
    return _stringify(STRATEGY_NAME);
}