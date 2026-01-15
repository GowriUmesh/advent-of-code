/* 
Advent of Code - Day 4: Printing Department

Optimize forklift operations, The forklifts can access a 
roll of paper if it has at least four adjacent rolls.

Part1  : Count the number of rolls that can be accessed
by the forklifts based on the adjacency rule.

Part 2 : Count the total number of rolls that can be accessed
by the forklifts based on the adjacency rule after a roll is removed.

*/


#include <iostream>
#include <vector>
using namespace std;

vector<string> readGridFromFile(const string& filePath) {
    vector<string> grid;
    freopen(filePath.c_str(), "r", stdin);
    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    fclose(stdin);
    return grid;
}
int countAccessibleRolls(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> directions = {-1, 0, 1};
    int totalRemoved = 0;
    while(true){
        vector<int> colRemove;
        vector<int> rowRemove;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '@') {
                    int adjacentRolls = 0;
                    for (int dr : directions) {
                        for (int dc : directions) {
                            if (dr == 0 && dc == 0) continue;
                            int nr = r + dr;
                            int nc = c + dc;
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                                if (grid[nr][nc] == '@') {
                                    adjacentRolls++;
                            }
                        }
                    }
                }
                if (adjacentRolls < 4) {
                    colRemove.push_back(c);
                    rowRemove.push_back(r);
                }
            }
        }
    }
    

    if(colRemove.empty()) break;
    for(int i = 0; i < colRemove.size(); i++){
        grid[rowRemove[i]][colRemove[i]] = '.';
    }
    totalRemoved += colRemove.size();
    }

    return totalRemoved;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Usage: " << argv[0] << " <path_to_input_file>" << endl;
        return 1;
    }
    string inputFilePath = argv[1];    
    vector<string> grid = readGridFromFile(inputFilePath);
    int accessibleRolls = countAccessibleRolls(grid);
    cout << "Total accessible rolls: " << accessibleRolls << endl;
    return 0;
}