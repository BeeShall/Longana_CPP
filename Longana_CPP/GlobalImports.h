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

enum Side {LEFT, RIGHT, ENGINE, ANY};

typedef pair<int,int> Tile;
typedef pair<Tile,Side> Move;

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

enum MoveType {VALID, INVALID, PASS};

inline bool isTileDouble(Tile tile){ return tile.first == tile.second; };

inline bool isChoiceYes(char choice){return (choice == 'y' || choice == 'Y');}

static string removeLabel(string line){
    int index = (int)line.find(':');
    return line.substr(index+1, line.length());
};

inline string getTileString(Tile tile){return to_string(tile.first)+"-"+to_string(tile.second); }

#endif /* GlobalImports_h */
