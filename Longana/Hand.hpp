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
    
    inline int getNumberOfTileInHand() { return tiles.size();}
    
    Tile getTile(int index){
        return tiles[index];
    }
    
    void displayHand(){
        if(tiles.empty()){
            return;
        }
        for(int i=0; i<tiles.size(); i++){
            cout<<tiles[i].first<<" - "<< tiles[i].second << "   ";
        }
        cout<<endl;
    }
    
  
    int hasTile(Tile tile){
        for(int i=0; i<tiles.size(); i++){
            if(tiles[i]== tile) return i;
        }
        return -1;
    }
    
    
    void playTile(int index){
        tiles.erase(tiles.begin()+index);
    }
    
    bool isEmpty(){
        return tiles.size() == 0;
    }
    
    int getSumofAllPips(){
        int sum = 0;
        for(int i=0; i<tiles.size(); i++){
            sum += (tiles[i].first+tiles[i].second);
        }
        return sum;
    }
    
    bool hasDoubles(){
        for(int i =0; i<tiles.size(); i++){
            if(isTileDouble(tiles[i])) return true;
        }
        return false;
    }
private:
    vector<Tile> tiles;
};
#endif /* Hand_hpp */
