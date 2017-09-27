//
//  Hand.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include "GlobalImports.h"

class Hand{
public:
    Hand();
    
    Hand(vector<Tile> tiles);
    
    inline int getNumberOfTileInHand() const { return (int)tiles.size();}
    
    inline Tile getTile(int index) const { return tiles[index]; }
   
    inline void addTile(Tile tile) { tiles.push_back(tile); }
  
    inline bool isEmpty() const { return tiles.size() == 0; }
    
    int hasTile(Tile tile);
    
    void playTile(int index);
    
    void playTile(Tile tile);
    
    int getSumofAllPips();
    
    bool hasDoubles();
    
    bool hasPip(int pip);
    
    void displayHand(ostream& os);
    
private:
    vector<Tile> tiles;
};
#endif /* Hand_hpp */
