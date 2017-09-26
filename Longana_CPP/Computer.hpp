//
//  Computer.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include "Player.hpp"

class Computer : public Player{
public:
    Computer(){
        playedMove = "";
        this->side = RIGHT;
        this->otherSide = LEFT;
        
    }
    
    MoveType play(Layout* layout, bool passed){
        
        //print computer played what on which side
        Move hint = this->hint(layout, passed);
        if(hint.first.first == -1) return INVALID;
        else{
            layout->placeTile(hint);
            hand->playTile(hint.first);
            playedMove = to_string(hint.first.first) + " - " + to_string(hint.first.second) + " on the " + getSideString(hint.second);
        }
        return VALID;
    }
    
    void playTile(int tileIndex){
        hand->playTile(tileIndex);
    }
    string getPlayedMove(){
        return playedMove;
    }
    
private:
    string playedMove;
    
};

#endif /* Computer_hpp */
