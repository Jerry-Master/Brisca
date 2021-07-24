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
    Deck start = D.starter_cards();
    card muestra = D.show_muestra();
    vector<Strategy*> players;
    players.push_back(Registry::new_strategy(pl1, Deck(&start[0], &start[3]), muestra));
    Strategy* player2 = nullptr;
    if (not human){
        players.push_back(Registry::new_strategy(pl2, Deck(&start[3], &start[3]+3), muestra));
    }
    players[0]->show();
    players[1]->show();

    bool current_player = 0;
    while (D.remaining_cards()){
        card first = players[current_player]->play();
        card second = players[not current_player]->play();

        bool change_curr_player = winner(first, second, muestra);
        if (change_curr_player) current_player = not current_player;

        players[current_player]->add_to_pile(first, second);

        players[current_player]->take_card(D.give_card());
        players[not current_player]->take_card(D.give_card());
    }
    int points1 = players[0]->count();
    int points2 = players[1]->count();
    if (points1 > points2){
        
    }
}