//
//  Hand.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include "GlobalImports.h"

class Hand{
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
    Hand();
    
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
    Hand(vector<Tile> tiles);
    
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
    inline int getNumberOfTileInHand() const { return (int)tiles.size();}
    
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
    inline Tile getTile(int index) const { return tiles[index]; }
   
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
    inline void addTile(Tile tile) { tiles.push_back(tile); }
  
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
    inline bool isEmpty() const { return tiles.size() == 0; }
    
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
    int hasTile(Tile tile);
    
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
    void playTile(int index);
    
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
    void playTile(Tile tile);
    
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
    int getSumofAllPips();
    
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
    bool hasDoubles();
    
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
    bool hasPip(int pip);
    
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
    void displayHand(ostream& os);
    
private:
    vector<Tile> tiles;
};
#endif /* Hand_hpp */
