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
        tournamentScore =0;
        roundCount =0;
        engineIndex = 0;
    }
    
    void start(){
        //while(human->getScore() < tournametScore && computer->getScore() < tournametScore){
        roundCount++;
        cout<<"Engine pip"<<getEnginePipForRound()<<endl;
            Round r(human, computer, getEnginePipForRound());
            r.play();
        //}
        
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
    
    inline void printWinner(string winner){cout<<"Congratulations! "<<winner<<"has won the tournament !"<<endl;}
    
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
        
        if(human->getScore()>= tournamentScore) {
            printWinner(((Human*)human)->getName());
            //human won
        }
        else{
            printWinner("Computer");
            //computer won
        }
    }
    
};

#endif /* Tournament_hpp */
