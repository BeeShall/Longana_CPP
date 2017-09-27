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
    Layout(Tile tile);
    
    inline Tile getEngine() const { return engine; }
    
    inline void setEngine(){ engineSet=true; }
    
    void setLayout(vector<Tile> tiles);
    
    bool isSideEmpty(Side side);
    
    bool placeTile(Move move);
    
    bool canTileBePlaced(Move move);
    
    void displayLayout(ostream& os);
    
    void resetLayout();
    
private:
    vector<Tile> left;
    vector<Tile> right;
    Tile engine;
    bool engineSet;
    
    //tile sent by reference because might need to switch the first and second based on spot
    bool validateMove(Move &move);
    
    bool checkifTileCanBePlaced(Move &move);
    
    void writeTileToStream(stringstream &line1, stringstream &line2, stringstream &line3, Tile tile);
};



#endif /* Layout_hpp */
