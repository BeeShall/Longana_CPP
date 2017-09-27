//
//  Human.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <stdio.h>
#include "Player.hpp"

class Human:public Player{
public:
    Human();
    
    Human(string name);
    
    inline string getName() {return name;}
    
    MoveType play(int tileIndex, Side side, Layout* layout, bool passed);
    
    Move getHint(Layout* layout, bool passed);
private:
    string name;
    
};

#endif /* Human_hpp */
