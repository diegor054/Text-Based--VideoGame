#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string>* load(const string &);
void save(const string &, vector<string>*);

int main() {
    //load program
    string file = "./data/savefile.txt";
    vector<string>* gameInfo = load(file);
    
    //check if new player
    if (playerinfo == nullptr) {
        string playerName;
        cout << "Welcome, please enter your player's name: " << flush;
        cin >> playerName;
    }
    
    //run program
    PlayerFactory pf;
    Character* player = pf.getPlayer(gameInfo->at(2));
    
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
    vector<string>* gameInfo = new vector<string>(3);
    fin << temp << gameInfo->at(0); //stage
    fin << temp << gameInfo->at(1); //points
    fin << temp; getline(fin, gameinfo->at(2)); //playerInfo
    fin.close();
    return true;
}

void save(const string &file, vector<string>* gameInfo) {
    ofstream fout(file);
    if (!fout.is_open()) {
        cout << "Error writing to " << file << endl;
        exit(EXIT_FAILURE);
    }
    fout << "Stage: " << gameInfo->at(0) << endl;
    fout << "Points: " << gameInfo->at(1) << endl;
    fout << "PlayerInfo: " << gameInfo->at(2) << endl;
    fout.close();
    delete gameInfo;
    return true;
}
