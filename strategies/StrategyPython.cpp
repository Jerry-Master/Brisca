#include "StrategyPython.hh"

Strategy* STRATEGY_NAME::factory (const Deck& cards_, card muestra) {
    return new STRATEGY_NAME(cards_, muestra);
}

card STRATEGY_NAME::play(card card_) {
    // Read state
    ofstream inp(infile);
    if (card_.palo.size() > 0){
        inp << '[';
        print_card_json(card_, inp);
        inp << ',';
        print_deck_json(cards, inp);
        inp << ']';
    } else print_deck_json(cards, inp);
    inp.close();

    // Compute strategy
    int result = system(("python3 strategies/Strategy.py -i " + infile + " -o " + outfile).c_str()); 

    // Return action
    ifstream out(outfile);
    int selection;
    out >> selection;
    out.close();
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