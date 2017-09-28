//
//  Longana.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Longana_hpp
#define Longana_hpp

#include "Tournament.hpp"
#include "Computer.hpp"
#include "Human.hpp"
#include "GlobalImports.h"
#include <fstream>

class Longana{
public:
    /* *********************************************************************
     Function Name: Longana
     Purpose: Default constructor for the class
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm: None
     Assistance Received: none
     ********************************************************************* */
    Longana();
    
    /* *********************************************************************
     Function Name: ~Longana
     Purpose: Destructor for the class
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm: Cleans up both tha player and tournament
     Assistance Received: none
     ********************************************************************* */
    ~Longana();
    
    /* *********************************************************************
     Function Name: start
     Purpose: To start the game by loading from file or  start fresh initializing players and tournament
     Parameters: None
     Return Value: None
     Local Variables: strings and characters used to get user choices
     Algorithm: Ask for user name and asks whether to start a new game or load saved.
     Assistance Received: none
     ********************************************************************* */
    void start();
    
    /* *********************************************************************
     Function Name: reset
     Purpose: To free up resources from heap
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm: delete players and tournament
     Assistance Received: none
     ********************************************************************* */
    void reset();
    
    /* *********************************************************************
     Function Name: restart
     Purpose: to restart a new game
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm: Free resources and run start()
     Assistance Received: none
     ********************************************************************* */
    void restart();
    
    
private:
    //pointer to store the human player
    Player* human;
    
    //pointer to store the computer player
    Player* computer;
    
    //pointer to store the tournament object which has the rounds
    Tournament* tournament;
    
    /* *********************************************************************
     Function Name: init
     Purpose: initialize players and tournament
     Parameters:
         name, stirng for the human name
         score, integer for tournament score from the user
     Return Value: None
     Local Variables: None
     Assistance Received: none
     ********************************************************************* */
    void init(string name, int score);
    
    /* *********************************************************************
     Function Name: loadNewGame
     Purpose: To load a saved game from file
     Parameters:
         playerName, name of the human player for the game
     Return Value: None
     Local Variables:
         game, ifstream to read from file
         line, string to read lines from file
         roundInfo, vector of strings to store lines from the file that contain info for the round which the Round class will parse
     Algorithm:
         1) Read the filename user wants to load game from
         2) Read lines from the file and parse tournament score and round count
         3) Omit the empty lines and store rest of the lines in a vector
     Assistance Received: none
     ********************************************************************* */
    void loadNewGame(string playerName);
    
};

#endif /* Longana_hpp */
