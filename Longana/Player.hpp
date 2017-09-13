//
//  Player.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "GlobalImports.h"
#include "Hand.hpp"

class Player{
public:
    Player(){
        score = 0;
        hand = new Hand();
    }
    
    void setNewHand(Hand* hand) {
        delete this->hand;
        this->hand = hand;
    }
    
    int getScore(){
        return score;
    }
    
    void addScore(int score){
        this->score += score;
    }
    
    void displayHand(){
        hand->displayHand();
    }
    
private:
    Hand* hand;
    int score;
    
};

#endif /* Player_hpp */
