#include "StrategyGordas.hh"

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
            points += 4; // We don't want to throw muestra if we have other cards
        }
        if (used3.count(cards[i].palo) and used1.count(cards[i].palo)){
            points -= 24*3; // If 1 and 3 have been used, there is no risk
        } else if (used1.count(cards[i].palo) and points < 10){
            points -= 24*2; // If 1 has been used, there is less risk
        } else if (used3.count(cards[i].palo) and points < 10){
            points -= 24; // If 3 has been used, there is less risk
        }
        if (points < minValue){
            minValue = points;
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
    } else if (num_muestra == 10){
        int max = 0;
        for (int i = 0; i < cards.size(); i++){ // Tirar la más gorda si no queda muestra
            int points = POINTS[cards[i].value];
            if (points > max){
                max = points;
                selection = i;
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

void STRATEGY_NAME::update (card first, card second){
    if (POINTS[first.value] == 10)
        used3.insert(first.palo);
    if (POINTS[second.value] == 10)
        used3.insert(second.palo);
    if (POINTS[first.value] == 11)
        used1.insert(first.palo);
    if (POINTS[second.value] == 11)
        used1.insert(second.palo);
    if (first.palo == muestra.palo)
        num_muestra++;
    if (second.palo == muestra.palo)
        num_muestra++;
}

string STRATEGY_NAME::name(){
    return _stringify(STRATEGY_NAME);
}