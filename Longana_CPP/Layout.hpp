//
//  Layout.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/14/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Layout_hpp
#define Layout_hpp

#include "GlobalImports.h"
#import <utility>
#import <sstream>

class Layout{
public:
    
    /* *********************************************************************
     Function Name: Hand
     Purpose: Default constructor for Hand class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Layout();
    
    /* *********************************************************************
     Function Name: Hand
     Purpose: Constructor for Hand class
     Parameters: Tile, tile for the engine
     Assistance Received: none
     ********************************************************************* */
    Layout(Tile tile);
    
    /* *********************************************************************
     Function Name: getEngine
     Purpose: To get the engine for the layout/round
     Parameters: None
     Return Value: Tile, the engine for the layout/round
     Assistance Received: none
     ********************************************************************* */
    inline Tile getEngine() const { return engine; }
    
    /* *********************************************************************
     Function Name: setEngine
     Purpose: To set the engine for the layout/round
     Parameters: None
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    inline void setEngine(){ engineSet=true; }
    
    /* *********************************************************************
     Function Name: setLayout
     Purpose: To set the layout with the given tiles
     Parameters: vector<Tiles> to set the layout with
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void setLayout(vector<Tile> tiles);
    
    /* *********************************************************************
     Function Name: isSideEmpty
     Purpose: To check if the side of the layout is empty
     Parameters: Side, side to check for
     Return Value: boolean, indicating if the side is empty
     Assistance Received: none
     ********************************************************************* */
    bool isSideEmpty(Side side);
    
    /* *********************************************************************
     Function Name: placeTile
     Purpose: To place a tile
     Parameters: Move, tile and side to place
     Return Value: boolean, indicating if the tile was placed
     Assistance Received: none
     ********************************************************************* */
    bool placeTile(Move move);
    
    /* *********************************************************************
     Function Name: removeLastTile
     Purpose: To remove the last tile from the given side
     Parameters: side to remove from
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void removeLastTile(Side side);
    
    /* *********************************************************************
     Function Name: canTileBePlaced
     Purpose: To check if the tile can be placed
     Parameters: Move, tile and side to place
     Return Value: boolean, indicating if the tile can be placed
     Assistance Received: none
     ********************************************************************* */
    bool canTileBePlaced(Move move);
    
    /* *********************************************************************
     Function Name: displayLayout
     Purpose: To print the layout
     Parameters: stream to print the hand to
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void displayLayout(ostream& os);
    
    /* *********************************************************************
     Function Name: resetLayout
     Purpose: To reset the layout
     Parameters: stream None
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void resetLayout();
    
private:
    //store tiles on the left to engine
    vector<Tile> left;
    //stores tiles on right to the engine
    vector<Tile> right;
    //store the round engine
    Tile engine;
    //indicates if the engine has been set yet
    bool engineSet;
    
    
    /* *********************************************************************
     Function Name: checkifTileCanBePlaced
     Purpose: To check if the tile can be placed
     Parameters: Move, tile and side to place, sent by reference because tiles might have to be transposed
     Return Value: boolean, indicating if the tile can be placed
     Assistance Received: none
     ********************************************************************* */
    bool checkifTileCanBePlaced(Move &move);
    
    /* *********************************************************************
     Function Name: writeTileToStream
     Purpose: To write tile to stream such that it can be showed in their order in cout
     Parameters:
         stringstream line1: line1 to print on cout
         stringstream line2: line2 to print on cout
         stringstream line3: line3 to print on cout
         Tile tile: tile to be printed to cout
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void writeTileToStream(stringstream &line1, stringstream &line2, stringstream &line3, Tile tile);
};



#endif /* Layout_hpp */
