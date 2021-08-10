# Brisca

This program simulates several brisca games and tells which strategy is the best on average. You can also play agains any strategy but there isn't any pretty interface.

## Compilation

Simply enter the directory in the terminal and do ```make```. If you haven't cloned the repository the instructions will be
```
git clone https://github.com/Jerry-Master/Brisca.git
cd Brisca
mkdir
make
```

It is possible that you will need to execute it as administrator, in that case just use ```sudo make```. Don't worry about that, it is only for the creation of the obj directory.

## Execution

In the command line do ```./environment.exe player1 player2 [-o | --output filename] [-s | --seed seed] [-h | --human human-first] [-v | --verbose] [-n | --nrounds nrounds]```. They are all optional but it is required that you write them in order. Below is the meaning of each one:
* Output: Specifies where to save the result of the games. By default is a.txt.
* Seed: It is the seed of the random generator of the deck. Used for reproducibility.
* Human: Use it if you want to play against the machine. If you want to start first type ```-hfirst``` without spaces.
* Verbose: It writes more information about the games in the output.
* N-rounds: The number of rounds to play. It takes over a second to execute 100000 games.

If a strategy is called StrategyDummy, it is only needed to write player1 as Dummy.

## Design your own strategy

In case you want to write your own strategy you only need to copy the ```StrategyDummy.hh``` and the ```StrategyDummy.cpp``` change the name of the files to ```StrategySomething``` and modify the ```play()``` and ```update()``` methods. The first one should return one of the at most three cards in the player hand, if the player goes second, the card in the table is passed to the method and can be used in the strategy. The update method can be used to save any information after each round like the number of 1s that had been played.
