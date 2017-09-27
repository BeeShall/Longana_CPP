//
//  Stock.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Stock_hpp
#define Stock_hpp

#include "GlobalImports.h"
#include "Hand.hpp"
#include <algorithm>
#include <random>

class Stock{
public:
    Stock();
    
    void setStock(vector<Tile> tiles);
    
    inline bool isEmpty() const { return stock.size()==0; }
    
    void shuffleStock();
    
    Hand* generateHand();
    
    Tile getTileOnTop();
    
    void displayStock(ostream &os);
    
private:
    vector<Tile> stock;
    
};

#endif /* Stock_hpp */
