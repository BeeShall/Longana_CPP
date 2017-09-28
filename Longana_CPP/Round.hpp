//
//  Round.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Round_hpp
#define Round_hpp

#include <stdio.h>
#include "Stock.hpp"
#include "Human.hpp"
#include "Computer.hpp"
#include "Layout.hpp"
#include <sstream>

class Round{
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
    Round();
    
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
    Round(Player* human, Player* computer, int enginePip);
    
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
    ~Round();
    
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
    inline bool isSaveAndQuit() const { return saveAndQuit; }
    
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
    void play();
    
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
    void load(vector<string> roundInfo);
    
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
    string getSerielizedRoundInfo();
    
    
private:
    Stock* stock;
    Human* human;
    Computer* computer;
    Layout* layout;
    bool turn;  //true is user, false is computer
    bool passed;
    int passCount;
    bool saveAndQuit;
    
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
    bool checkIfPlayerHasEngine(Tile engine);
    
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
    void determineFirstPlayer();
    
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
    void start();
    
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
    vector<Tile> parsePips(string pips);
    
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
    bool hasGameEnded();
    
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
    void printRoundState();
    
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
    void getUserMove();
    
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
    void getComputerMove();
    
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
    void getRoundScore();
  
};

#endif /* Round_hpp */
