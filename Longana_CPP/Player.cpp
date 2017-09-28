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
    for(int i =0 ; i < hand->getNumberOfTileInHand(); i++){
        Tile tile =hand->getTile(i);
        if(layout->canTileBePlaced({tile , side})) return true;
        if(passed || isTileDouble(tile)){
            if(layout->canTileBePlaced({tile, otherSide})) return true;
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
    Move returnMove = moves[0];
    cout<<"This move decreases the total sum on the hand by "<<returnMove.first.first + returnMove.first.second<<endl;
    
    if(returnMove.second == ANY){
        cout<<"However, This tile can be placed on either side!"<<endl;
        int leftPlacementScore = getNextMoveScoreAfterPlacement(layout, {returnMove.first,LEFT});
        int rightPlacementScore = getNextMoveScoreAfterPlacement(layout, {returnMove.first,RIGHT});
        if(leftPlacementScore>rightPlacementScore){
            cout<<"If placed on LEFT, the next best move decreases the total sum on the hand by "<<leftPlacementScore<<" rather than placing on the RIGHT which would decrease by "<<rightPlacementScore<<endl;
            returnMove.second = LEFT;
        }
        else if(leftPlacementScore<rightPlacementScore){
           cout<<"If placed on RIGHT, the next best move decreases the total sum on the hand by "<<rightPlacementScore<<" rather than placing on the LEFT which would decrease by "<<leftPlacementScore<<endl;
            returnMove.second = RIGHT;
        }
        else{
          cout<<"The next best move will decreases the total sum on the hand by "<<leftPlacementScore<<" either way, So placing it on the otherSide would create more chances of screwing the opponent over!"<<endl;
            returnMove.second = otherSide;
        }
    }
    return returnMove;
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
                //else set the tile and side to otherside
                else move = {tile,otherSide};
            }
        }
        
        if(move.first.first != -1) moves.push_back(move);
        
    }
    return moves;
}
