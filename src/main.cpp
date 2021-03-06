#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "../header/Opponent.hpp"
#include "../header/Player.hpp"
#include "../header/AttackerFactory.hpp"
#include "../header/HealerFactory.hpp"
#include "../header/NinjaFactory.hpp"
#include "../header/LeftPathFactory.hpp"
#include "../header/RightPathFactory.hpp"

vector<string>* load(const string &);
void save(const string &, vector<string>*);
void help(const string &);
vector<string>* start();
BaseCharacter* getPlayer(const string &, const string &, int, bool);
void getPath(bool &);
void instructions();
vector<BaseCharacter*> getStage(BaseCharacter*, int, bool);
bool fight(vector<BaseCharacter*>, int &);
string getFightOption();
void stageMessages(int, bool &);

int main() {
    //load program
    string file = "data/savefile.txt";
    vector<string>* gameInfo = load(file);
    
    //get player
    BaseCharacter* player;
    if (gameInfo == nullptr) {
        gameInfo = start();
        player = getPlayer(gameInfo->at(2), gameInfo->at(3), stoi(gameInfo->at(1)), true);
        instructions();
    }
    else {
        player = getPlayer(gameInfo->at(2), gameInfo->at(3), stoi(gameInfo->at(1)), false);
        cout << "Welcome back to King of the Dungeon, " << gameInfo->at(2) << "!" << endl;
    }
    cout << endl;
    player->refresh(true);

    //run program
    int stage = stoi(gameInfo->at(0));
    bool isLeftPath = gameInfo->at(4) == "Left" ? true : false;
    string userInput = "X";
    while (toupper(userInput.at(0)) != 'Q' && stage <= 10) {
        cout << "Would you like to continue (C) view stats (S) or exit (Q)? " << flush;
        cin >> userInput;
        if (toupper(userInput.at(0)) == 'C') {
            cout << endl;
            stageMessages(stage, isLeftPath); 
            vector<BaseCharacter*> opponentsList = getStage(player, stage, isLeftPath);
            stage += fight(opponentsList, stage);
            cout << endl;
        }
        else if (toupper(userInput.at(0)) == 'S') {
            cout << endl;
            cout << "Name: " << player->getName() << endl;
            cout << "Type: " << player->getType() << endl;
            cout << "Path: " << (isLeftPath == true ? "Left" : "Right") << endl;
            cout << "Stage: " << stage << endl;
            cout << "Level: " << player->getLevel() << endl;
            cout << "Points: " << player->getXP() << endl;
            cout << "Max Health: " << player->getHealth() << endl;
            cout << "Attack Strength: " << player->getAttackStrength() << endl;
            cout << endl;
        }
    }
    if (stage > 10) {
        cout << "Congrats on beating the final boss. You have made everyone proud. Now go on and collect your treasure." << endl;
    }
    cout << endl << "Thanks for playing, " << player->getName() << "!" << endl;

    //save program
    gameInfo->at(0) = to_string(stage);
    gameInfo->at(1) = to_string(player->getXP());
    gameInfo->at(4) = isLeftPath == true ? "Left" : "Right";
    save(file, gameInfo);
    delete player;
    return 0;
}

vector<string>* load(const string &file) {
    ifstream fin(file);
    if (!fin.is_open()) {
        ofstream fout(file);
        fout.close();
        fin.open(file);
    }
    if (!fin.is_open()) {
        cout << "Error reading from " << file << endl;
        exit(EXIT_FAILURE);
    }
    string temp;
    fin >> temp;
    if (fin.eof()) {
        return nullptr;
    }
    vector<string>* gameInfo = new vector<string>(5);
    fin >> gameInfo->at(0); //stage
    fin >> temp >> gameInfo->at(1); //points
    fin >> temp >> gameInfo->at(2); //name
    fin >> temp >> gameInfo->at(3); //type
    fin >> temp >> gameInfo->at(4); //path
    fin.close();
    return gameInfo;
}

void save(const string &file, vector<string>* gameInfo) {
    ofstream fout(file);
    if (!fout.is_open()) {
        cout << "Error writing to " << file << endl;
        exit(EXIT_FAILURE);
    }
    fout << "Stage: " << gameInfo->at(0) << endl;
    fout << "Points: " << gameInfo->at(1) << endl;
    fout << "Name: " << gameInfo->at(2) << endl;
    fout << "Type: " << gameInfo->at(3) << endl;
    fout << "Path: " << gameInfo->at(4) << endl;
    fout.close();
    delete gameInfo;
}

void help(const string &name) {
    cout << "Welcome to King of the Dungeon, " << name << "!" << endl << endl;
    cout << "You are going on a journey throughout a mysterious dungeon in hopes of finding a secret treasure that no one has ever found." << endl;
    cout << "However, the task will not be easy 0_0." << endl;
    cout << "There are rumors of mysterous creatures that live within the dugeon." << endl;
    cout << "Whether those rumors are true or not, that's for you to find out." << endl;
    cout << "Throughout your journey you may potentially have to fight armies of creatures so prepare yourself." << endl;
    cout << "Good Luck " << name << ", may you have luck on your side and most importantly have fun." << endl;
}

vector<string>* start() {
    string playerName;
    cout << "Welcome, please enter your player's name: " << flush;
    cin >> playerName;
    cout << endl;
    help(playerName);
    string playerType = "X";
    bool invalidInput = true;
    while (invalidInput) {
        invalidInput = false;
        cout << endl << "Choose your player type wisely: (A) attacker, (H) healer, or (N) Ninja: " << flush;
        cin >> playerType;
        if (toupper(playerType.at(0)) == 'A') {
            playerType = "Attacker";
        }
        else if (toupper(playerType.at(0)) == 'H') {
            playerType = "Healer";
        }
        else if (toupper(playerType.at(0)) == 'N') {
            playerType = "Ninja";
        }
        else {
            cout << "This is not a valid choice." << endl;
            invalidInput = true;
        }
    }
    return new vector<string>{"1", "0", playerName, playerType, "Left"};
}

BaseCharacter* getPlayer(const string &name, const string &type, int xp, bool isNew) {
    AbstractPlayerFactory* pf;
    if (type == "Attacker") pf = new AttackerFactory();
    else if (type == "Healer") pf = new HealerFactory();
    else if (type == "Ninja") pf = new NinjaFactory();
    else return nullptr;
    if (isNew) {
        cout << endl << pf->getPlayerInfo() << endl;
        BaseCharacter* player = pf->getDefaultPlayer();
        delete pf;
        player->setName(name);
        return player;
    }
    BaseCharacter* player = pf->getUpgradedPlayer(name, xp);
    delete pf;
    return player;
}

void instructions() {
    cout << endl << "Would you like to see the instructions before you start? (Y)/(N): " << flush;
    string userInput;
    cin >> userInput;
    if (toupper(userInput.at(0)) == 'Y') {
        cout << endl << "Throughout this game you will explore a dungeon and have to navigate throughout the halls." << endl;
        cout << "You will be asked to go LEFT or RIGHT and face enemies depending on what directon you go." << endl;
        cout << "You will have to eliminate all enemies before moving onto the next stage." << endl;
        cout << "You will have the ability to leave a fight if you are running low on health." << endl;
        cout << "Note you will gain back some health after each round." << endl;
    }
}

vector<BaseCharacter*> getStage(BaseCharacter* player, int stage, bool isLeftPath) {
    AbstractStageFactory *path;
    if (isLeftPath) path = new LeftPathFactory(player);
    else path = new RightPathFactory(player);
    vector<BaseCharacter*> charList;
    switch(stage) {
        case 1: charList = path->getStage1(); delete path; return charList;
        case 2: charList = path->getStage2(); delete path; return charList;
        case 3: charList = path->getStage3(); delete path; return charList;
        case 4: charList = path->getStage4(); delete path; return charList;
        case 5: charList = path->getStage5(); delete path; return charList;
        case 6: charList = path->getStage6(); delete path; return charList;
        case 7: charList = path->getStage7(); delete path; return charList;
        case 8: charList = path->getStage8(); delete path; return charList;
        case 9: charList = path->getStage9(); delete path; return charList;
        default: charList = path->getStage10(); delete path; return charList;
    }
}

void getPath(bool &isLeftPath) {
    cout << endl << "Which path would you like to take. Enter L or R: " << flush;
    string path;
    cin >> path;
    while (toupper(path.at(0)) != 'L' && toupper(path.at(0)) != 'R') {
        cout << "This is not a valid choice. Enter L or R: " << flush;
        cin >> path;
    }
    cout << endl;
    if (toupper(path.at(0)) == 'L') isLeftPath = true;
    else isLeftPath = false;
}

bool fight(vector<BaseCharacter*> charList, int& stage) {
    cout << endl << "Round " << stage << " has begun!" << endl << endl;
    while (charList.at(0)->getHealth() > 0) {
        string option = getFightOption();
        cout << endl;
        if (option == "A") {
            int numLeft = charList.size() - 1;
            charList.at(0)->attack(charList, 0);
            for (int i = 1; i < charList.size(); ++i) {
                if (charList.at(i)->getHealth() == 0) {
                    cout << charList.at(i)->getName() + " Has Been Eliminated." << endl;
                    delete charList.at(i);
                    charList.erase(charList.begin() + i);
                    numLeft -= 1;
                }
            }
            if (numLeft == 0) {
                cout << "You have eliminated all opponents! Round " << stage << " has finished." << endl;
                charList.at(0)->refresh(true);
                return true;
            }
            int numOpponents = charList.size() - 1;
            int opponentIndex = rand() % numOpponents + 1;
            charList.at(opponentIndex)->attack(charList, opponentIndex);
            cout << endl;
        }
        else if (option == "V") {
            for (int i = 0; i < charList.size(); ++i) {
                cout << charList.at(i)->getName() << ": " << charList.at(i)->getHealth() << " health. " << charList.at(i)->getHealthBar() << endl;
            }
            cout << endl;
        }
        else {
            cout << "You have fled the fight." << endl;
            while (charList.size() > 1) {
                delete charList.back();
                charList.pop_back();
            }
            charList.at(0)->refresh(true);
            return false;
        }
    }
    cout << "You have been elimated." << endl;
    stage -= 1;
    charList.at(0)->refresh(false);
    while (charList.size() > 1) {
        delete charList.back();
        charList.pop_back();
    }
    return false;
}

string getFightOption() {
    string choice = "X";
    bool invalidInput = true;
    while (invalidInput) {
        invalidInput = false;
        cout << "Would you like to attack (A) view enemies (V) or escape (E): " << flush;
        cin >> choice;
        if (toupper(choice.at(0)) == 'A') {
            choice = "A";
        }
        else if (toupper(choice.at(0)) == 'V') {
            choice = "V";
        }
        else if (toupper(choice.at(0)) == 'E') {
            choice = "E";
        }
        else {
            cout << "This is not a valid choice." << endl;
            invalidInput = true;
        }
    }
    return choice;
}

void stageMessages(int stage, bool &isLeftPath) {
    switch(stage) {
        case 1:
            cout << "You have entered the dungeon. It seems as if this place hasn't been cleaned in centuries." << endl;
            cout << "You heard grand tales of the endless riches contained inside, and now the moment has finally arrived to explore." << endl;
        cout << "You walk down the dungeon for about five minutes until you reach a point where the dungeon splits off." << endl;
            cout << "*thump*" << endl;
            cout << "You see a bright torch and a sign pointing in two directions, Left or Right" << endl;
            cout << "In the left path, you hear lots of noises and see many figures in the distance." << endl;
            cout << "In the right path, you see this giant looming shadow with a deadly presence."<< endl;
        getPath(isLeftPath);
            if (isLeftPath) {
                cout << "You walk down the left path and see zombies standing before your eyes! They run towards you and want some fresh meat!" << endl;
            }
            else {
                cout << "You walk down the right path and see a couple corpses. Wait, they're zombies ready to eat some brains!" << endl;
            }
            cout << "Prepare yourself... you are about to get in a fight." << endl;
            break;
        case 2:
            cout << "You take a quick break to heal yourself and recover." << endl;
            cout << "Suddenly, more opponents start to show up! This time it looks like alot more." << endl;
            break;
        case 3:
            cout << "You take another quick break and heal yourself." << endl;
            cout << "You thought you were done... More Opponents start to show up. These look way more dangerous!" << endl;
            break;
        case 4:
            cout << "After 3 long fights, you take a break and continue to explore the dungeon. " << endl;
            cout << "You find some human skeleton remains and realize that people have died on this exploration before." << endl;
            cout << "You walk past the skeletons to continue your journey and to try to do what no-one else had ever achieved before." << endl;
            cout << "*thump*" << endl;
            cout << "Once again, you walk for about ten minutes and the path ahead of you splits into two paths." << endl;
            cout << "The left path, you notice small shadows and many little noises you can't understand." << endl;
            cout << "From the right path, there are a couple gravestones and giant footprints leading into the tunnel " << endl;
            getPath(isLeftPath);
            if (isLeftPath) {
                cout << "You walk down the left path and see many weak zombies arguing over a couple of bones. They all look at you simultaneously, and run to eat you instead!" << endl;
            }
            else {
                cout << "You walk down the right path and see giant zombies sitting in a circular table using limbs as playing cards. It looks like they've been waiting for a while. They slowly get up, and stubbornly fight you." << endl;
            }
            cout << "Prepare yourself... you are about to get in a fight." << endl;
            break;
        case 5:
            cout << "You take a quick break to heal yourself and recover." << endl;
            cout << "Suddenly, more opponents start to show up! This time it looks like alot more." << endl;
            break;
        case 6:
            cout << "You take another quick break and heal yourself." << endl;
            cout << "You thought you were done... More Opponents start to show up. These look way more dangerous!" << endl;
            break;
        case 7:
            cout << "After 3 more long fights, you are approaching the end. " << endl;
            cout << "You walk more through the dungeon and have to choose which path direction to take once again." << endl;
            cout << "In the dreadful left path, you see blood, guts, and countless footprints trailing further into a darkness, do you dare to venture forward?" << endl;
            cout << "In the simpler right path, there is seemingly nothing to worry about except for a giant shadow, and it almost seems too peaceful to be true." << endl;
            getPath(isLeftPath);
            if (isLeftPath) {
                cout << "You walk down the left path and see zombies, goblins, and fairies all teaming up to finish you off! You look like a nice snack to them..." << endl;
            }
            else {
                cout << "You walk down the right path and see a giant zombie, goblin, and fairy ready to gang up on you! You're not ready for this dual!" << endl;
            }
            cout << "Prepare yourself... you are about to get in a fight." << endl;
            break;
        case 8:
            cout << "You take a quick break to heal yourself and recover." << endl;
            cout << "Suddenly, more opponents start to show up! This time it looks like a lot more." << endl;
            break;
        case 9:
            cout << "You take another quick break and heal yourself." << endl;
            cout << "You thought you were done... More Opponents start to show up. These look way more dangerous!" << endl;
            break;
        case 10:
            cout << "You walk more. You start to see gold, diamonds, emeralds, rubies... THIS IS IT. ALL YOU HAVE EVER WANTED!" << endl;
            cout << "YOU HAVE REACHED THE TREASURE!!!" << endl;
            cout << "However, its never this easy." << endl;
            cout << "Before you can step towards the treasure, every monster you have ever faced returns for revenge while guarding the endless-riches fortold by the many famous tales." << endl;
            cout << "This is your final stage, you final test, your endgame." << endl;
            cout << "It won't be easy to beat, but all the good things in life aren't easy." << endl;
            cout << "Well, its time for a final dual. Prepare yourself and good luck." << endl;
            break;
        default:
            cout << "Stage " << stage << " does not exist!" << endl;
            break;
    }
}
