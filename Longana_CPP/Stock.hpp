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

#define MAX_PIP 6
#define HAND_SIZE 8

class Stock{
public:
    
    /* *********************************************************************
     Function Name: Hand
     Purpose: Default constructor for Hand class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    Stock();
    
    /* *********************************************************************
     Function Name: setStock
     Purpose: To set the tiles for the stock
     Parameters: vector<Tile> containing the tiles for stock
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    inline void setStock(vector<Tile> tiles) { stock = tiles; };
    
    /* *********************************************************************
     Function Name: isEmpty
     Purpose: To check if the stock is empty
     Parameters: None
     Return Value: boolean indicating whether the stock is empty
     Assistance Received: none
     ********************************************************************* */
    inline bool isEmpty() const { return stock.empty(); }
    
    /* *********************************************************************
     Function Name: shuffleStock
     Purpose: To randomly generate the stock
     Parameters: None
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void shuffleStock();
    
    /* *********************************************************************
     Function Name: generateHand
     Purpose: To generate a new hand from the stock
     Parameters: None
     Return Value: pointer to the newly generated hand
     Assistance Received: none
     ********************************************************************* */
    Hand* generateHand();
    
    /* *********************************************************************
     Function Name: getTileOnTop
     Purpose: To get the tile on top of boneyard
     Parameters: None
     Return Value: Tile, tile on the top of the stock
     Assistance Received: none
     ********************************************************************* */
    Tile getTileOnTop();
    
    /* *********************************************************************
     Function Name: displayStock
     Purpose: To print the boneyard
     Parameters: stream to print the hand to
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void displayStock(ostream &os);
    
private:
    
    //stores the tiles in the stock
    vector<Tile> stock;
    
};

#endif /* Stock_hpp */
