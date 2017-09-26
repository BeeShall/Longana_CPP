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
    Layout(Tile tile){
        engine = tile;
        engineSet=false;
    }
    
    Tile getEngine(){
        return engine;
    }
    
    void setEngine(){
        engineSet=true;
    }
    
    void setLayout(vector<Tile> tiles){
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
    
    bool isSideEmpty(Side side){
        if(side == LEFT) return left.size() == 0;
        else if(side == RIGHT) return right.size() == 0;
        else return true;
    }
    
    bool placeTile(Move move){
        if(engineSet){
            if(validateMove(move)){
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
    
    bool canTileBePlaced(Move move){
        if(engineSet){
            if(move.second == LEFT) return checkifTileCanBePlaced(move);
            else if(move.second == RIGHT) return checkifTileCanBePlaced(move);
            else return false;
        }
        else{
            return false;
        }
    }
    
    
    void displayLayout(ostream& os){
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
            cout<<"L   R"<<endl;
        }
        
    }
    
    void resetLayout(){
        left.clear();
        right.clear();
        engineSet = false;
    }
    
private:
    vector<Tile> left;
    vector<Tile> right;
    Tile engine;
    bool engineSet;
    
    //tile sent by reference because might need to switch the first and second based on spot
    
    bool validateMove(Move &move){
        if(isTileDouble(move.first)) return true;
        if(move.second== LEFT){
            return checkifTileCanBePlaced(move);
        }
        else if(move.second == RIGHT) {
            return checkifTileCanBePlaced(move);
        }
        else{
            return false;
        }
        
    }
    
    bool checkifTileCanBePlaced(Move &move){
        if(move.second == LEFT){
            Tile* tile = &move.first;
            Tile temp;
            if(left.size()==0) temp = engine;
            else temp = left.back();
            if(temp.first == tile->first){
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
            if(temp.second == tile->second){
                swap(tile->first,tile->second);
                return true;
            }
            else if(temp.second == tile->first) return true;
        }
        
        return false;
    }
    
    void writeTileToStream(stringstream &line1, stringstream &line2, stringstream &line3, Tile tile){
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
    
    
    
};



#endif /* Layout_hpp */
