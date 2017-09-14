//
//  Stock.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Stock_hpp
#define Stock_hpp

#include "GlobalImports.h"
#include "Hand.hpp"

class Stock{
public:
    Stock(){
        //generating the stock
        for(int i=0; i<=6; i++){
            for(int j=i; j<=6; j++){
                stock.push_back({i,j});
            }
        }
    }
    
    void shuffleStock(){
        random_shuffle(stock.begin(), stock.end());
    }
    
    Hand* generateHand(){
        vector<Tile> tiles(stock.end()-8, stock.end());
        stock.erase(stock.end()-8, stock.end());
        return new Hand(tiles);
    }
    
    Tile getTile(){
        Tile temp = stock.back();
        stock.pop_back();
        return temp;
    }
    
    void displayStock(){
        cout<<"Current Stock: "<<endl;
        if(stock.empty()) return;
        for(int i=0; i<stock.size(); i++){
            cout<<stock[i].first<<" - "<< stock[i].second << "   ";
        }
        cout<<endl;
    }
    
    bool isEmpty(){
        return stock.size()==0;
    }
    
    
    
private:
    vector<Tile> stock;
    
};

#endif /* Stock_hpp */
