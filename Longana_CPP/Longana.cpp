//
//  Longana.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Longana.hpp"

/* *********************************************************************
 Function Name: Longana
 Purpose: Default constructor for the class
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm: None
 Assistance Received: none
 ********************************************************************* */
Longana::Longana(){
    human=NULL;
    computer = NULL;
    tournament = NULL;
}

/* *********************************************************************
 Function Name: ~Longana
 Purpose: Destructor for the class
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm: Cleans up both tha player and tournament
 Assistance Received: none
 ********************************************************************* */
Longana::~Longana(){
    reset();
}

/* *********************************************************************
 Function Name: start
 Purpose: To start the game by loading from file or  start fresh initializing players and tournament
 Parameters: None
 Return Value: None
 Local Variables: strings and characters used to get user choices
 Algorithm: Ask for user name and asks whether to start a new game or load saved.
 Assistance Received: none
 ********************************************************************* */
void Longana::start(){
    cout<<"Hi! Welcome to Longana!"<<endl;
    cout<<"Please enter your name: ";
    string name;
    getline(cin,name);
    
    char choice;
    cout<<"Would you like to load a game? Press y for yes. ";
    cin>>choice;
    cout<<endl;
    if(isChoiceYes(choice)) loadNewGame(name);
    else{
        int score;
        cout<<"Please enter a tournament score: ";
        cin>>score;
        cout<<endl;
        init(name,score);
        tournament->start();
    }
}

/* *********************************************************************
 Function Name: reset
 Purpose: To free up resources from heap
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm: delete players and tournament
 Assistance Received: none
 ********************************************************************* */
void Longana::reset(){
    delete human;
    delete computer;
    delete tournament;
}

/* *********************************************************************
 Function Name: restart
 Purpose: to restart a new game
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm: Free resources and run start()
 Assistance Received: none
 ********************************************************************* */
void Longana::restart(){
    reset();
    start();
}

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
void Longana::init(string name, int score){
    human = new Human(name);
    computer = new Computer();
    tournament = new Tournament(score, human, computer);
}

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
void Longana::loadNewGame(string playerName){
    string name;
    ifstream game;
    do{
        cin.ignore();
        cout<<"Enter the file name of the game you want to load with the extension: ";
        getline(cin,name);
        name = "/Users/beeshall/Documents/Fall 2018/OPL/Longana_CPP/" + name;
        
        game.open(name);
    } while(!game.is_open());
    
    string line;
    
    //Parsing tournament score
    getline(game, line);
    cout<<line<<endl;
    int tournamentScore = stoi(removeLabel(line));
    
    //parsing round count
    getline(game, line);
    int roundNo = stoi(removeLabel(line));
    
    //storing rest of the lines exclusing enpty lines to later parse from the round
    vector<string> roundInfo;
    while(getline(game, line)){
        if(line != ""){
            roundInfo.push_back(line);
        }
    }
    
    game.close();
    
    //Initialize the tournament with parsed info and load the torunament
    init(playerName , tournamentScore);
    
    tournament->load(roundNo, roundInfo);
}



