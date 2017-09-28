//
//  Tournament.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Tournament_hpp
#define Tournament_hpp

#include "GlobalImports.h"
#include "Round.hpp"
#include "Player.hpp"
#include <fstream>

#define MAX_PIP 6

class Tournament{
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
    Tournament();
    
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
    Tournament(int finalScore, Player* human, Player* computer);
    
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
    void load(int roundCount, vector<string> &roundInfo);
    
private:
    int tournamentScore;
    int roundCount;
    Player* human;
    Player* computer;
    int engineIndex;
    
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
    inline int getEnginePipForRound(){ return MAX_PIP - (roundCount-1)%MAX_PIP;}
    
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
    void findWinner();
    
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
    inline void printWinner(string winner){cout<<"Congratulations! "<<winner<<" has won the tournament !"<<endl;}
    
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
    void saveToFile(const string &roundInfo);
    
};

#endif /* Tournament_hpp */
