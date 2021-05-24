#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "header/Player.hpp"

vector<string>* load(const string &);
void save(const string &, vector<string>*);
void help(const string &);
vector<string>* start();
Player* getPlayer(const string &, const string &, int, bool);

int main() {
    //load program
    string file = "./data/savefile.txt";
    vector<string>* gameInfo = load(file);
    
    //check if new player
    Player* player;
    if (gameInfo == nullptr) {
        gameInfo = start();
        player = getPlayer(gameInfo->at(2), gameInfo->at(3), stoi(gameInfo->at(1)), true);
    }
    else {
        player = getPlayer(gameInfo->at(2), gameInfo->at(3), stoi(gameInfo->at(1)), false);
    }

    //run program
    int stage = stoi(gameInfo->at(0));
    
    //save program
    gameInfo->at(2) = player.getType();
    save(file, gameInfo);
    return 0;
}

vector<string>* load(const string &file) {
    ifstream fin(file);
    if (!fin.is_open()) {
        cout << "Error reading from " << file << endl;
        exit(EXIT_FAILURE);
    }
    if (fin.eof()) {
        return nullptr;
    }
    string temp;
    vector<string>* gameInfo = new vector<string>(4);
    fin >> temp >> gameInfo->at(0); //stage
    fin >> temp >> gameInfo->at(1); //points
    fin >> temp >> gameInfo->at(2); //name
    fin >> temp >> gameInfo->at(3); //type
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
    fout.close();
    delete gameInfo;
}

void help(const string &name) {
	cout << "Welcome to King of the Dungeon, " << name << "!" << endl;
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
    help(playerName);
    cout << endl;
    string playerType = "X";
    bool invalidInput = true;
    while (invalidInput) {
        invalidInput = false;
        cout << "Choose your player type wisely: (A) attacker or (H) healer: " << flush;
        cin >> playerType;
        if (toupper(playerType.at(0)) == 'A') {
            playerType = "Attacker";
        }
        else if (toupper(playerType.at(0)) == 'H') {
            playerType = "Healer";
        }
        else {
            cout << "This is not a valid choice." << endl;
            invalidInput = true;
        }
    }
    return new vector<string>{"0", "0", playerName, playerType};
}

Player* getPlayer(const string &name, const string &type, int xp, bool isNew) {
    AbstractPlayerFactory pf;
    if (gameInfo->at(3) == "Attacker") pf = new AttackerFactory();
    else if (gameInfo->at(3) == "Healer") pf = new HealerFactory();
    else if (gameInfo->at(3) == "Ninja") pf = new NinjaFactory();
    else return nullptr;
}