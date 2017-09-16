//
//  Human.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include "Player.hpp"

class Human:public Player{
public:
    Human(){
        
    }
    
    Human(string name){
        this->name = name;
    }
    
    inline string getName() {return name;}
    
    Move play(int tileIndex, Side side, Layout* layout, bool passed){
        
    
        
        //if human is trying to set the engine
        if(side == ENGINE){
            hand->playTile(tileIndex);
            return VALID ;
        }
        
        Tile playedTile = getTilefromHand(tileIndex);
        
        
        //checking if the side is valid
        if((!isTileDouble(playedTile) && !passed) && side == RIGHT) return INVALID; //if tile is a single and was not passed, then right is invalid;
        
        //checking if the tile placed by human is a valid one
        if(layout->placeTile(playedTile, side)){
            hand->playTile(tileIndex);
            return VALID;
        }
        return INVALID;
    }
    
    Tile getHint(Layout* layout){
        return hint(layout);
    }
private:
    string name;
    
};

#endif /* Human_hpp */
