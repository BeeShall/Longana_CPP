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
#include "Player.hpp"

class Round{
public:
    Round(){
        
    }
    
    Round(Player* human, Player* computer){
        stock = new Stock();
        this->human = human;
        this->computer = computer;
    }
    
    void start(){
        printRoundState();
        stock->shuffleStock();
        human->setNewHand(stock->generateHand());
        computer->setNewHand(stock->generateHand());
        printRoundState();
    }
    
    void printRoundState(){
        stock->displayStock();
        human->displayHand();
        computer->displayHand();
    }
    
    
private:
    Stock* stock;
    Player* human;
    Player* computer;
};

#endif /* Round_hpp */
