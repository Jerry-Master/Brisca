#ifndef Registry_hh
#define Registry_hh
#include "Utils.hh"
#include "Structs.hh"

/** \file
 * Magic to register players.
 */


class Strategy;


/**
 * Since the main program does not know how many strategies will be inherited
 * from the Strategy class, we use a registration and factory pattern.
 */
class Registry {
    public:
        typedef Strategy* (*Factory)(const Deck&, card);
        static int Register (const char* name, Factory fact);
        static Strategy* new_strategy (string name, const Deck& cards, card muestra);
        static void print_strategies (ostream& os);
};

#define _stringify(s) _stringification(s)
#define _stringification(s) #s
#define RegisterStrategy(x) static int registration = \
        Registry::Register(_stringify(x), x::factory)

#endif
