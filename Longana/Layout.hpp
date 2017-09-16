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
    
    //need to implement validation of tiles better
    bool placeTile(Tile tile, Side side){
        if(engineSet){
            if(validateMove(tile, side)){
                if(side == LEFT){
                    left.push_back(tile);
                    return true;
                }
                else if(side == RIGHT){
                   right.push_back(tile);
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
    
    
    void displayLayout(){
        cout<<"Current Layout: "<<endl;
        if(engineSet){
            //left side
            cout<<"L ";
            for(int i = left.size()-1; i>=0; i--){
                cout<<left[i].first<<" - "<< left[i].second << "   ";
            }
            
            //engine
            cout<<engine.first<<" - "<< engine.second << "   ";
            
            //right side
            for(int i =0; i<right.size(); i++){
                cout<<right[i].first<<" - "<< right[i].second << "   ";
            }
            
            
            cout<<"R";
            
            cout<<endl;
            
            
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
    bool validateMove(Tile &tile, Side side){
        if(isTileDouble(tile)) return true;
        if(side== LEFT){
            Tile temp;
            if(left.size()==0) temp = engine;
            else temp = left.back();
            if(temp.first == tile.first){
                swap(tile.first,tile.second);
                return true;
            }
            else if(temp.first == tile.second) return true;
            else return false;
        }
        else if(side == RIGHT) {
            Tile temp;
            if(right.size()==0) temp = engine;
            else temp = right.back();
            if(temp.second == tile.second){
                swap(tile.first,tile.second);
                return true;
            }
            else if(temp.second == tile.first) return true;
            else return false;
        }
        else{
            return false;
        }
        
    }
    
    
};



#endif /* Layout_hpp */
