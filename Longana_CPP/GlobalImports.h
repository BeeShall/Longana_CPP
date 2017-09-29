//
//  GlobalImports.h
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef GlobalImports_h
#define GlobalImports_h

#include <vector>
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

//enum to denote sides
enum Side {LEFT, RIGHT, ENGINE, ANY};

//pair for tiles, first meaning left, second meaning right
typedef pair<int,int> Tile;

//pair for a move, first is Tile and second is side
typedef pair<Tile,Side> Move;

//to stringify the sideEnum
inline string getSideString(Side side){
    switch (side) {
        case LEFT:
            return "LEFT";
            break;
        case RIGHT:
            return "RIGHT";
            break;
        default:
            return "ANY";
            break;
    }
}

//indicate the tyep of move made
enum MoveType {VALID, INVALID, PASS};

//checks if the tile is a double
inline bool isTileDouble(Tile tile){ return tile.first == tile.second; };

//validates if the user I\input was a yes
inline bool isChoiceYes(char choice){return (choice == 'y' || choice == 'Y');}

//removes label on the serialized lines imported from file. i.e. remove "xxxx:"
static string removeLabel(string line){
    int index = (int)line.find(':');
    return line.substr(index+2, line.length());
};


#endif /* GlobalImports_h */
