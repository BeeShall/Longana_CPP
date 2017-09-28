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
#include "Human.hpp"
#include "Computer.hpp"
#include "Layout.hpp"
#include <sstream>

class Round{
public:
    /* *********************************************************************
     Function Name: Round
     Purpose: Default constructor for the class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Round();
    
    /* *********************************************************************
     Function Name: Round
     Purpose: Constructor for the class
     Parameters:
         human, pointer to the human player,
         computer, pointer to the computer player,
         enginePip, integer to indicate the engine for the round
     Assistance Received: none
     ********************************************************************* */
    Round(Player* human, Player* computer, int enginePip);
    
    /* *********************************************************************
     Function Name: ~Round
     Purpose: Destructor for the class
     Assistance Received: none
     ********************************************************************* */
    ~Round();
    
    /* *********************************************************************
     Function Name: isSaveAndQuit
     Purpose: To save whether the user save and quit
     Parameters: None
     Return Value: boolean, whether the user saved and quit
     Assistance Received: none
     ********************************************************************* */
    inline bool isSaveAndQuit() const { return saveAndQuit; }
    
    /* *********************************************************************
     Function Name: play
     Purpose: To run the round
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm:
         1) Shuffles the stock
         2) generates the hand for Human and Computer
         3) determines the first player
         4) starts the round loop by calling start()
     Assistance Received: none
     ********************************************************************* */
    void play();
    
    /* *********************************************************************
     Function Name: load
     Purpose: To load the round given the roundState
     Parameters:
        roundInfo, constant reference to vector of string to save memory, serialized state of round to load
     Return Value: none
     Local Variables:
        vector<Tile> computerHand, to store parsed computer hand
         vector<Tile> humanHand, to store parsed human hand
         vector<Tile> layoutTiles,, to store parsed layout tiles
         vector<Tile> stockTiles, to store parsed boneyard tiles
     Assistance Received: none
     ********************************************************************* */
    void load(const vector<string> &roundInfo);
    
    /* *********************************************************************
     Function Name: getSerializedRoundInfo
     Purpose: To generate serialized string of round state
     Parameters: None
     Return Value: The serialized round state, string
     Local Variables:
        ostringstream, to create the string
     Assistance Received: none
     ********************************************************************* */
    string getSerializedRoundInfo();
    
    
private:
    //pointer to the boneyard
    Stock* stock;
    //ppinter to the human player
    Human* human;
    //pointer to the computer player
    Computer* computer;
    //pointer to the layout for the round
    Layout* layout;
    //indicates the player turn, true is user, false is computer
    bool turn;
    //indicates if the player passed
    bool passed;
    //number of passCounts after the boneyard gets empty, if the passcount reaches 3 then round is over
    int passCount;
    //indicates if the user wanted to save and quit
    bool saveAndQuit;
    
    /* *********************************************************************
     Function Name: start
     Purpose: To start the round
     Parameters: None
     Return Value: None
     Local Variables: None
     Algorithm:
         1) Runs a loop while the round hasn't ended
         2) Gets Human and Computer move turn by turn
         3) Checks if the user has indicated save an quit on every iteration, if yes serializes the round state
     Assistance Received: none
     ********************************************************************* */
    void start();
    
    /* *********************************************************************
     Function Name: determineFirstPlayer
     Purpose: To determine the first player for the round
     Parameters: None
     Return Value: None
     Algorithm:
         1) Get the engine
         2) Keep drawing tiles from the stock until one has the pip
     Assistance Received: none
     ********************************************************************* */
    void determineFirstPlayer();
    
    /* *********************************************************************
     Function Name: checkIfPlayerHasEngine
     Purpose: To check if the either player has engine
     Parameters: Tile, the engine tile
     Return Value: boolean, inidicating if the either player has engine
     Assistance Received: none
     ********************************************************************* */
    bool checkIfPlayerHasEngine(Tile engine);
    
    /* *********************************************************************
     Function Name: parsePips
     Purpose: To parse the serialized string to vector of pip Tiles
     Parameters: string containing serialized pip Tiles
     Return Value: vector of Tile containing parse pip Tiles
     Assistance Received: none
     ********************************************************************* */
    vector<Tile> parsePips(string pips);
    
    /* *********************************************************************
     Function Name: hasRoundEnded
     Purpose: To determine if the round has ended
     Parameters: None
     Return Value: boolean indicating if the round ended
     Assistance Received: none
     ********************************************************************* */
    bool hasRoundEnded();
    
    /* *********************************************************************
     Function Name: printRoundState
     Purpose: To print layout and the boneyard
     Parameters: None
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void printRoundState();
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void getUserMove();
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void getComputerMove();
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void getRoundScore();
  
};

#endif /* Round_hpp */
