//
//  Human.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Human.hpp"

/* *********************************************************************
 Function Name: Human
 Purpose: Default constructor for Human class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
Human::Human(){
    this->side = LEFT;
    this->otherSide = RIGHT;
}

/* *********************************************************************
 Function Name: Human
 Purpose: Constructor for the Human class
 Parameters: name, string for the user name
 Assistance Received: none
 ********************************************************************* */
Human::Human(string name){
    this->name = name;
    this->side = LEFT;
    this->otherSide = RIGHT;
}

/* *********************************************************************
 Function Name: play
 Purpose: To play and make the move for the player
 Parameters:
 tileIndex: index of the tile in hand starting 1, integer
 side: side the tile is to be placed
 layout: pointer to the layout of the game
 passed: boolean to indicate if the previous player passed
 Return Value: MoveType indicating if the played move is valid. invalid
 Local Variables: playedTile, to get the tile played played from hand using passed index
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: hint
 Purpose: To get the best possible hint given the game state
 Parameters:
 layout: pointer to layout to check for tile placement,
 passed: boolean value indicating if the earlier player had passed
 Return Value: Move containing the hint tile and side
 Assistance Received: none
 ********************************************************************* */
Move Human::getHint(Layout* layout, bool passed){
    return hint(layout, passed);
}
    

