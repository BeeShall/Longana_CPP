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

class Round{
public:
    Round(){
        
    }
    
    Round(Player* human, Player* computer, int enginePip){
        stock = new Stock();
        this->human = (Human*)human;
        this->computer = (Computer*)computer;
        layout = new Layout(Tile(enginePip,enginePip));
        passCount=0;
        turn = false;
        passed = false;
    }
    
    int play(){
        stock->shuffleStock();
        human->setNewHand(stock->generateHand());
        computer->setNewHand(stock->generateHand());
        printRoundState();
        
        determineFirstPlayer();
        
        printRoundState();
        
        //if(turn) getUserMove();
        //else getComputerMove();
        
        getUserMove();
        
        printRoundState();
        
        //game ending conditions
        while(!hasGameEnded()){
            if(turn) getUserMove();
            else getComputerMove();
            cout<<endl;
        }
        cout<<endl;
        cout<<"The round has ended!"<<endl;
        return getRoundScore();
    }
    
    int getRoundScore(){
        int humanTotal = human->getSumofAllPips();
        int computerTotal = computer->getSumofAllPips();
        string winner ="Computer";
        int score = 0;
        if(human->isHandEmpty()){
            winner = human->getName();
            score = computerTotal;
        }
        else if(computer->isHandEmpty()){
            score = humanTotal;
        }
        else if(humanTotal < computerTotal){
            winner = human->getName();
            score = computerTotal;
        }
        else{
            score = humanTotal;
            
        }
        cout<<winner<< " won this round with a score of "<<score<<endl;
        return score;
    }
    
    
private:
    Stock* stock;
    Human* human;
    Computer* computer;
    Layout* layout;
    bool turn;  //true is user, false is computer
    bool passed;
    int passCount;
    
    void determineFirstPlayer(){
        Tile engine = layout->getEngine();
        while(!checkIfPlayerHasEngine(engine)){
            cout<<"No one has the engine yet! Both players draw from the top! "<<endl;
            Tile newTile = stock->getTileOnTop();
            human->addNewTile(newTile);
            cout<<human->getName()<<" drew "<<newTile.first<< " - "<<newTile.second<<endl;
            
            newTile = stock->getTileOnTop();
            computer->addNewTile(newTile);
            cout<<"Computer drew "<<newTile.first<< " - "<<newTile.second<<endl;
        }
        layout->setEngine();
    }
    
    bool checkIfPlayerHasEngine(Tile engine){
        int humanIndex = human->hasTile(engine);
        if(humanIndex>=0){
            cout<<((Human*)human)->getName()<<" has the engine! "<<endl;
            human->play(humanIndex, ENGINE, layout, false);
            turn = false; //human will place and computers turn
            return true;
        }
        else{
            int computerIndex =computer->hasTile(engine);
            if(computerIndex>=0){
                cout<<"Computer has the engine! "<<endl;
                computer->playTile(computerIndex);
                turn = true; //vice versa
                return true;
            }
            else return false;

        }
    }
    
    bool hasGameEnded(){
        if(human->isHandEmpty() || computer->isHandEmpty()) return true;
        if(stock->isEmpty() && passCount >2) return true;
        return false;
    }
    
    
    
    void printRoundState(){
        layout->displayLayout();
        stock->displayStock();
        cout<<"Computer Hand: "<<endl;
        computer->displayHand();
    }
    
    void getUserMove(){
        cout<<endl;
        
        cout<<"Human Hand: "<<endl;
        human->displayHand();
        
        cout<<endl;
        int choice = -1;
        bool hasAlreadyDrawn = false;
        do{
            cout<<"Please make a move using of the following options: "<<endl;
            cout<<"1. Make a move"<<endl;
            cout<<"2. Draw from stock"<<endl;
            cout<<"3. Pass"<<endl;
            cin>>choice;
            
            //chceking if its a valid option for 2 and 3
            if(choice == 2 || choice == 3){
                if(human->hasMoreMoves()) {
                    cout<<"You already have a valid move you can make! Please try again!"<<endl;
                    choice = -1;
                    cout<<endl;
                }
                else if(choice == 2 && hasAlreadyDrawn){
                    cout<<"You already drew on tile! You can only pass now!"<<endl;
                    choice = -1;
                    cout<<endl;
                }
                else{
                    human->addNewTile(stock->getTileOnTop());
                    hasAlreadyDrawn = true;
                    cout<<"Human drew a tile from the stock!"<<endl;
                }
            }
        }while(choice != 1 && choice != 3);
        
        if(choice == 1){
            Move move = INVALID;
            
            do{
                cout<<endl;
                cout<<"Please enter the index of the tile you want to play. (1-8):: ";
                int index;
                cin>>index;
                
                Side s;
                do{
                    cout<<"Please enter which side you want to play (L for left and R for right) :: ";
                    char side;
                    cin>>side;
                    if((side == 'l') || (side == 'L')){
                      s = LEFT;
                        break;
                    }
                    else if ((side == 'R') || (side == 'r')){
                        s = RIGHT;
                        break;
                    }
                }while(true);
                    
                Tile tile = human->getTilefromHand(index);
                cout<<"You chose to play "<<tile.first<<" - "<<tile.second<<" !"<<" Are you sure? (Y for yes / any key for No) :: ";
                char sure;
                cin>>sure;
                if(sure == 'y' || sure == 'Y' ) move = human->play(index, s, layout, passed);
                if(move == INVALID) cout<< "Invalid move played! Try Again!"<<endl;
            }while(move != VALID);
            passCount = 0;
            
        }
        else{
            passed= true;
            passCount++;
        }
        turn = !turn;
    }
    
    void getComputerMove(){
        
        Move move = computer->play(layout, passed);
        if(move == PASS) passed = true;
        else if(move == VALID) cout<<"Computer played "<<computer->getPlayedMove()<<endl;;
        
        
        turn = !turn;
        
    }
};

#endif /* Round_hpp */
