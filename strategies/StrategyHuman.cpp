#include "StrategyHuman.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_, card muestra) {
    return new STRATEGY_NAME(cards_, muestra);
}

card STRATEGY_NAME::play(card card_) {
    cout << "Select your move:" << endl;
    for (int i = 0; i < cards.size(); i++){
        cout << "(" << char('a'+i) << ") ";
        print_card(cards[i]);
    }
    char select;
    cin >> select;
    while (select < 'a' or select > 'a'+cards.size()-1){
        cout << "Not a valid move." << endl;
        cin >> select;
    }
    int selection = select - 'a';
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