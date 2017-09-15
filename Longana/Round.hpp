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
        
        //game ending conditions
        /*
        while(!stock->isEmpty()){
            
        }
         */
    }
    
    void printRoundState(){
        layout->displayLayout();
        stock->displayStock();
        cout<<"Human Hand: "<<endl;
        human->displayHand();
        cout<<"Computer Hand: "<<endl;
        computer->displayHand();
    }
    
    
private:
    Stock* stock;
    Human* human;
    Computer* computer;
    Layout* layout;
    bool turn;  //true is user, false is computer
    
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
            human->play(humanIndex, ENGINE, layout);
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
};

#endif /* Round_hpp */
