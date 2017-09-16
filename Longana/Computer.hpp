//
//  Computer.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp

#include <stdio.h>
#include "Player.hpp"

class Computer : public Player{
public:
    Computer(){
        playedMove = "";
        
    }
    
    Move play(const Layout* layout, bool passed){
        
        //print computer played what on which side
        return VALID;
    }
    
    void playTile(int tileIndex){
        hand->playTile(tileIndex);
    }
    
    string getPlayedMove(){
        return playedMove;
    }
    
private:
    string playedMove;
    
};

#endif /* Computer_hpp */
