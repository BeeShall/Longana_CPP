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
#include <algorithm>
#include <random>

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
    
    void setStock(vector<Tile> tiles){
        stock = tiles;
    }
    
    void shuffleStock(){
        auto rng = default_random_engine {};
        shuffle(stock.begin(), stock.end(), rng);
    }
    
    Hand* generateHand(){
        vector<Tile> tiles(stock.end()-8, stock.end());
        stock.erase(stock.end()-8, stock.end());
        return new Hand(tiles);
    }
    
    Tile getTileOnTop(){
        Tile temp = stock.back();
        stock.pop_back();
        return temp;
    }
    
    void displayStock(ostream &os){
        if(stock.empty()) return;
        for(int i=0; i<stock.size(); i++){
            os<<stock[i].first<<"-"<< stock[i].second << " ";
        }
        os<<endl;
    }
    
    bool isEmpty(){
        return stock.size()==0;
    }
    
    
    
private:
    vector<Tile> stock;
    
};

#endif /* Stock_hpp */