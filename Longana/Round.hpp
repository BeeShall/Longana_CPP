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
    }
    
    void start(){
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
        /*
        while(!stock->isEmpty()){
            
        }
         */
    }
    
    
private:
    Stock* stock;
    Human* human;
    Computer* computer;
    Layout* layout;
    bool turn;  //true is user, false is computer
    bool passed; 
    
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
        do{
            cout<<"Please make a move using of the following options: "<<endl;
            cout<<"1. Make a move"<<endl;
            cout<<"2. Pass"<<endl;
            cin>>choice;
        }while(choice != 1 && choice != 2);
        
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
            
        }
        else{
            passed = true;
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
