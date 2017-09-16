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
#include <iostream>
using namespace std;

typedef pair<int,int> Tile;

enum Side {LEFT, RIGHT, ENGINE};

enum Move {VALID, INVALID, PASS};

inline bool isTileDouble(Tile tile){ return tile.first == tile.second; };

#endif /* GlobalImports_h */
