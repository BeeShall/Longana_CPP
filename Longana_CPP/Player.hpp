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

#define EMPTY_MOVE {{-1,-1}, ANY}



class Player{
public:
    /* *********************************************************************
     Function Name: Player
     Purpose: Constructor for the class
     Parameters:None
     Assistance Received: none
     ********************************************************************* */
    Player();
    
    /* *********************************************************************
     Function Name: ~Player
     Purpose: Destructor for the class
     Parameters: None
     Assistance Received: none
     ********************************************************************* */
    ~Player();
    
    /* *********************************************************************
     Function Name: getNumberOfTilesInHand
     Purpose: To get the number of tiles in player hand
     Parameters: None
     Return Value: number of tiles in hand, int
     Assistance Received: none
     ********************************************************************* */
    int getNumberOfTilesInHand();
    
    /* *********************************************************************
     Function Name: getScore
     Purpose: To get the score of the player
     Parameters: None
     Return Value: score for the player, int
     Assistance Received: none
     ********************************************************************* */
    inline int getScore() const { return score; }
    
    /* *********************************************************************
     Function Name: getTilefromHand
     Purpose: To get the tile from player hand with the index
     Parameters: index, the index of the tile, int
     Return Value: Tile for the given index
     Assistance Received: none
     ********************************************************************* */
    Tile getTilefromHand(int index);
    
    /* *********************************************************************
     Function Name: hasTile
     Purpose: To return the index of tile tile, is it exists in hand
     Parameters: Tile to look for
     Return Value: -1 if tile doesn't exist, index if it exists
     Assistance Received: none
     ********************************************************************* */
    int hasTile(Tile tile);
    
    /* *********************************************************************
     Function Name: isHandEmpty
     Purpose: To check if the hand is empty
     Parameters: None
     Return Value: boolean,if hand is empty
     Assistance Received: none
     ********************************************************************* */
    bool isHandEmpty();
    
    /* *********************************************************************
     Function Name: getSumofAllPips
     Purpose: To get sum of all pips in hand
     Parameters: None
     Return Value: integer, sum of all pips in hand
     Assistance Received: none
     ********************************************************************* */
    int getSumofAllPips();
    
    /* *********************************************************************
     Function Name: setNewHand
     Purpose: To set a new hand for the player with hand object
     Parameters: pointer to Hand object
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void setNewHand(Hand* hand);
    
    /* *********************************************************************
     Function Name: setNewHand
     Purpose: To set a new hand for the player with tiles
     Parameters: vector of tiles for the hand
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void setNewHand(vector<Tile> tiles);
    
    /* *********************************************************************
     Function Name: setScore
     Purpose: To set score for the round, adds score to the existing
     Parameters: score to set, integer
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    inline void setScore(int score){ this->score += score; }
    
    /* *********************************************************************
     Function Name: setNewScore
     Purpose: To set new score for the player, replaces the exisitng
     Parameters: socre to set, integer
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    inline void setNewScore(int score) { this->score = score;}
    
    /* *********************************************************************
     Function Name: addNewTile
     Purpose: To add the tile to the player hand
     Parameters: Tile to add
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void addNewTile(Tile tile);
    
    /* *********************************************************************
     Function Name: displayHand
     Purpose: To print the hand to the stream
     Parameters: stream passed by reference
     Return Value: None
     Assistance Received: none
     ********************************************************************* */
    void displayHand(ostream& os);

    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
         layout: pointer to layout to check for tile placement,
         passed: boolean value indicating if the earlier player had passed
     Return Value: boolean indicating if the player has any moves to play
     Assistance Received: none
     ********************************************************************* */
    bool hasMoreMoves(Layout* layout, bool passed);
    
    /* *********************************************************************
     Function Name: play
     Purpose: To play and make the move for the player
     Parameters: None
     Return Value: MoveType indicating if the played move is valid. invalid
     Assistance Received: none
     ********************************************************************* */
    virtual MoveType play() { return VALID; };
    
protected:
    Hand* hand;
    int score;
    Side side;
    Side otherSide;
    
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
         3) return the first single tile
         4) If no single, place the first double tile which has a matching single tile from hand with the same pip
         5) If there is no such tile, place the first double tile on the other side
     Assistance Received: none
     ********************************************************************* */
    Move hint(Layout* layout, bool passed);
    
private:
    
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
    vector<Move> getAllPossibleMoves(Layout* layout, bool passed);
    
    int getNextMoveScoreAfterPlacement(Layout* layout, Move move){
        int returnVal = 0;
        layout->placeTile(move);
        vector<Move> moves = getAllPossibleMoves(layout, false);
        if(!moves.empty()){
            Tile bestTile;
            if(moves[0].first != move.first) returnVal = moves[0].first.first + moves[0].first.second;
            else{
                if(moves.size() > 1) returnVal = moves[1].first.first + moves[1].first.second;
            }
            layout->removeLastTile(move.second);
        }
        return returnVal;
    }

};

#endif /* Player_hpp */
