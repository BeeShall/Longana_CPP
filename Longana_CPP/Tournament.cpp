//
//  Tournament.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Tournament.hpp"

/* *********************************************************************
 Function Name: Tournament
 Purpose: Default constructor for the class
 Parameters:  None
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
Tournament::Tournament(){
    tournamentScore = 0;
    roundCount = 0;
    engineIndex =0 ;
    human = NULL;
    computer = NULL;
}

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
Tournament::Tournament(int finalScore, Player* human, Player* computer){
    this->tournamentScore = finalScore;
    this->human = human;
    this->computer = computer;
    roundCount =0;
    engineIndex = 0;
}

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
void Tournament::start(){
    //seeding for random shuffle
    srand((unsigned)time(NULL));
    
    //while either player doesn't reach the tournament score
    while(human->getScore() < tournamentScore && computer->getScore() < tournamentScore){
        roundCount++;
        
        //init the round
        Round r(human, computer, getEnginePipForRound());
        r.play();
        
        //if user wishes to save and quit, serielize
        if(r.isSaveAndQuit()){
            saveToFile(r.getSerielizedRoundInfo());
            return;
        }
        cout<<"Press any key to continue....";
        getchar();
    }
    
    //after reaching the tournament score
    cout<<"The torunament has ended!"<<endl;
    findWinner();
    
}

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
void Tournament::load(int roundCount, const vector<string> &roundInfo){
    this->roundCount = roundCount;
    
    Round r(human,computer, getEnginePipForRound());
    r.load(roundInfo);
    
    //If the user wants to quit within the same round as the loaded,
    //this function will not have been ended
    //so need to serielize from here
    if(!r.isSaveAndQuit()){
        roundCount++;
        start();
    }
    else saveToFile(r.getSerielizedRoundInfo());
}

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
void Tournament::findWinner(){
    int humanScore = human->getScore();
    int computerScore = computer->getScore();
    
    cout<< ((Human*)human)->getName()<<"'s final score: "<<humanScore<<endl;
    cout<<"Computer's final score: "<<computerScore<<endl;
    
    //if the scores are equal its a draw
    if (humanScore == computerScore){
        cout<<"The tournament was a draw"<<endl;
    }
    //if human has greater score, human is winner
    else if(humanScore>computerScore){
        printWinner(((Human*)human)->getName());
    }
    //else computer is winner
    else{
        printWinner("Computer");
    }
    
}

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
void Tournament::saveToFile(const string &roundInfo){
    string fileName;
    cout<<endl;
    cin.ignore();
    cout<<"Please enter the name of the file you want to save the game to: ";
    getline(cin,fileName);
    ofstream fout;
    fout.open("/Users/beeshall/Documents/Fall 2018/OPL/Longana_CPP/"+fileName);
    fout<<"Tournament Score: "<<tournamentScore<<endl;
    fout<<"Round No.: "<<roundCount<<endl;
    fout<<endl;
    fout<<roundInfo;
    
    fout.close();
}
