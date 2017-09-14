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
    Hand(){
        
    }
    
    Hand(vector<Tile> tiles){
        this->tiles = tiles;
    }
    
    inline void addTile(Tile tile) { tiles.push_back(tile); }
    
    void displayHand(){
        if(tiles.empty()){
            return;
        }
        for(int i=0; i<tiles.size(); i++){
            cout<<tiles[i].first<<" - "<< tiles[i].second << "   ";
        }
        cout<<endl;
    }
    
    Tile getTile(int index){
       return tiles[index];
    }
    
    void playTile(int index){
        tiles.erase(tiles.begin()+index);
    }
    
private:
    vector<Tile> tiles;
};
#endif /* Hand_hpp */
