//
//  Round.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Round.hpp"

Round::Round(){
    stock = NULL;
    human = NULL;
    computer = NULL;
    layout = NULL;
    passCount=0;
    turn = false;
    passed = false;
    saveAndQuit = false;
}

Round::Round(Player* human, Player* computer, int enginePip){
    stock = new Stock();
    this->human = (Human*)human;
    this->computer = (Computer*)computer;
    layout = new Layout(Tile(enginePip,enginePip));
    passCount=0;
    turn = false;
    passed = false;
    saveAndQuit = false;
}

Round::~Round(){
    delete stock;
    delete layout;
}

void Round::play(){
    stock->shuffleStock();
    human->setNewHand(stock->generateHand());
    computer->setNewHand(stock->generateHand());
    printRoundState();
    
    determineFirstPlayer();
    
    start();
    
    getRoundScore();
    
    
}

void Round::load(vector<string> roundInfo){
    //computer
    vector<Tile> computerHand = parsePips(removeLabel(roundInfo[1])); //hand
    computer->setNewHand(computerHand);
    computer->setNewScore(stoi(removeLabel(roundInfo[2]))); //score
    
    //human
    vector<Tile> humanHand = parsePips(removeLabel(roundInfo[4])); //hand
    human->setNewHand(humanHand);
    human->setNewScore(stoi(removeLabel(roundInfo[5])));//score
    
    //layout
    int leftIndex = (int)roundInfo[7].find('L')+2; //omitting the L and space
    int rightIndex = (int)roundInfo[7].find('R')-1; //omitting the space
    vector<Tile> layoutTiles = parsePips(roundInfo[7].substr(leftIndex,rightIndex-leftIndex));
    layout->setLayout(layoutTiles);
    
    vector<Tile> stockTiles = parsePips(roundInfo[9]); //stock
    stock->setStock(stockTiles);
    
    if((removeLabel(roundInfo[10])).compare("Yes") == 0) passed= true;
    else passed = false;
    
    if((removeLabel(roundInfo[11])).compare("Human") == 0) turn = true; //turn
    else turn = false;
    
    start();
    
    getRoundScore();
    
    
}

void Round::getRoundScore(){
    int humanTotal = human->getSumofAllPips();
    int computerTotal = computer->getSumofAllPips();
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Computer Score: "<<computerTotal<<endl;
    cout<< human->getName()<<"'s Score: "<<humanTotal<<endl;
    string winner ="Computer";
    int score = 0;
    if(human->isHandEmpty()){
        winner = human->getName();
        score = computerTotal;
        human->setScore(score);
    }
    else if(computer->isHandEmpty()){
        score = humanTotal;
        computer->setScore(score);
    }
    else if(humanTotal < computerTotal){
        winner = human->getName();
        score = computerTotal;
        human->setScore(score);
    }
    else if (humanTotal > computerTotal){
        score = humanTotal;
    }
    else{
        cout<<"The round ended with a draw!"<<endl;
        return;
    }
    cout<<winner<< " won this round with a score of "<<score<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;
}

string Round::getSerielizedRoundInfo(){
    ostringstream ss;
    ss<<"Computer:"<<endl;
    ss<<"\t Hand: ";
    computer->displayHand(ss);
    ss<<"\t Score: "<<computer->getScore()<<endl;
    ss<<endl;
    
    ss<<"Human:"<<endl;
    ss<<"\t Hand: ";
    human->displayHand(ss);
    ss<<"\t Score: "<<human->getScore()<<endl;
    ss<<endl;
    
    ss<<"Layout: "<<endl;
    layout->displayLayout(ss);
    ss<<endl;
    
    ss<<"Boneyard: "<<endl;
    stock->displayStock(ss);
    ss<<endl;
    
    ss<<"Previous Player Passed: ";
    if(passed) ss<<"Yes";
    else ss<<"No";
    
    ss<<endl;
    ss<<endl;
    
    ss<<"Next Player: ";
    if(turn) ss<<"Human";
    else ss<<"Computer";
    
    return ss.str();
}


bool Round::checkIfPlayerHasEngine(Tile engine){
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

void Round::determineFirstPlayer(){
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

void Round::start(){
    printRoundState();
    //game ending conditions
    while(!hasGameEnded()){
        if(turn) getUserMove();
        else getComputerMove();
        if(saveAndQuit) return;
        printRoundState();
    }
    cout<<endl;
    cout<<"The round has ended!"<<endl;
}

vector<Tile> Round::parsePips(string pips){
    vector<Tile> tiles;
    istringstream iss(pips);
    string tileStr = "";
    while(iss>>tileStr){
        tiles.push_back({atoi(&tileStr[0]), atoi(&tileStr[2])});
    }
    return tiles;
}

bool Round::hasGameEnded(){
    if(human->isHandEmpty() || computer->isHandEmpty()) return true;
    if(stock->isEmpty() && passCount >2) return true;
    return false;
}

void Round::printRoundState(){
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Current Layout:"<<endl;
    layout->displayLayout(cout);
    
    cout<<"Current Stock:"<<endl;
    stock->displayStock(cout);
    cout<<"----------------------------------"<<endl;
    cout<<endl;
}

void Round::getUserMove(){
    cout<<endl;
    
    cout<<"Human Hand: "<<endl;
    human->displayHand(cout);
    
    cout<<endl;
    int choice = -1;
    bool hasAlreadyDrawn = false;
    do{
        cout<<"Please make a move using of the following options: "<<endl;
        cout<<"1. Make a move"<<endl;
        cout<<"2. Draw from stock"<<endl;
        cout<<"3. Pass"<<endl;
        cout<<"4. Hint Please???"<<endl;
        cout<<"5. Save and quit"<<endl;
        cin>>choice;
        
        if(choice == 5){
            cout<<"Are you sure you want to save and quit? (Y/N): ";
            char c;
            cin>>c;
            if(isChoiceYes(c)){
                saveAndQuit = true;
                return;
            }
            else{
                choice = -1;
                continue;
            }
        }
        
        //chceking if its a valid option for 2 and 3
        if(choice == 2 || choice == 3){
            if(human->hasMoreMoves(layout, passed)) {
                cout<<"You already have a valid move you can make! Please try again!"<<endl;
                choice = -1;
                cout<<endl;
            }
            else if(choice == 2){
                if(hasAlreadyDrawn){
                    cout<<"You already drew on tile! You can only pass now!"<<endl;
                    choice = -1;
                    cout<<endl;
                }
                else{
                    Tile tileDrawn =stock->getTileOnTop();
                    human->addNewTile(tileDrawn);
                    hasAlreadyDrawn = true;
                    cout<<human->getName()<<" drew "<< tileDrawn.first<<"-"<<tileDrawn.second<<" from the stock!"<<endl;
                    cout<<endl;
                    cout<<"Human Hand:"<<endl;
                    human->displayHand(cout);
                }
            }
            else{
                if(!hasAlreadyDrawn){
                    cout<<"You cannot pass yet! Please draw a tile from the stock! "<<endl;
                    choice = -1;
                    cout<<endl;
                }
            }
        }
        
        if(choice == 4){
            Move hint = human->getHint(layout, passed);
            cout<<endl;
            if(hint.first.first == -1){
                cout<<"There are no possible moves that you can make."<<endl;
                if(hasAlreadyDrawn) cout<<"You can only pass now!"<<endl;
                else cout<<"You'll have to draw one from the stock!"<<endl;
            }
            else{
                cout<<"You can play "<<hint.first.first<< " - "<<hint.first.second <<" on the "<<getSideString(hint.second)<<"!"<<endl;
            }
            cout<<endl;
            choice = -1;
        };
    }while(choice != 1 && choice != 3);
    
    if(choice == 1){
        MoveType move = INVALID;
        
        do{
            cout<<endl;
            int noOfTiles = human->getNumberOfTilesInHand();
            int index = -1;
            do{
                cout<<"Please enter the index of the tile you want to play. (1-"<<noOfTiles<<"):: ";
                cin>>index;
            }while(index < 0 || index>noOfTiles);
            
            
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
            cout<<"You chose to play "<<tile.first<<" - "<<tile.second<<" on the "<<getSideString(s) <<" !"<<" Are you sure? (Y for yes / any key for No) :: ";
            char sure;
            cin>>sure;
            if(isChoiceYes(sure)) move = human->play(index, s, layout, passed);
            if(move == INVALID) cout<< "Invalid move played! Try Again!"<<endl;
        }while(move != VALID);
        passCount = 0;
        
    }
    else{
        passed= true;
        passCount++;
        cout<<human->getName()<<" has passed! Its computer's trun! "<<endl;
    }
    turn = !turn;
}

void Round::getComputerMove(){
    
    cout<<endl;
    cout<<"Computer Hand: "<<endl;
    computer->displayHand(cout);
    
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    MoveType move = computer->play(layout, passed);
    if(move == INVALID){
        computer->addNewTile(stock->getTileOnTop());
        cout<<"Computer drew a tile from the stock"<<endl;
        move = computer->play(layout, passed);
    }
    if(move == INVALID){
        passed = true;
        cout<<"Computer passed! Your turn!"<<endl;
        cout<<endl;
    }
    else if(move == VALID) cout<<"Computer played "<<computer->getPlayedMove()<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;
    
    turn = !turn;
    
}

