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
#include "GlobalImports.h"
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
        if(isChoiceYes(choice)) loadNewGame(name);
        else{
            int score;
            cout<<"Please enter a tournament score: ";
            cin>> score;
            cout<<endl;
            init(name,score);
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
    
    void loadNewGame(string playerName){
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
        int tournamentScore = stoi(removeLabel(line));
        
        getline(game, line);
        int roundNo = stoi(removeLabel(line));
        
        vector<string> roundInfo;
        while(getline(game, line)){
            if(line != ""){
                roundInfo.push_back(line);
            }
        }
        init(playerName , tournamentScore);
        
        tournament->load(roundNo, roundInfo);
    }
    
    void init(string name, int score){
        human = new Human(name);
        computer = new Computer();
        tournament = new Tournament(score, human, computer);
    }
    
    
    
};

#endif /* Longana_hpp */
