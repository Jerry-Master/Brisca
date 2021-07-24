#include "Dealer.hh"

int randomfunc(int j){
    return rand() % j;
}

Dealer::Dealer(int seed) {
    for (const string& palo : PALOS){
        for (int i = 1; i <= 7; i++){
            deck.push_back(card(palo, i));
        }
        for (int i = 10; i <= 12; i++){
            deck.push_back(card(palo, i));
        }
    }
    srand(seed);
    random_shuffle(deck.begin(), deck.end(), randomfunc);
}

Deck Dealer::starter_cards(){
    _my_assert(deck.size() == 40, "Deck must have 40 cards at the beginning.")
    vector<card> give1, give2;
    for (int i = 0 ; i < 3; i++){
        give1.push_back(deck.back());
        deck.pop_back();

        give2.push_back(deck.back());
        deck.pop_back();
    }
    muestra = deck.back();
    deck.pop_back();

    give1.insert(--give1.end(), give2.begin(), give2.end());
    _my_assert(give1.size()==6, "Must have 6 cards.");
    return give1;
}

card Dealer::give_card(){
    _my_assert(deck.size() > 0, "Deck must have cards to give.")
    card give = deck.back();
    deck.pop_back();
    return give;
}

int Dealer::remaining_cards(){
    return deck.size();
}

card Dealer::show_muestra(){
    return muestra;
}