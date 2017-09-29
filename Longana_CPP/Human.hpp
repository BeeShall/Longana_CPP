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
    /* *********************************************************************
     Function Name: Human
     Purpose: Default constructor for Human class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Human();
    
    /* *********************************************************************
     Function Name: Human
     Purpose: Constructor for the Human class
     Parameters: name, string for the user name
     Assistance Received: none
     ********************************************************************* */
    Human(string name);
    
    /* *********************************************************************
     Function Name: getName
     Purpose: To get the name of the human player
     Parameters: None
     Return Value: string, name of the human player
     Assistance Received: none
     ********************************************************************* */
    inline string getName() {return name;}
    
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
    MoveType play(int tileIndex, Side side, Layout* layout, bool passed);
    
    /* *********************************************************************
     Function Name: hint
     Purpose: To get the best possible hint given the game state
     Parameters:
         layout: pointer to layout to check for tile placement,
         passed: boolean value indicating if the earlier player had passed
     Return Value: Move containing the hint tile and side
     Assistance Received: none
     ********************************************************************* */
    Move getHint(Layout* layout, bool passed);
private:
    
    //string to store the human player name
    string name;
    
};

#endif /* Human_hpp */
