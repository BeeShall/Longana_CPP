//
//  Stock.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Stock.hpp"

Stock::Stock(){
    //generating the stock
    for(int i=0; i<=6; i++){
        for(int j=i; j<=6; j++){
            stock.push_back({i,j});
        }
    }
}

void Stock::setStock(vector<Tile> tiles){
    stock = tiles;
}

void Stock::shuffleStock(){
    auto rng = default_random_engine {};
    shuffle(stock.begin(), stock.end(), rng);
}

Hand* Stock::generateHand(){
    vector<Tile> tiles(stock.end()-8, stock.end());
    stock.erase(stock.end()-8, stock.end());
    return new Hand(tiles);
}

Tile Stock::getTileOnTop(){
    Tile temp = stock.back();
    stock.pop_back();
    return temp;
}

void Stock::displayStock(ostream &os){
    if(stock.empty()) return;
    for(int i=(int)stock.size()-1; i>=0; i--){
        os<<stock[i].first<<"-"<< stock[i].second << " ";
    }
    os<<endl;
}
