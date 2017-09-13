//
//  Longana.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Longana_hpp
#define Longana_hpp

#include "Tournament.hpp"
#include "Computer.hpp"
#include "Human.hpp"
#include <iostream>

class Longana{
public:
    Longana(){
        
    }
    
    ~Longana(){
        reset();
    }
    
    void start(){
        int score;
        cout<<"Please enter a tournament score: ";
        cin>> score;
        cout<<endl;
        human = new Human();
        computer = new Computer();
        tournament = new Tournament(score, human,computer);
        tournament->start();
    }
    
    void reset(){
        delete human;
        delete computer;
        delete tournament;
    }
    
    void restart(){
        reset();
        start();
    }
    
    
private:
    Player* human;
    Player* computer;
    Tournament* tournament;
    
    
    
};

#endif /* Longana_hpp */
