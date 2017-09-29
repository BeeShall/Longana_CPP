//
//  Hand.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Hand.hpp"

/* *********************************************************************
 Function Name: Hand
 Purpose: Constructor for Hand class
 Parameters: vector of Tiles, to set the hand with
 Assistance Received: none
 ********************************************************************* */
Hand::Hand(vector<Tile> tiles){
    this->tiles = tiles;
}

/* *********************************************************************
 Function Name: hasTile
 Purpose: To check for existance of a tile in hand and get its index
 Parameters: Tile to look for
 Return Value: integer, index of the tile, -1 if doesn't exist
 Assistance Received: none
 ********************************************************************* */
int Hand::hasTile(Tile tile){
    for(int i=0; i<tiles.size(); i++){
        if(tiles[i]== tile) return i;
    }
    return -1;
}

/* *********************************************************************
 Function Name: playTile
 Purpose: To remove the tile with given index from hand
 Parameters: index of the tile to remove
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Hand::playTile(int index){
    tiles.erase(tiles.begin()+index);
}

/* *********************************************************************
 Function Name: playTile
 Purpose: To remove the given from hand
 Parameters: Tile to remove
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Hand::playTile(Tile tile){
    for(int i=0; i<tiles.size(); i++){
        if(tiles[i]==tile){
            tiles.erase(tiles.begin()+i);
            return;
        }
    }
}

/* *********************************************************************
 Function Name: getSumofAllPips
 Purpose: To get the sum of all pips from tiles in hand
 Parameters: None
 Return Value: integer, sum of all pips
 Assistance Received: none
 ********************************************************************* */
int Hand::getSumofAllPips(){
    int sum = 0;
    for(int i=0; i<tiles.size(); i++){
        sum += (tiles[i].first+tiles[i].second);
    }
    return sum;
}

/* *********************************************************************
 Function Name: displayHand
 Purpose: To print the hand
 Parameters: stream to print the hand to
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
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
