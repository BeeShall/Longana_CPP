//
//  Hand.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Hand.hpp"

Hand::Hand(){
    
}

Hand::Hand(vector<Tile> tiles){
    this->tiles = tiles;
}

void Hand::playTile(int index){
    tiles.erase(tiles.begin()+index);
}

void Hand::playTile(Tile tile){
    for(int i=0; i<tiles.size(); i++){
        if(tiles[i]==tile){
            tiles.erase(tiles.begin()+i);
            return;
        }
    }
}

int Hand::hasTile(Tile tile){
    for(int i=0; i<tiles.size(); i++){
        if(tiles[i]== tile) return i;
    }
    return -1;
}

int Hand::getSumofAllPips(){
    int sum = 0;
    for(int i=0; i<tiles.size(); i++){
        sum += (tiles[i].first+tiles[i].second);
    }
    return sum;
}

bool Hand::hasDoubles(){
    for(int i =0; i<tiles.size(); i++){
        if(isTileDouble(tiles[i])) return true;
    }
    return false;
}

bool Hand::hasPip(int pip){
    for(int i =0; i<tiles.size(); i++ ){
        if(tiles[i].first == pip || tiles[i].second == pip) return true;
    }
    return false;
}

void Hand::displayHand(ostream& os){
    if(tiles.empty()){
        return;
    }
    for(int i=0; i<tiles.size(); i++){
        if(&os == &cout) cout<<"("<<i+1<<") ";
        os<<tiles[i].first<<"-"<< tiles[i].second << " ";
    }
    os<<endl;
}
