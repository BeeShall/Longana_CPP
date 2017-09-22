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
            tournamentScore += r.getRoundScore();
        //}
        
        if(human->getScore()>= tournamentScore) {
            //human won
        }
        else{
            //computer won
        }
    }
    
    void load(int tournamentScore, int roundCount, vector<string> &roundInfo){
        this->tournamentScore = tournamentScore;
        this->roundCount = roundCount;
        
        Round r(human,computer, getEnginePipForRound());
        r.load(roundInfo);
        this->tournamentScore += r.getRoundScore();
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
    
};

#endif /* Tournament_hpp */
