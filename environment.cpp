#include "Strategy.hh"
#include "Dealer.hh" 
using namespace std;

int main(int argc, char **argv) {
    string output_file = "a.json";
    int seed = 42;
    bool human = false;
    bool verbose = false;
    string pl1, pl2;  
    read_args(argc, argv, output_file, seed, human, verbose, pl1, pl2);  
    
    Dealer D(seed);
    cout << human << endl;
    Deck start = D.starter_cards();
    show_deck(start);
    for (int i = 0; i < 6; i++){
        _my_assert(start[i].palo.size()>0, "Void palo.(env)");

    }
    Strategy* player1 = Registry::new_strategy(pl1, Deck(start.begin(), start.begin()+3));
    Strategy* player2 = nullptr;
    if (not human){
        player2 = Registry::new_strategy(pl2, Deck(start.begin()+3, start.end()));
    }
    player1->play();
    player2->play();
}