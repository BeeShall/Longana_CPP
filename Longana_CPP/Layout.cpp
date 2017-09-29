//
//  Layout.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/14/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Layout.hpp"

/* *********************************************************************
 Function Name: Hand
 Purpose: Default constructor for Hand class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
Layout::Layout(){
    engine = {-1,-1};
    engineSet=false;
}

/* *********************************************************************
 Function Name: Hand
 Purpose: Constructor for Hand class
 Parameters: Tile, tile for the engine
 Assistance Received: none
 ********************************************************************* */
Layout::Layout(Tile tile){
    engine = tile;
    engineSet=false;
}

/* *********************************************************************
 Function Name: setLayout
 Purpose: To set the layout with the given tiles
 Parameters: vector<Tiles> to set the layout with
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Layout::setLayout(vector<Tile> tiles){
    //if tiles is empty both are empty
    if(tiles.empty()) return;
    cout<<"Engine: "<<engine.first<< " - "<< engine.second<<endl;
    left.clear();
    int index =0;
    while(tiles[index] != engine){
        left.push_back(tiles[index++]);
    }
    reverse(left.begin(), left.end());
    index++; //skip the engine
    setEngine();
    right.clear();
    while(index<tiles.size()){
        right.push_back(tiles[index++]);
    }
}

/* *********************************************************************
 Function Name: isSideEmpty
 Purpose: To check if the side of the layout is empty
 Parameters: Side, side to check for
 Return Value: boolean, indicating if the side is empty
 Assistance Received: none
 ********************************************************************* */
bool Layout::isSideEmpty(Side side){
    if(side == LEFT) return left.size() == 0;
    else if(side == RIGHT) return right.size() == 0;
    else return true;
}

/* *********************************************************************
 Function Name: placeTile
 Purpose: To place a tile
 Parameters: Move, tile and side to place
 Return Value: boolean, indicating if the tile was placed
 Assistance Received: none
 ********************************************************************* */
bool Layout::placeTile(Move move){
    if(engineSet){
        if(checkifTileCanBePlaced(move)){
            if(move.second == LEFT){
                left.push_back(move.first);
                return true;
            }
            else if(move.second == RIGHT){
                right.push_back(move.first);
                return true;
            }
            else{
                cout<<"Invalid Side"<<endl;
                return false;
            }
        }
        else{
            return false;
        }
        
    }
    else{
        cout<<"The engine hasn't been set yet!"<<endl;
        return false;
    }
}

/* *********************************************************************
 Function Name: removeLastTile
 Purpose: To remove the last tile from the given side
 Parameters: side to remove from
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Layout::removeLastTile(Side side){
    if(side == LEFT && !left.empty()) left.pop_back();
    if(side == RIGHT && !right.empty()) right.pop_back();
}

/* *********************************************************************
 Function Name: canTileBePlaced
 Purpose: To check if the tile can be placed
 Parameters: Move, tile and side to place
 Return Value: boolean, indicating if the tile can be placed
 Assistance Received: none
 ********************************************************************* */
bool Layout::canTileBePlaced(Move move){
    if(engineSet){
        return checkifTileCanBePlaced(move);
    }
    else{
        return false;
    }
}

/* *********************************************************************
 Function Name: displayLayout
 Purpose: To print the layout
 Parameters: stream to print the hand to
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Layout::displayLayout(ostream& os){
    if(engineSet){
        stringstream line1;
        stringstream line2;
        stringstream line3;
        //left side
        if(&os == &cout){
            line1<<"  ";
            line2<<"L ";
            line3<<"  ";
            
        }
        else os<<"L ";
        for(int i = (int)left.size()-1; i>=0; i--){
            if(&os == &cout) writeTileToStream(line1, line2, line3, left[i]);
            else os<<left[i].first<<"-"<< left[i].second << " ";
        }
        
        //engine
        if(&os == &cout) writeTileToStream(line1, line2, line3, engine);
        else os<<engine.first<<"-"<< engine.second << " ";
        
        //right side
        for(int i =0; i<right.size(); i++){
            if(&os == &cout) writeTileToStream(line1, line2, line3, right[i]);
            else os<<right[i].first<<"-"<< right[i].second << " ";
        }
        
        if(&os == &cout){
            line1<<" ";
            line2<<"R";
            line3<<" ";
            
            os<<line1.str()<<endl;
            os<<line2.str()<<endl;
            os<<line3.str()<<endl;
        }
        else os<<"R";
        
        os<<endl;
        
        
    }
    else{
        os<<"L  R"<<endl;
    }
    
}

/* *********************************************************************
 Function Name: resetLayout
 Purpose: To reset the layout
 Parameters: stream None
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Layout::resetLayout(){
    left.clear();
    right.clear();
    engineSet = false;
}

/* *********************************************************************
 Function Name: checkifTileCanBePlaced
 Purpose: To check if the tile can be placed
 Parameters: Move, tile and side to place, sent by reference because tiles might have to be transposed
 Return Value: boolean, indicating if the tile can be placed
 Assistance Received: none
 ********************************************************************* */
bool Layout::checkifTileCanBePlaced(Move &move){
    if(move.second == LEFT){
        Tile* tile = &move.first;
        Tile temp;
        if(left.size()==0) temp = engine;
        else temp = left.back();
        //checking if either pip match
        if(temp.first == tile->first){
            //transposing
            swap(tile->first,tile->second);
            return true;
        }
        else if(temp.first == tile->second) return true;
    }
    else{
        Tile* tile = &move.first;
        Tile temp;
        if(right.size()==0) temp = engine;
        else temp = right.back();
        //checking if either pip match
        if(temp.second == tile->second){
            //transposing
            swap(tile->first,tile->second);
            return true;
        }
        else if(temp.second == tile->first) return true;
    }
    
    return false;
}

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
void Layout::writeTileToStream(stringstream &line1, stringstream &line2, stringstream &line3, Tile tile){
    if(isTileDouble(tile)){
        line1<<tile.first<<" ";
        line2<<"| ";
        line3<<tile.second<<" ";
    }
    else{
        line1<<"    ";
        line2<<tile.first<<"-"<<tile.second<<" ";
        line3<<"    ";
    }
}

