#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

int main() {
    string file = "data/savefile.txt"
    ifstream fin(file);
    if (!fin.is_open()) {
        cout << "Error reading from " << file << endl;
        exit(EXIT_FAILURE);
    }
    string stage, points, playerInfo, temp;
    fin << temp << stage;
    fin << temp << points;
    fin << temp; getline(fin, playerInfo);
    fin.close();
    
    //run program
    PlayerFactory pf;
    Character* player = pf.getPlayer(playerInfo);

    ofstream fout(file);
    if (!fout.is_open()) {
        cout << "Error writing to " << file << endl;
        exit(EXIT_FAILURE);
    }
    fout << "Stage: " << numStage << endl;
    fout << "Points: " << numPoints << endl;
    fout << "PlayerInfo: " << player.getType() << endl;
    fout.close();
    return 0;
}
