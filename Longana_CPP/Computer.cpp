//
//  Computer.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Computer.hpp"

/* *********************************************************************
 Function Name: Computer
 Purpose: Default constructor for Computer class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
Computer::Computer(){
    playedMove = "";
    this->side = RIGHT;
    this->otherSide = LEFT;
}

/* *********************************************************************
 Function Name: play
 Purpose: To play and make the move for the computer
 Parameters:
 layout: pointer to the layout of the game
 passed: boolean to indicate if the previous player passed
 Return Value: MoveType indicating if the played move is valid. invalid
 Local Variables: hint, to store the AI generated move using the hint function
 Assistance Received: none
 ********************************************************************* */
MoveType Computer::play(Layout* layout, bool passed){
    
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

/* *********************************************************************
 Function Name: playTile
 Purpose: to play the tile and remove it from the hanf
 Parameters: tileIndex, integer, to remove from hand
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Computer::playTile(int tileIndex){
    hand->playTile(tileIndex);
}
