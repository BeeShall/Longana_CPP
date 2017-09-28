//
//  Round.cpp
//  Longana
//
//  Created by Bishal Regmi on 9/12/17.
//  Copyright © 2017 Bishal Regmi. All rights reserved.
//

#include "Round.hpp"

/* *********************************************************************
 Function Name: Round
 Purpose: Default constructor for the class
 Parameters: None
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: Round
 Purpose: Constructor for the class
 Parameters:
 human, pointer to the human player,
 computer, pointer to the computer player,
 enginePip, integer to indicate the engine for the round
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: ~Round
 Purpose: Destructor for the class
 Assistance Received: none
 ********************************************************************* */
Round::~Round(){
    delete stock;
    delete layout;
}

/* *********************************************************************
 Function Name: play
 Purpose: To run the round
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm:
 1) Shuffles the stock
 2) generates the hand for Human and Computer
 3) determines the first player
 4) starts the round loop by calling start()
 Assistance Received: none
 ********************************************************************* */
void Round::play(){
    stock->shuffleStock();
    human->setNewHand(stock->generateHand());
    computer->setNewHand(stock->generateHand());
    printRoundState();
    
    determineFirstPlayer();
    
    start();
    if(!saveAndQuit) getRoundScore();
    
}

/* *********************************************************************
 Function Name: load
 Purpose: To load the round given the roundState
 Parameters:
 roundInfo, constant reference to vector of string to save memory, serialized state of round to load
 Return Value: none
 Local Variables:
 vector<Tile> computerHand, to store parsed computer hand
 vector<Tile> humanHand, to store parsed human hand
 vector<Tile> layoutTiles,, to store parsed layout tiles
 vector<Tile> stockTiles, to store parsed boneyard tiles
 Assistance Received: none
 ********************************************************************* */
void Round::load(const vector<string> &roundInfo){
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
    
    if(!saveAndQuit) getRoundScore();
    
    
}

/* *********************************************************************
 Function Name: getSerializedRoundInfo
 Purpose: To generate serialized string of round state
 Parameters: None
 Return Value: The serialized round state, string
 Local Variables:
 ostringstream, to create the string
 Assistance Received: none
 ********************************************************************* */
string Round::getSerializedRoundInfo(){
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

/* *********************************************************************
 Function Name: start
 Purpose: To start the round
 Parameters: None
 Return Value: None
 Local Variables: None
 Algorithm:
 1) Runs a loop while the round hasn't ended
 2) Gets Human and Computer move turn by turn
 3) Checks if the user has indicated save an quit on every iteration, if yes serializes the round state
 Assistance Received: none
 ********************************************************************* */
void Round::start(){
    printRoundState();
    //game ending conditions
    while(!hasRoundEnded()){
        if(turn) getUserMove();
        else getComputerMove();
        if(saveAndQuit) return;
        printRoundState();
    }
    cout<<endl;
    cout<<"The round has ended!"<<endl;
    cout<<endl;
    //getRoundScore();
}

/* *********************************************************************
 Function Name: determineFirstPlayer
 Purpose: To determine the first player for the round
 Parameters: None
 Return Value: None
 Algorithm:
 1) Get the engine
 2) Keep drawing tiles from the stock until one has the pip
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: checkIfPlayerHasEngine
 Purpose: To check if the either player has engine
 Parameters: Tile, the engine tile
 Return Value: boolean, inidicating if the either player has engine
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: parsePips
 Purpose: To parse the serialized string to vector of pip Tiles
 Parameters: string containing serialized pip Tiles
 Return Value: vector of Tile containing parse pip Tiles
 Assistance Received: none
 ********************************************************************* */
vector<Tile> Round::parsePips(string pips){
    vector<Tile> tiles;
    istringstream iss(pips);
    string tileStr = "";
    while(iss>>tileStr){
        tiles.push_back({atoi(&tileStr[0]), atoi(&tileStr[2])});
    }
    return tiles;
}

/* *********************************************************************
 Function Name: hasRoundEnded
 Purpose: To determine if the round has ended
 Parameters: None
 Return Value: boolean indicating if the round ended
 Assistance Received: none
 ********************************************************************* */
bool Round::hasRoundEnded(){
    if(human->isHandEmpty() || computer->isHandEmpty()) return true;
    if(stock->isEmpty() && passCount >2) return true;
    return false;
}

/* *********************************************************************
 Function Name: printRoundState
 Purpose: To print layout and the boneyard
 Parameters: None
 Return Value: None
 Assistance Received: none
 ********************************************************************* */
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

/* *********************************************************************
 Function Name: getUserMove
 Purpose: gets and makes the UserMove
 Parameters: None
 Return Value: None
 Local Variables:
 choice, character to get user menu choice
 hasAlreadyDrawn, boolean to record if the user drew a tile from boneyard
 tileDrawn, Tile to save the drawn tile
 MoveType, to record of the user's move was valid or invalid
 Algorithm:
 1) Ask user for a choice
 2) If wants to save and quit, set saveAndQuit to true and return
 3) If wants to draw or tile or pass, validate if the user has a valid move in hand
 4) If not, validate if the user already drew a tile
 5) If not and user chose draw a tile, draw a tile drom the stock and show the menu again
 6) If the user chose make a move, get a move and validate it
 7) If the user chose pass and pass is allowed, set passed to true
 8) If the stock is empty, increase the passcount to record round end
 9) Switch the turn
 Assistance Received: none
 ********************************************************************* */
void Round::getUserMove(){
    cout<<endl;
    
    cout<<"Human Hand: "<<endl;
    human->displayHand(cout);
    
    cout<<endl;
    //to record menu choice
    int choice = -1;
    //to record if tile has already been drawn
    bool hasAlreadyDrawn = false;
    //loop until user chose to make a move or pass is valid
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
            //if the human has more moves, he can't pass or draw
            if(human->hasMoreMoves(layout, passed)) {
                cout<<"You already have a valid move you can make! Please try again!"<<endl;
                choice = -1;
                cout<<endl;
            }
            //if the user doesn't have any moves
            else if(choice == 2){
                //if the user already drew, he can only pass
                if(hasAlreadyDrawn){
                    cout<<"You already drew on tile! You can only pass now!"<<endl;
                    choice = -1;
                    cout<<endl;
                }
                //else he'll draw the from top of the staock
                else{
                    //if stock is empty, the user can only pass
                    if(stock->isEmpty()) cout<<"Stock is empty! You can only pass!"<<endl;
                    else{
                        Tile tileDrawn =stock->getTileOnTop();
                        human->addNewTile(tileDrawn);
                        cout<<human->getName()<<" drew "<< tileDrawn.first<<"-"<<tileDrawn.second<<" from the stock!"<<endl;
                        cout<<endl;
                        cout<<"Human Hand:"<<endl;
                        human->displayHand(cout);
                    }
                    hasAlreadyDrawn = true;
                }
            }
            else{
                //if the user hasn't drawn tile, he can't pass yet
                if(!hasAlreadyDrawn){
                    cout<<"You cannot pass yet! Please draw a tile from the stock! "<<endl;
                    choice = -1;
                    cout<<endl;
                }
            }
        }
        //user wants a hint
        if(choice == 4){
            Move hint = human->getHint(layout, passed);
            cout<<endl;
            //{-1,-1} means no valid moves in hand
            if(hint.first.first == -1){
                cout<<"There are no possible moves that you can make."<<endl;
                //if the user hasAlready drawn or stock is empty, the only hint is to pass
                if(hasAlreadyDrawn || stock->isEmpty()) cout<<"You can only pass now!"<<endl;
                //if hasn't drawn, the hint is to draw from stock
                else cout<<"You'll have to draw one from the stock!"<<endl;
            }
            //if there's valid move, show the hint
            else{
                cout<<"----------------------------------"<<endl;
                cout<<"You can play "<<hint.first.first<< " - "<<hint.first.second <<" on the "<<getSideString(hint.second)<<"!"<<endl;
                cout<<"----------------------------------"<<endl;
            }
            cout<<endl;
            choice = -1;
        }
    }while(choice != 1 && choice != 3);
    
    //if the user chose to make a move
    if(choice == 1){
        MoveType move = INVALID;
        
        //loop until the user's move isn't valid
        do{
            cout<<endl;
            //no of tiles user has in hand
            int noOfTiles = human->getNumberOfTilesInHand();
            int index = -1;
            //validate if the user enters a valid tile index
            do{
                cout<<"Please enter the index of the tile you want to play. (1-"<<noOfTiles<<"):: ";
                cin>>index;
            }while(index < 0 || index>noOfTiles);
            
            //to get the side user wants to play in
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
            
            //get the tile from boneyard and confirm and validate before making the move
            Tile tile = human->getTilefromHand(index);
            cout<<"You chose to play "<<tile.first<<" - "<<tile.second<<" on the "<<getSideString(s) <<" !"<<" Are you sure? (Y for yes / any key for No) :: ";
            char sure;
            cin>>sure;
            if(isChoiceYes(sure)) move = human->play(index, s, layout, passed);
            if(move == INVALID) cout<< "Invalid move played! Try Again!"<<endl;
        }while(move != VALID);
        //reset the passcount because user made the move
        passCount = 0;
        passed = false;
        
    }
    else{
        passed= true;
        // passes are counted only after the boneyard is empty excluding the pass after last tile drawn
        if(stock->isEmpty() && !hasAlreadyDrawn)passCount++;
        cout<<human->getName()<<" has passed! Its computer's trun! "<<endl;
    }
    turn = !turn;
}

/* *********************************************************************
 Function Name: getComputerMove
 Purpose: To get and make the computer move
 Parameters: None
 Return Value: None
 Local Variables:
 move, MoveType to record whether the computer has a valid move or not
 Algorithm:
 1) get the move from computer
 2) if invalid, draw from stock
 3) if still invalid, pass
 4) switch the turn
 Assistance Received: none
 ********************************************************************* */
void Round::getComputerMove(){
    
    cout<<endl;
    cout<<"Computer Hand: "<<endl;
    computer->displayHand(cout);
    
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    //to record if tile was drawn
    bool tileDrawn = false;
    //get the move based on the layout
    MoveType move = computer->play(layout, passed);
    //if there is no valid move
    if(move == INVALID){
        //if the stock isn't empty
        if(!stock->isEmpty()) {
            //draw from stock
            computer->addNewTile(stock->getTileOnTop());
            cout<<"Computer drew a tile from the stock"<<endl;
            move = computer->play(layout, passed);
        }
        tileDrawn = true;
    }
    //if there is no valid after drawing
    if(move == INVALID){
        //pass it
        passed = true;
        //if the boneyard is empty and tile has already been drawn, increase passCount
        if(stock->isEmpty() && !tileDrawn)passCount++;
        cout<<"Computer passed! Your turn!"<<endl;
        cout<<endl;
    }
    //if move is valid, place it
    else if(move == VALID){
        cout<<"Computer played "<<computer->getPlayedMove()<<endl;
        passed = false;
        passCount = 0;
    }
    cout<<"----------------------------------"<<endl;
    cout<<endl;
    //switch the turn
    turn = !turn;
    
}

/* *********************************************************************
 Function Name: getRoundScore
 Purpose: To calculate the round score and the winner
 Parameters: None
 Return Value: None
 Local Variables:
 humanTotal: sum of pips for human
 computerTotal: sum of pops for computer
 winner: winner of the round
 Algorithm:
 1) Get sum of pips for both the player
 2) if a player's hand is empty, the player with empty hand is the winner and his score is the sum of pips from other player
 3) if hand was not empty, then the player with lower sum wins and get score as the sum of pips from other palyer
 4) if equal, its a draw and return
 5) else print the winner
 Assistance Received: none
 ********************************************************************* */
void Round::getRoundScore(){
    //holds sum of all tiles for human
    int humanTotal = human->getSumofAllPips();
    //holds sum of all tiles for computer
    int computerTotal = computer->getSumofAllPips();
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Computer Score: "<<computerTotal<<endl;
    cout<< human->getName()<<"'s Score: "<<humanTotal<<endl;
    string winner ="Computer";
    int score = 0;
    
    //if human emptied the hand , he wins
    if(human->isHandEmpty()){
        winner = human->getName();
        score = computerTotal;
        human->setScore(score);
    }
    //if computer emptied the hand, computer wins
    else if(computer->isHandEmpty()){
        score = humanTotal;
        computer->setScore(score);
    }
    //if human has less sum than computer, human wins
    else if(humanTotal < computerTotal){
        winner = human->getName();
        score = computerTotal;
        human->setScore(score);
    }
    //if computer has less sum, computer wins
    else if (humanTotal > computerTotal){
        score = humanTotal;
        computer->setScore(score);
    }
    //if equal, its a draw
    else{
        cout<<"The round ended with a draw!"<<endl;
        return;
    }
    cout<<winner<< " won this round with a score of "<<score<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;
}
