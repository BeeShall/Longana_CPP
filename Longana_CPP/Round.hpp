//
//  Round.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Round_hpp
#define Round_hpp

#include <stdio.h>
#include "Stock.hpp"
#include "Human.hpp"
#include "Computer.hpp"
#include "Layout.hpp"
#include <sstream>

class Round{
public:
    Round();
    
    Round(Player* human, Player* computer, int enginePip);
    
    ~Round();
    
    inline bool isSaveAndQuit() const { return saveAndQuit; }
    
    void play();
    
    void load(vector<string> roundInfo);
    
    string getSerielizedRoundInfo();
    
    
private:
    Stock* stock;
    Human* human;
    Computer* computer;
    Layout* layout;
    bool turn;  //true is user, false is computer
    bool passed;
    int passCount;
    bool saveAndQuit;
    
    
    bool checkIfPlayerHasEngine(Tile engine);
    
    void determineFirstPlayer();
    
    void start();
    
    vector<Tile> parsePips(string pips);
    
    bool hasGameEnded();
    
    void printRoundState();
    
    void getUserMove();
    
    void getComputerMove();

    void getRoundScore();
  
};

#endif /* Round_hpp */
