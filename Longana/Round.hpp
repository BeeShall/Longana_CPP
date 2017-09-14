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
#include "Layout.hpp"

class Round{
public:
    Round(){
        
    }
    
    Round(Player* human, Player* computer){
        stock = new Stock();
        this->human = human;
        this->computer = computer;
        layout = new Layout();
    }
    
    void start(){
        stock->shuffleStock();
        human->setNewHand(stock->generateHand());
        computer->setNewHand(stock->generateHand());
        printRoundState();
        
        while(!stock->isEmpty()){
            
        }
    }
    
    void printRoundState(){
        layout->displayLayout();
        stock->displayStock();
        cout<<"Human Hand: "<<endl;
        human->displayHand();
        cout<<"Computer Hand: "<<endl;
        computer->displayHand();
    }
    
    
private:
    Stock* stock;
    Player* human;
    Player* computer;
    Layout* layout;
    bool turn;
};

#endif /* Round_hpp */
