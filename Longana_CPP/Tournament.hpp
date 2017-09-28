//
//  Tournament.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Tournament_hpp
#define Tournament_hpp

#include "GlobalImports.h"
#include "Round.hpp"
#include "Player.hpp"
#include <fstream>

//the maximum number of pip value possible
#define MAX_PIP 6

class Tournament{
public:
    /* *********************************************************************
     Function Name: Tournament
     Purpose: Default constructor for the class
     Parameters:  None
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    Tournament();
    
    /* *********************************************************************
     Function Name: Tournament
     Purpose: Contructor for the class
     Parameters:
         finalScore, integer, the tournament score for the game
         human, pointer to the human player
         computer, pointer to the computer player
     Return Value: None
     Local Variables: None
     Assistance Received: none
     ********************************************************************* */
    Tournament(int finalScore, Player* human, Player* computer);
    
    /* *********************************************************************
     Function Name: start
     Purpose: starts the tournament and the rounds
     Parameters: None
     Return Value: None
     Local Variables: Nonr
     Algorithm:
         1) Runs a loop until either playes scores does not reach the tournament score
         2) creates rounds and serielizes the game to file is user requested
     Assistance Received: none
     ********************************************************************* */
    void start();
    
    /* *********************************************************************
     Function Name: load
     Purpose: load the tournament and round with the lines from the file
     Parameters:
         roundCount, integer, indicates how many rounds have been played
         roundInfo, vector of string, contains the lines from file that contain round information, passed as a constant reference to prevent making a copy to save memory
     Return Value: None
     Local Variables:None
     Algorithm: Initialized round with the players and sends the roundInfo
     Assistance Received: none
     ********************************************************************* */
    void load(int roundCount, const vector<string> &roundInfo);
    
private:
    
    //stores the target score for the tournament
    int tournamentScore;
    //indicates how many rounds have been played
    int roundCount;
    //pointer to the human player
    Player* human;
    //pointer to the computer player
    Player* computer;
    //keeps track of the engine pip value
    int engineIndex;
    
    /* *********************************************************************
     Function Name: getEnginePipForRound
     Purpose: To calculate the engine for the round
     Parameters: None
     Return Value: integer, corresponding engine pip value for round
     Local Variables: None
     Algorithm:
         1) Get the remainder of round number divided by maximum pip value
         2) subtract that from the maximum pip value
     Assistance Received: none
     ********************************************************************* */
    inline int getEnginePipForRound(){ return MAX_PIP - (roundCount-1)%MAX_PIP;}
    
    /* *********************************************************************
     Function Name: findWinner
     Purpose: find the winner and prints the scores
     Parameters: None
     Return Value: None
     Local Variables:
         humanScore, integer to store human score
         computerScore, integer to store computer score
     Algorithm:
         1) if human score is greater than computerScore, human wins
         2) if the other way, computer wins
         3) if they are equal, its a draw
     Assistance Received: none
     ********************************************************************* */
    void findWinner();
    
    /* *********************************************************************
     Function Name: printWinner
     Purpose: To print the winner to the console
     Parameters:
         winner, string, name of the winner
     Return Value: None
     Local Variables: None
     Assistance Received: none
     ********************************************************************* */
    inline void printWinner(string winner){cout<<"Congratulations! "<<winner<<" has won the tournament !"<<endl;}
    
    /* *********************************************************************
     Function Name: saveToFile
     Purpose: saves the round and tournament state to a file
     Parameters:
         roundInfo, constant reference to string to save memory, the round state serielized to a string
     Return Value: None
     Local Variables:
        fileName, string, to store the name of the file user wants to save to
        fout, ofstreams, outputstream to write to the file
     Assistance Received: none
     ********************************************************************* */
    void saveToFile(const string &roundInfo);
    
};

#endif /* Tournament_hpp */
