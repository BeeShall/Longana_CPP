//
//  Player.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Player.hpp"

/* *********************************************************************
 Function Name: Player
 Purpose: Constructor for the class
 Parameters:None
 Assistance Received: none
 ********************************************************************* */
Player::Player(){
    score = 0;
    hand = new Hand();
}

/* *********************************************************************
 Function Name: ~Player
 Purpose: Destructor for the class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
Player::~Player(){
    delete hand;
}

/* *********************************************************************
 Function Name: getNumberOfTilesInHand
 Purpose: To get the number of tiles in player hand
 Parameters: None
 Return Value: number of tiles in hand, int
 Assistance Received: none
 ********************************************************************* */
int Player::getNumberOfTilesInHand() {
    return hand->getNumberOfTileInHand();
}

/* *********************************************************************
 Function Name: getTilefromHand
 Purpose: To get the tile from player hand with the index
 Parameters: index, the index of the tile, int
 Return Value: Tile for the given index
 Assistance Received: none
 ********************************************************************* */
Tile Player::getTilefromHand(int index) {
    return this->hand->getTile(index-1);
}

/* *********************************************************************
 Function Name: hasTile
 Purpose: To return the index of tile tile, is it exists in hand
 Parameters: Tile to look for
 Return Value: -1 if tile doesn't exist, index if it exists
 Assistance Received: none
 ********************************************************************* */
int Player::hasTile(Tile tile){
    return hand->hasTile(tile);
}

/* *********************************************************************
 Function Name: isHandEmpty
 Purpose: To check if the hand is empty
 Parameters: None
 Return Value: boolean,if hand is empty
 Assistance Received: none
 ********************************************************************* */
bool Player::isHandEmpty() {
    return hand->isEmpty();
}

/* *********************************************************************
 Function Name: getSumofAllPips
 Purpose: To get sum of all pips in hand
 Parameters: None
 Return Value: integer, sum of all pips in hand
 Assistance Received: none
 ********************************************************************* */
int Player::getSumofAllPips() {
    return hand->getSumofAllPips();
}

/* *********************************************************************
 Function Name: setNewHand
 Purpose: To set a new hand for the player with hand object
 Parameters: pointer to Hand object
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Player::setNewHand(Hand* hand) {
    delete this->hand;
    this->hand = hand;
}

/* *********************************************************************
 Function Name: setNewHand
 Purpose: To set a new hand for the player with tiles
 Parameters: vector of tiles for the hand
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Player::setNewHand(vector<Tile> tiles){
    delete hand;
    this->hand = new Hand(tiles);
}

/* *********************************************************************
 Function Name: addNewTile
 Purpose: To add the tile to the player hand
 Parameters: Tile to add
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Player::addNewTile(Tile tile){
    hand->addTile(tile);
}

/* *********************************************************************
 Function Name: displayHand
 Purpose: To print the hand to the stream
 Parameters: stream passed by reference
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
void Player::displayHand(ostream& os){
    hand->displayHand(os);
}

/* *********************************************************************
 Function Name: hasMoreMoves
 Purpose: To calculate the average grade in a class
 Parameters:
 layout: pointer to layout to check for tile placement,
 passed: boolean value indicating if the earlier player had passed
 Return Value: boolean indicating if the player has any moves to play
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: hint
 Purpose: To get the best possible hint given the game state
 Parameters:
 layout: pointer to layout to check for tile placement,
 passed: boolean value indicating if the earlier player had passed
 Return Value: Move containing the hint tile and side
 Local Variables:
 vector<Move> moves, to store the all possible valid moves
 Algorithm:
 1) get all possible valid moves
 2) sort the moves based on their sum (descending order)
 3) get the first tile
 4) if side is any, first place it on your side and record the move you can make after that
 5) then place it on other side and record the move you can make after that
 6) compare the two moves and place the one yielding greater score
 7) if same place it on the other side to screw the other person over
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: getAllPossibleMoves
 Purpose: To get all the possible moves for the given layout
 Parameters:
 layout: pointer to layout to check for tile placement,
 passed: boolean value indicating if the earlier player had passed
 Return Value: vector<Move>, all the moves that the can be played
 Local Variables: vector<Move> moves, to sotre the moves
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: getNextMoveScoreAfterPlacement
 Purpose: To get the score of the next best move after making the given move
 Parameters:
 layout: pointer to layout to check for tile placement,
 move: Move, move to make
 Return Value: int, sum of the pip of the best tile yielded after making the move
 Local Variables: vector<Move> moves, to sotre the possible moves
 returnVal: to store the best value to return
 Assistance Received: none
 ********************************************************************* */
int Player::getNextMoveScoreAfterPlacement(Layout* layout, Move move){
    //default value if no possible moves is 0
    int returnVal = 0;
    //place the move
    layout->placeTile(move);
    //get all possible moves
    vector<Move> moves = getAllPossibleMoves(layout, false);
    if(!moves.empty()){
        Tile bestTile;
        //since the current move is still in hand, checking if the move we got is the current move
        if(moves[0].first != move.first) returnVal = moves[0].first.first + moves[0].first.second;
        else{
            if(moves.size() > 1) returnVal = moves[1].first.first + moves[1].first.second;
        }
        //remove to tile placed, to restore the layout
        layout->removeLastTile(move.second);
    }
    return returnVal;
}
