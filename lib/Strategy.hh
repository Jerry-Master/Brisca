#pragma once
#include "Registry.hh"

class Strategy{
    protected:
        Deck cards, pile;
        card muestra;
    public:
        Strategy(const Deck& cards_, card muestra_);
        /* 
            Play: returns the move in the next turn 
            and deletes the card from deck
            It will be overwritten, thus virtual
        */
        virtual card play (card card_ = card()){return card_;};
        virtual void update (card first = card(), card second = card()){};

        /* Shows the cards in console */
        void show(ostream& os);
        void show_pile(ostream& os);

        /* Counts the point currently in the pile */
        int count();

        /* Add cards to pile and deck */
        void add_to_pile(card c1, card c2);
        void take_card(card c);

        /* Returns name (will be overwritten)*/
        virtual string name(){return "";};
};