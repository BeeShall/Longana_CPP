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
        
    }
    
    bool play(const Layout* layout){
        return true;
    }
    
    void playTile(int tileIndex){
        hand->playTile(tileIndex);
    }
    
private:
    
    
};

#endif /* Computer_hpp */
