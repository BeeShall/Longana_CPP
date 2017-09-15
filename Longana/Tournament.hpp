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

class Tournament{
public:
    Tournament(){
        tournametScore = 0;
    }
    
    Tournament(int finalScore, Player* human, Player* computer){
        this->tournametScore = finalScore;
        this->human = human;
        this->computer = computer;
    }
    
    void start(){
        int engineIndex = 0;
        //while(human->getScore() < tournametScore && computer->getScore() < tournametScore){
        int enginePip = 6 - engineIndex%6;
            Round r(human, computer, enginePip);
            r.start();
        //}
        
        if(human->getScore()>= tournametScore) {
            //human won
        }
        else{
            //computer won
        }
    }
private:
    int tournametScore;
    Player* human;
    Player* computer;
    
};

#endif /* Tournament_hpp */
