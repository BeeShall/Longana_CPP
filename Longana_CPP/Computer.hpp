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
    /* *********************************************************************
     Function Name: Computer
     Purpose: Default constructor for Computer class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Computer();
    
    /* *********************************************************************
     Function Name: getPlayedMove
     Purpose: to get the last move played by the computer
     Parameters: None
     Return Value: stringified move played by the computer
     Assistance Received: none
     ********************************************************************* */
    inline string getPlayedMove() const{ return playedMove; }
    
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
    MoveType play(Layout* layout, bool passed);
    
    /* *********************************************************************
     Function Name: playTile
     Purpose: to play the tile and remove it from the hanf
     Parameters: tileIndex, integer, to remove from hand
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void playTile(int tileIndex);
    
private:
    //stores the last move played by the computer
    string playedMove;
    
};

#endif /* Computer_hpp */
