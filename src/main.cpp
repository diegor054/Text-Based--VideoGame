#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string>* load(const string &);
void save(const string &, vector<string>*, Character*);

int main() {
    string file = "data/savefile.txt";
    vector<string>* gameInfo = load(file);
    if (playerinfo.size() == 0) {
        string playerName;
        cout << "Welcome, please enter your player's name: " << flush;
        cin >> playerName;
    }
    
    //run program
    PlayerFactory pf;
    Character* player = pf.getPlayer(playerInfo);

    save(file, player);
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
    string stage, points, playerInfo, temp;
    fin << temp << stage;
    fin << temp << points;
    fin << temp; getline(fin, playerInfo);
    fin.close();
    return true;
}

void save(const string &file, vector<string>* gameInfo, Character* player) {
    ofstream fout(file);
    if (!fout.is_open()) {
        cout << "Error writing to " << file << endl;
        exit(EXIT_FAILURE);
    }
    fout << "Stage: " << playerInfo.at(0) << endl;
    fout << "Points: " << playerInfo.at(1) << endl;
    fout << "PlayerInfo: " << player.getType() << endl;
    fout.close();
    delete gameInfo;
    return true;
}
