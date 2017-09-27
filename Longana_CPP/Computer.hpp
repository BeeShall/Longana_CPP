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
    Computer();
    
    inline string getPlayedMove() const{ return playedMove; }
    
    MoveType play(Layout* layout, bool passed);
    
    void playTile(int tileIndex);
    
private:
    string playedMove;
    
};

#endif /* Computer_hpp */
