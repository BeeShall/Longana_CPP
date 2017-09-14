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

class Layout{
public:
    Layout(){
        engineSet=false;
    }
    
    void setEngine(){
        engineSet=true;
    }
    
    void placeTile(Tile tile, Side side){
        if(engineSet){
        if(side == LEFT) left.push_back(tile);
        else if(side == RIGHT) right.push_back(tile);
        else cout<<"Invalid Side"<<endl;
        }
        else{
            cout<<"The engine hasn't been set yet!"<<endl;
        }
    }
    
    void displayLayout(){
        cout<<"Current Layout: "<<endl;
        if(engineSet){
            //left side
            cout<<"L ";
            for(auto it = left.end(); it != left.begin(); it--){
                cout<<it->first<<" - "<< it->second << "   ";
            }
            
            //engine
            cout<<"6 - 6"<< " ";
            
            //right side
            cout<<"R";
            for(auto it = left.begin(); it != left.end(); it++){
                cout<<it->first<<" - "<< it->second << "   ";
            }
            
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
    bool engineSet;
    
};



#endif /* Layout_hpp */
