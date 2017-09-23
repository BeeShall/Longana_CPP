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
    ~Player(){
        delete hand;
    }
    
    void setNewHand(Hand* hand) {
        delete this->hand;
        this->hand = hand;
    }
    
    void setNewHand(vector<Tile> tiles){
        delete hand;
        this->hand = new Hand(tiles);
    }
    
    void addNewTile(Tile tile){
        hand->addTile(tile);
    }
    
    inline int getScore(){
        return score;
    }
    
    Tile getTilefromHand(int index)
    {
        return this->hand->getTile(index-1);
    }
    
    void displayHand(ostream& os){
        hand->displayHand(os);
    }
    
    int hasTile(Tile tile){
        return hand->hasTile(tile);
    }
    
    bool hasMoreMoves(Layout* layout, bool passed){
        if(hand->hasDoubles()) return true;
        for(int i =0 ; i < hand->getNumberOfTileInHand(); i++){
            if(layout->canTileBePlaced({hand->getTile(i), side})) return true;
            if(passed){
                if(layout->canTileBePlaced({hand->getTile(i), otherSide})) return true;
            }
        }
        return false;
    }
    
   bool isHandEmpty(){
        return hand->isEmpty();
    }
    
    int getSumofAllPips(){
        return hand->getSumofAllPips();
    }
    
   void setScore(int score){
        this->score += score;
    }
    
    void setNewScore(int score) { this->score = score;}
    
    
    virtual MoveType play() { return VALID; };
    
protected:
    Hand* hand;
    int score;
    Side side;
    Side otherSide;
    
    void addScore(int score){
        this->score += score;
    }
    
    
    
    //return the tile that'll lower the sum by most (for now)
    Move hint(Layout* layout, bool passed){
        vector<Move> moves = getAllPossibleMoves(layout,  passed);
        
        //if there are no moves that the player can make
        if(moves.size() == 0) return {{-1,-1},ANY};
        
        //sorting such that the ones with higher value come to the front;
        sort(moves.begin(),moves.end(),[](Move a, Move b){
            Tile tileA = a.first;
            Tile tileB = b.first;
            return (tileA.first+tileA.second) > (tileB.first+tileB.second);
        });
        
        //find the first single tile
        for(int i =0; i< moves.size(); i++){
            if(!isTileDouble(moves[i].first)) return moves[i];
        }
        
        //at this point no single tiles available
        //strategy for the double tiles
        //scan through your hand with every single pip from the double,
        //if you have a matching pip in your hand for any of the double
        //return the first matching double
        
        for(int i =0; i<moves.size(); i++){
            if(hand->hasPip(moves[i].first.first)){
                moves[i].second = side;
                return moves[i];
            }
            else{
                moves[i].second = otherSide;
                return moves[i];
            }
        }
        
        return moves[0];
        
        
    }
    
private:
    
    vector<Move> getAllPossibleMoves(Layout* layout, bool passed){
        vector<Move> moves;
        for(int i =0 ; i < hand->getNumberOfTileInHand(); i++){
            Tile tile = hand->getTile(i);
            if(isTileDouble(tile)) moves.push_back({tile,ANY});
            else{
                if(layout->canTileBePlaced({tile, side})) moves.push_back({tile,side});
                else{
                    if(passed && layout->canTileBePlaced({tile, otherSide})) moves.push_back({tile,otherSide});
                }
            }
            
        }
        return moves;
    }
    
    
    
    
    
};

#endif /* Player_hpp */
