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

#define MAX_PIP 6

class Tournament{
public:
    Tournament(){
        tournamentScore = 0;
        roundCount = 0;
        engineIndex =0 ;
    }
    
    Tournament(int finalScore, Player* human, Player* computer){
        this->tournamentScore = finalScore;
        this->human = human;
        this->computer = computer;
        roundCount =0;
        engineIndex = 0;
    }
    
    void start(){
        while(human->getScore() < tournamentScore && computer->getScore() < tournamentScore){
        roundCount++;
            Round r(human, computer, getEnginePipForRound());
            r.play();
        if(r.isSaveAndQuit()){
            string roundInfo = r.getSerielizedRoundInfo();
            saveToFile(roundInfo);
            return;
        }
        }
        
        cout<<"The torunament has ended!"<<endl;
        findWinner();
        
    }
    
    void load(int roundCount, vector<string> &roundInfo){
        this->roundCount = roundCount;
        
        Round r(human,computer, getEnginePipForRound());
        r.load(roundInfo);
        roundCount++;
        start();
        
    }
private:
    int tournamentScore;
    int roundCount;
    Player* human;
    Player* computer;
    int engineIndex;
    
    inline int getEnginePipForRound(){ return MAX_PIP - (roundCount-1)%MAX_PIP;}
    
    inline void printWinner(string winner){cout<<"Congratulations! "<<winner<<" has won the tournament !"<<endl;}
    
    void findWinner(){
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
    
    void saveToFile(const string &roundInfo){
        string fileName;
        cout<<endl;
        cout<<"Please enter the name of the file you want to save the game to: ";
        cin.ignore();
        getline(cin, fileName);
        ofstream fout;
        fout.open(fileName);
        fout<<"Tournament Score: "<<tournamentScore<<endl;
        fout<<"Round No.: "<<roundCount<<endl;
        fout<<endl;
        fout<<roundInfo;
        
        fout.close();
    }
    
    
};

#endif /* Tournament_hpp */
