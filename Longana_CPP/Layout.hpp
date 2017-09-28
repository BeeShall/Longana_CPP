//
//  Layout.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/14/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Layout_hpp
#define Layout_hpp

#include "GlobalImports.h"
#import <utility>
#import <sstream>

class Layout{
public:
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    Layout(Tile tile);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    inline Tile getEngine() const { return engine; }
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    inline void setEngine(){ engineSet=true; }
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void setLayout(vector<Tile> tiles);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    bool isSideEmpty(Side side);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    bool placeTile(Move move);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void removeLastTile(Side side);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    bool canTileBePlaced(Move move);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void displayLayout(ostream& os);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void resetLayout();
    
private:
    vector<Tile> left;
    vector<Tile> right;
    Tile engine;
    bool engineSet;
    
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    bool checkifTileCanBePlaced(Move &move);
    
    /* *********************************************************************
     Function Name: compute
     Purpose: To calculate the average grade in a class
     Parameters:
     grades[], an array passed by value. It holds individual grades
     size, an integer. It refers to the number of students in the class
     Return Value: The average grade in the class, a real value
     Local Variables:
     temp[], an integer array used to sort the grades
     Algorithm:
     1) Add all the grades
     2) Divide the sum by the number of students in class to calculate the average
     Assistance Received: none
     ********************************************************************* */
    void writeTileToStream(stringstream &line1, stringstream &line2, stringstream &line3, Tile tile);
};



#endif /* Layout_hpp */
