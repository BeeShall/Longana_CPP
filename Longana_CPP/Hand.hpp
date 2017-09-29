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
    /* *********************************************************************
     Function Name: Hand
     Purpose: Default constructor for Hand class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Hand(){};
    
    /* *********************************************************************
     Function Name: Hand
     Purpose: Constructor for Hand class
     Parameters: vector of Tiles, to set the hand with
     Assistance Received: none
     ********************************************************************* */
    Hand(vector<Tile> tiles);
    
    /* *********************************************************************
     Function Name: getNumberOfTileInHand
     Purpose: To get the number of tiles in hand
     Parameters: None
     Return Value: integer, number of tiles in hand
     Assistance Received: none
     ********************************************************************* */
    inline int getNumberOfTileInHand() const { return (int)tiles.size();}
    
    /* *********************************************************************
     Function Name: getTile
     Purpose: To get the tile in hand with the given index
     Parameters: index, integer, to get the tile at
     Return Value: Tile, at the given index
     Assistance Received: none
     ********************************************************************* */
    inline Tile getTile(int index) const { return tiles[index]; }
   
    /* *********************************************************************
     Function Name: addTile
     Purpose: To ass a tile to hand
     Parameters: Tile to be added
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    inline void addTile(Tile tile) { tiles.push_back(tile); }
  
    /* *********************************************************************
     Function Name: isEmpty
     Purpose: To check if hand is empty
     Parameters: None
     Return Value: boolean, representing whether the hand is empty
     Assistance Received: none
     ********************************************************************* */
    inline bool isEmpty() const { return tiles.empty(); }
    
    /* *********************************************************************
     Function Name: hasTile
     Purpose: To check for existance of a tile in hand and get its index
     Parameters: Tile to look for
     Return Value: integer, index of the tile, -1 if doesn't exist
     Assistance Received: none
     ********************************************************************* */
    int hasTile(Tile tile);
    
    /* *********************************************************************
     Function Name: playTile
     Purpose: To remove the tile with given index from hand
     Parameters: index of the tile to remove
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void playTile(int index);
    
    /* *********************************************************************
     Function Name: playTile
     Purpose: To remove the given from hand
     Parameters: Tile to remove
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void playTile(Tile tile);
    
    /* *********************************************************************
     Function Name: getSumofAllPips
     Purpose: To get the sum of all pips from tiles in hand
     Parameters: None
     Return Value: integer, sum of all pips
     Assistance Received: none
     ********************************************************************* */
    int getSumofAllPips();
    
    /* *********************************************************************
     Function Name: displayHand
     Purpose: To print the hand
     Parameters: stream to print the hand to
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void displayHand(ostream& os);
    
private:
    //store the tiles in hand
    vector<Tile> tiles;
};
#endif /* Hand_hpp */
