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

int Player::getNumberOfTilesInHand() {
    return hand->getNumberOfTileInHand();
}

Tile Player::getTilefromHand(int index) {
    return this->hand->getTile(index-1);
}

int Player::hasTile(Tile tile){
    return hand->hasTile(tile);
}

bool Player::isHandEmpty() {
    return hand->isEmpty();
}

int Player::getSumofAllPips() {
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
    cout<<"-----------------------------"<<endl;
    cout<<"Strategy:"<<endl;
    
    //find the first single tile
    //what to do if you the side is ANY
    //if side is any, first place it on your side and record the move you can make after that
    //then place it on other side and record the move you can make after that
    //compare the two moves and place the one yielding greater score
    //if same place it on the other side to screw the other person over
    for(int i =0; i< moves.size(); i++){
        if(!isTileDouble(moves[i].first)){
            
            return moves[i];
        }
    }
    
    for(int i =0; i< moves.size(); i++){
        if(moves[i].second == ANY){
            
        }
        else{
            cout<<"This move decreases the total sum on the hand by "<<moves[i].first.first+moves[i].first.second<<endl;
            return moves[i];
        }
    }
    
    
    //at this point no single tiles available
    //strategy for the double tiles
    //scan through your hand with every single pip from the double,
    //if you have a matching pip in your hand for any of the double
    //return the first matching double
    
    cout<<"There are no single tiles that can be placed! So we look for doubles now!"<<endl;
    
    for(int i =0; i<moves.size(); i++){
        if(hand->hasPip(moves[i].first.first)){
            moves[i].second = side;
            cout<<"The hand has a tile that can be placed after this double has been placed!"<<endl;
            return moves[i];
        }
    }
    
    //play the double with highest heuristic but on the other side
    moves[0].second = otherSide;
    cout<<"There are no tiles that can be played in our favor. So, we play the largest sum yielding pip on the other side! "<<endl;
    return moves[0];
}

vector<Move> Player::getAllPossibleMoves(Layout* layout, bool passed){
    vector<Move> moves;
    for(int i =0 ; i < hand->getNumberOfTileInHand(); i++){
        Tile tile = hand->getTile(i);
        
        //for doubles or single, send which side can it be placed, left right or any
        Move move = EMPTY_MOVE;
        //if the move can be placed on the side, then set it
        if(layout->canTileBePlaced({tile, side})) move = {tile,side};
        //if its passed or double you can put on the other side if its valid
        if(passed || isTileDouble(tile)){
            //if its valid
            if(layout->canTileBePlaced({tile, otherSide})){
                //if it can already be placed on the side, set the side a any
                if(move.second == side) move.second = ANY;
                //else set the side to otherside
                else move.second = otherSide;
            }
        }
        
    }
    return moves;
}
