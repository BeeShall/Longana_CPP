//
//  Longana.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Longana.hpp"
Longana::Longana(){
    human=NULL;
    computer = NULL;
    tournament = NULL;
}

Longana::~Longana(){
    reset();
}

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

void Longana::reset(){
    delete human;
    delete computer;
    delete tournament;
}

void Longana::restart(){
    reset();
    start();
}

void Longana::init(string name, int score){
    human = new Human(name);
    computer = new Computer();
    tournament = new Tournament(score, human, computer);
}

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
    
    getline(game, line);
    cout<<line<<endl;
    int tournamentScore = stoi(removeLabel(line));
    
    getline(game, line);
    int roundNo = stoi(removeLabel(line));
    
    vector<string> roundInfo;
    while(getline(game, line)){
        if(line != ""){
            roundInfo.push_back(line);
        }
    }
    
    game.close();
    init(playerName , tournamentScore);
    
    tournament->load(roundNo, roundInfo);
}



