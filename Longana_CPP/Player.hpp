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
    Player();
    
    ~Player();
    
    int getNumberOfTilesInHand() const;
    
    inline int getScore() const { return score; }
    
    Tile getTilefromHand(int index) const;
    
    int hasTile(Tile tile) const;
    
    bool isHandEmpty() const;
    
    int getSumofAllPips() const ;
    
    void setNewHand(Hand* hand);
    
    void setNewHand(vector<Tile> tiles);
    
    inline void setScore(int score){ this->score += score; }
    
    inline void setNewScore(int score) { this->score = score;}
    
    void addNewTile(Tile tile);
    
    void displayHand(ostream& os);

    bool hasMoreMoves(Layout* layout, bool passed);
    
    virtual MoveType play() { return VALID; };
    
protected:
    Hand* hand;
    int score;
    Side side;
    Side otherSide;
    
    Move hint(Layout* layout, bool passed);
    
private:
    vector<Move> getAllPossibleMoves(Layout* layout, bool passed);

};

#endif /* Player_hpp */
