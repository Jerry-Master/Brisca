#ifndef Utils_hh
#define Utils_hh

#include <cassert>
#include <cstdlib>
#include <getopt.h>
#include <string.h>
#include <time.h> 

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


/** \file
 * Contains several useful includes, plus defines for errors and other
 * utilities.
 */


/**
 * Assert with message.
 */
#define _my_assert(b, s) { if (not (b)) { cerr << "ERROR: " << s << endl; assert(b); } }


/**
 * Macro to specifically indicate when some code is unreachable,
 * so that the compiler doesn't cry when using NDEBUG.
 */
#define _unreachable() { _my_assert(false, "Unreachable code reached."); }


/**
 * C++11 to_string gives problems with Cygwin, so this is a replacement.
 */
inline string int_to_string (int i) {
    ostringstream oss;
    oss << i;
    return oss.str();
}

/**
 * C++11 stoi gives problems with Cygwin, so this is a replacement.
 */
inline int string_to_int (const string& s) {
    istringstream iss(s);
    int i;
    iss >> i;
    return i;
}

/* Function to read parameters from input */
inline void read_args(int argc, char **argv, string& output_file, int& seed, 
                      bool& human, bool& human_first, bool& verbose, int& nrounds,
                      string& player1, string& player2){
    int c;
    int option_index = 0;
    static struct option long_options[] = {
        {"output",  required_argument, 0,  'o' },
        {"seed",    required_argument, 0,  's' },
        {"human",   optional_argument, 0,  'h' },
        {"verbose", no_argument,       0,  'v' },
        {"nrounds", required_argument, 0,  'n' }
    };
 
    while ((c = getopt_long(argc, argv, "o:s:h::vn:",
                long_options, &option_index)) != -1) {

        switch (c) {
            case 0: // Long format
                if (string(long_options[option_index].name) == "output"){
                    output_file = optarg;
                } else if (string(long_options[option_index].name) == "seed"){
                    seed = string_to_int(optarg);
                } else if (string(long_options[option_index].name) == "human"){
                    human = true;
                    if (optarg) human_first = string(optarg) == "first";
                } else if (string(long_options[option_index].name) == "verbose"){
                    verbose = true;
                } else if (string(long_options[option_index].name) == "nrounds"){
                    nrounds = string_to_int(optarg);
                }
                break;
            case 'o':
                output_file = optarg;
                break;
            case 's':
                seed = string_to_int(optarg);
                break;
            case 'h':
                human = true;
                if (optarg) human_first = string(optarg) == "first";
                break;
            case 'v':
                verbose = true;
                break;
            case 'n':
                nrounds = string_to_int(optarg);
                break;
            case '?':
            cout << "?" << endl;
                break;

            default:
                cout << "?? getopt returned character code 0"<< c <<" ??\n";
        }
    }

    if (optind < argc) {
        player1 = "Strategy" + string(argv[optind++]);
        if (not human){
            _my_assert(optind < argc, "Needs one more player.");
            player2 = "Strategy" + string(argv[optind++]);
        } else {
            player2 = "StrategyHuman";
        }
        if (optind < argc){
            cout << "These parameters are not needed:";
            while (optind < argc){
                cout << " " << argv[optind++];
            }
            cout << endl;
        } 
    }
}
#endif
