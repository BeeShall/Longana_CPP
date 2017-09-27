//
//  Human.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Human.hpp"

Human::Human(){
    this->side = LEFT;
    this->otherSide = RIGHT;
}

Human::Human(string name){
    this->name = name;
    this->side = LEFT;
    this->otherSide = RIGHT;
}

MoveType Human::play(int tileIndex, Side side, Layout* layout, bool passed){
    //if human is trying to set the engine
    if(side == ENGINE){
        hand->playTile(tileIndex-1);
        return VALID ;
    }
    
    Tile playedTile = getTilefromHand(tileIndex);
    
    
    //checking if the side is valid
    if((!isTileDouble(playedTile) && !passed) && side == RIGHT) return INVALID; //if tile is a single and was not passed, then right is invalid;
    
    //checking if the tile placed by human is a valid one
    if(layout->placeTile({playedTile, side})){
        hand->playTile(tileIndex-1);
        return VALID;
    }
    return INVALID;
}

Move Human::getHint(Layout* layout, bool passed){
    return hint(layout, passed);
}
    

