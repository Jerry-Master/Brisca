#include "Strategy.hh"
#include "Dealer.hh" 
using namespace std;

string output_file = "a.txt";
int seed = time(NULL);
bool human = false;
bool human_first = false;
bool verbose = false;
int nrounds = 1;
string pl1, pl2; 

void one_round(ofstream& f, Dealer& D, vector<Strategy*>& players, bool& current_player, 
               card muestra, bool take=true){
    if (verbose){
        f << "First player cards:" << endl;
        players[current_player]->show(f);
    }
    card first = players[current_player]->play();
    if (human){
        cout << "First player " << players[current_player]->name() << " plays: ";
        print_card(first);
    }
    if (verbose){
        f << "First player " << players[current_player]->name() << " plays: ";
        print_card(first, f);
    }
    if (verbose){
        f << "Second player cards:" << endl;
        players[not current_player]->show(f);
    }
    card second = players[not current_player]->play(first);
    if (human){
        cout << "Second player " << players[not current_player]->name() << " plays: ";
        print_card(second);
    } if (verbose){
        f << "Second player " << players[not current_player]->name() << " plays: ";
        print_card(second, f);
    }

    bool change_curr_player = winner(first, second, muestra);
    if (change_curr_player) current_player = not current_player;

    players[current_player]->add_to_pile(first, second);

    players[current_player]->update(first, second);
    players[not current_player]->update(first, second);

    if (take){
        players[current_player]->take_card(D.give_card());
        if (D.remaining_cards()){
            players[not current_player]->take_card(D.give_card());
        } else {
            players[not current_player]->take_card(muestra);
        }
    }
}

int one_game(ofstream& f, bool result=true){
    Dealer D;
    Deck start = D.starter_cards();
    card muestra = D.show_muestra();
    if (human){
        cout << "Muestra: ";
        print_card(muestra);
    }
    if (verbose){
        f << "Muestra: ";
        print_card(muestra, f);
    }
    vector<Strategy*> players;
    players.push_back(Registry::new_strategy(pl1, Deck(&start[0], &start[3]), muestra));
    players.push_back(Registry::new_strategy(pl2, Deck(&start[3], &start[3]+3), muestra));
    
    if (human_first) swap(players[0], players[1]); 

    bool current_player = 0;
    int round = 1;
    while (D.remaining_cards()){
        if (verbose)
            f << "Round: " << round++ << endl;
        one_round(f, D, players, current_player, muestra);
    }
    // Last 3 rounds
    for (int i = 0; i < 3; i++){
        if (verbose)
            f << "Round: " << round++ << endl;
        one_round(f, D, players, current_player, muestra, false);
    }
    int points1 = players[0]->count();
    int points2 = players[1]->count();
    _my_assert((points1+points2)==120, "Total must sum up to 120.");
    if (points1 > points2){
        if (result) cout << "First player " <<  " won: " << pl1 << endl;
        if (verbose) f << "First player " <<  " won: " << pl1 << endl;
        return -1;
    } else if (points1 < points2) {
        if (result) cout << "Second player " <<  " won: " << pl2 << endl;
        if (verbose) f << "Second player " <<  " won: " << pl2 << endl;
        return 1;
    } else {
        if (result) cout << "Tie" << endl;
        if (verbose) f << "Tie" << endl;
        return 0;
    }
}

int main(int argc, char **argv) {  
    read_args(argc, argv, output_file, seed, human, human_first, verbose, nrounds, pl1, pl2);  
    srand(seed);
    ofstream f;
    if (verbose) f.open(output_file);

    if (nrounds == 0 or human){
        one_game(f);
    } else {
        int wins1 = 0;
        int wins2 = 0;
        int ties = 0;
        for (int i = 0; i < nrounds; i++){
            if (verbose){
                f << "Game: " << i << endl;
            }
            int res = one_game(f,false);
            if (res == -1) wins1++;
            else if (res == 1) wins2++;
            else ties++;
            if (verbose) f << endl;
        }
        cout << "Player1(" << pl1 << ") won: " << wins1 << " games. Winrate: " 
             << double(wins1) / (wins1 + wins2 + ties) * 100 << "%" << endl;
        cout << "Player2(" << pl2 << ") won: " << wins2 << " games. Winrate: " 
             << double(wins2) / (wins1 + wins2 + ties) * 100 << "%" << endl;
        cout << "Number of ties: " << ties << ". Tierate: " 
             << double(ties) / (wins1 + wins2 + ties) * 100 << "%" << endl;
    }
    if (verbose) f.close();
}