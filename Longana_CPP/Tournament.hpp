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
    Tournament();
    
    Tournament(int finalScore, Player* human, Player* computer);
    
    void start();
    
    void load(int roundCount, vector<string> &roundInfo);
    
private:
    int tournamentScore;
    int roundCount;
    Player* human;
    Player* computer;
    int engineIndex;
    
    inline int getEnginePipForRound(){ return MAX_PIP - (roundCount-1)%MAX_PIP;}
    
    void findWinner();
    
    inline void printWinner(string winner){cout<<"Congratulations! "<<winner<<" has won the tournament !"<<endl;}
    
    void saveToFile(const string &roundInfo);
    
};

#endif /* Tournament_hpp */
