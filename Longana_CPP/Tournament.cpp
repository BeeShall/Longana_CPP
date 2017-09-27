//
//  Tournament.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Tournament.hpp"
Tournament::Tournament(){
    tournamentScore = 0;
    roundCount = 0;
    engineIndex =0 ;
    human = NULL;
    computer = NULL;
}

Tournament::Tournament(int finalScore, Player* human, Player* computer){
    this->tournamentScore = finalScore;
    this->human = human;
    this->computer = computer;
    roundCount =0;
    engineIndex = 0;
}

void Tournament::start(){
    srand((unsigned)time(NULL));
    while(human->getScore() < tournamentScore && computer->getScore() < tournamentScore){
        roundCount++;
        Round r(human, computer, getEnginePipForRound());
        r.play();
        if(r.isSaveAndQuit()){
            saveToFile(r.getSerielizedRoundInfo());
            return;
        }
        cout<<"Press any key to continue....";
        getchar();
    }
    
    cout<<"The torunament has ended!"<<endl;
    findWinner();
    
}

void Tournament::load(int roundCount, vector<string> &roundInfo){
    this->roundCount = roundCount;
    
    Round r(human,computer, getEnginePipForRound());
    r.load(roundInfo);
    if(!r.isSaveAndQuit()){
        roundCount++;
        start();
    }
    else saveToFile(r.getSerielizedRoundInfo());
}

void Tournament::findWinner(){
    int humanScore = human->getScore();
    int computerScore = computer->getScore();
    
    cout<< ((Human*)human)->getName()<<"'s final score: "<<humanScore<<endl;
    cout<<"Computer's final score: "<<computerScore<<endl;
    
    if(humanScore >= tournamentScore && computerScore >= tournamentScore){
        if (humanScore == computerScore){
            cout<<"The tournament was a draw"<<endl;
        }
        else if(humanScore>computerScore){
            printWinner(((Human*)human)->getName());
        }
        else{
            printWinner("Computer");
        }
    }
}

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
