//
//  Longana.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Longana_hpp
#define Longana_hpp

#include "Tournament.hpp"
#include "Computer.hpp"
#include "Human.hpp"
#include "GlobalImports.h"
#include <fstream>

class Longana{
public:
    Longana();
    
    ~Longana();
    
    void start();
    
    void reset();
    
    void restart();
    
    
private:
    Player* human;
    Player* computer;
    Tournament* tournament;
    
    void init(string name, int score);
    
    void loadNewGame(string playerName);
    
};

#endif /* Longana_hpp */
