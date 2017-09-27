//
//  Player.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Player.hpp"
Player::Player(){
    score = 0;
    hand = new Hand();
}
Player::~Player(){
    delete hand;
}

int Player::getNumberOfTilesInHand() const{
    return hand->getNumberOfTileInHand();
}

Tile Player::getTilefromHand(int index) const {
    return this->hand->getTile(index-1);
}

int Player::hasTile(Tile tile) const{
    return hand->hasTile(tile);
}

bool Player::isHandEmpty() const {
    return hand->isEmpty();
}

int Player::getSumofAllPips() const {
    return hand->getSumofAllPips();
}

void Player::setNewHand(Hand* hand) {
    delete this->hand;
    this->hand = hand;
}

void Player::setNewHand(vector<Tile> tiles){
    delete hand;
    this->hand = new Hand(tiles);
}

void Player::addNewTile(Tile tile){
    hand->addTile(tile);
}

void Player::displayHand(ostream& os){
    hand->displayHand(os);
}

bool Player::hasMoreMoves(Layout* layout, bool passed){
    if(hand->hasDoubles()) return true;
    for(int i =0 ; i < hand->getNumberOfTileInHand(); i++){
        if(layout->canTileBePlaced({hand->getTile(i), side})) return true;
        if(passed){
            if(layout->canTileBePlaced({hand->getTile(i), otherSide})) return true;
        }
    }
    return false;
}

//return the tile that'll lower the sum by most
Move Player::hint(Layout* layout, bool passed){
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
    }
    
    //play the double with highest heuristic but on the other side
    moves[0].second = otherSide;
    return moves[0];
}

vector<Move> Player::getAllPossibleMoves(Layout* layout, bool passed){
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
