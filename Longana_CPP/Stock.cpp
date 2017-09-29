//
//  Stock.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Stock.hpp"

/* *********************************************************************
 Function Name: Hand
 Purpose: Default constructor for Hand class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
Stock::Stock(){
    //generating the stock
    for(int i=0; i<=MAX_PIP; i++){
        for(int j=i; j<=MAX_PIP; j++){
            stock.push_back({i,j});
        }
    }
}

/* *********************************************************************
 Function Name: shuffleStock
 Purpose: To randomly generate the stock
 Parameters: None
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Stock::shuffleStock(){
    auto rng = default_random_engine ((unsigned)time(NULL));
    shuffle(stock.begin(), stock.end(), rng);
}

/* *********************************************************************
 Function Name: generateHand
 Purpose: To generate a new hand from the stock
 Parameters: None
 Return Value: pointer to the newly generated hand
 Assistance Received: none
 ********************************************************************* */
Hand* Stock::generateHand(){
    //return the last 8 tiles from the shuffled stock
    vector<Tile> tiles(stock.end()-HAND_SIZE, stock.end());
    stock.erase(stock.end()-HAND_SIZE, stock.end());
    return new Hand(tiles);
}

/* *********************************************************************
 Function Name: getTileOnTop
 Purpose: To get the tile on top of boneyard
 Parameters: None
 Return Value: Tile, tile on the top of the stock
 Assistance Received: none
 ********************************************************************* */
Tile Stock::getTileOnTop(){
    Tile temp = stock.back();
    stock.pop_back();
    return temp;
}

/* *********************************************************************
 Function Name: displayStock
 Purpose: To print the boneyard
 Parameters: stream to print the hand to
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Stock::displayStock(ostream &os){
    if(stock.empty()) return;
    for(int i=(int)stock.size()-1; i>=0; i--){
        os<<stock[i].first<<"-"<< stock[i].second << " ";
    }
    os<<endl;
}
