//
//  Player.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "GlobalImports.h"
#include "Hand.hpp"
#include "Layout.hpp"

class Player{
public:
    Player(){
        score = 0;
        hand = new Hand();
    }
    
    void setNewHand(Hand* hand) {
        delete this->hand;
        this->hand = hand;
        movesOver = false;
    }
    
    void addNewTile(Tile tile){
        hand->addTile(tile);
    }
    
    int getScore(){
        return score;
    }
    
    Tile getTilefromHand(int index)
    {
        return this->hand->getTile(index-1);
    }
    
    void displayHand(){
        hand->displayHand();
    }
    
    int hasTile(Tile tile){
        return hand->hasTile(tile);
    }
    
    bool hasMoreMoves(){
        return movesOver;
    }
    
    bool isHandEmpty(){
        return hand->isEmpty();
    }
    
    int getSumofAllPips(){
        return hand->getSumofAllPips();
    }
    
    
    
    virtual Move play() { return VALID; };
    
protected:
    Hand* hand;
    int score;
    bool movesOver;
    
    void addScore(int score){
        this->score += score;
    }
    
    Tile hint(const Layout* layout) const{
        
        // TO:DO AI Logic
        
        return Tile(-1,-1);
    }
    
    
};

#endif /* Player_hpp */
