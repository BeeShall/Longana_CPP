//
//  Longana.hpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#ifndef Longana_hpp
#define Longana_hpp

#include "Tournament.hpp"
#include "Computer.hpp"
#include "Human.hpp"
#include <iostream>
#include <fstream>

class Longana{
public:
    Longana(){
        
    }
    
    ~Longana(){
        reset();
    }
    
    void start(){
        cout<<"Hi! Welcome to Longana!"<<endl;
        cout<<"Please enter your name: ";
        string name;
        cin>>name;
        
        char choice;
        cout<<"Would you like to load a game? Press y for yes. ";
        cin>>choice;
        cout<<endl;
        if(isChoiceYes(choice)) loadNewGame();
        else{
            int score;
            cout<<"Please enter a tournament score: ";
            cin>> score;
            cout<<endl;
            human = new Human(name);
            computer = new Computer();
            tournament = new Tournament(score, human,computer);
            tournament->start();
        }
    }
    
    void reset(){
        delete human;
        delete computer;
        delete tournament;
    }
    
    void restart(){
        reset();
        start();
    }
    
    
private:
    Player* human;
    Player* computer;
    Tournament* tournament;
    
    void loadNewGame(){
        string name;
        ifstream game;
        do{
            cout<<"Enter the file name of the game you want to load with the extension: ";
            cin>>name;
            name = "/Users/beeshall/Documents/Fall 2018/Longana/" + name;
            
            game.open(name);
        } while(!game.is_open());
        
        string line;
        
        getline(game, line);
        cout<<line<<endl;
        int index = (int)line.find(':');
        int tournamentScore = stoi(line.substr(index+1, line.length()));
        
        getline(game, line);
        index = (int)line.find(':');
        int roundNo = stoi(line.substr(index+1, line.length()));
        
        vector<string> roundInfo;
        while(getline(game, line)){
            if(line != ""){
                roundInfo.push_back(line);
                cout<<line<<endl;
            }
        }
        
        tournament = new Tournament();
        tournament->load(tournamentScore,roundNo, roundInfo);
        
        
        
    }
    
    
    
};

#endif /* Longana_hpp */
