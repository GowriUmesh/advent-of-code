/*
Advent of Code - Day 10: Factory Machines
Elves are trying to automate their factory by initiating a series of machines.
Each machine has a set of buttons that toggle certain lights on or off.

* Part 1 : Determine the minimum number of button presses required to achieve a target light configuration.

*/


#include <bits/stdc++.h>
using namespace std;


int initiate_machines(int lights,const vector<vector<int>>& buttons,const vector<int>& target) {
    int m = lights;
    int n = buttons.size();

    vector<vector<int>> mat(m, vector<int>(n + 1, 0));
    for (int j = 0; j < n; j++)
        for (int i : buttons[j])
            mat[i][j] ^= 1;
    for (int i = 0; i < m; i++)
        mat[i][n] = target[i];

    int row = 0;
    vector<int> where(n, -1);
    for (int col = 0; col < n && row < m; col++) {
        int sel = row;
        while (sel < m && mat[sel][col] == 0) sel++;
        if (sel == m) continue;
        swap(mat[sel], mat[row]);
        where[col] = row;
        for (int i = 0; i < m; i++) {
            if (i != row && mat[i][col])
                for (int j = col; j <= n; j++)
                    mat[i][j] ^= mat[row][j];
        }
        row++;
    }

    vector<int> freeVars;
    for (int i = 0; i < n; i++)
        if (where[i] == -1) freeVars.push_back(i);

    int best = INT_MAX;
    int f = freeVars.size();
    for (int mask = 0; mask < (1 << f); mask++) {
        vector<int> x(n, 0);
        for (int i = 0; i < f; i++)
            if (mask & (1 << i)) x[freeVars[i]] = 1;
        for (int i = 0; i < n; i++) {
            if (where[i] != -1) {
                int val = mat[where[i]][n];
                for (int j = 0; j < n; j++)
                    if (j != i && mat[where[i]][j]) val ^= x[j];
                x[i] = val;
            }
        }
        best = min(best, accumulate(x.begin(), x.end(), 0));
    }
    return best;
}



int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Usage: " << argv[0] << " <path_to_input_file> " << endl;
        return 1;
    }
    string inputFilePath = argv[1];
    ifstream inputFile(inputFilePath);

    if(!inputFile.is_open()) {
        cerr << "Error opening file: " << inputFilePath << endl;
        return 1;
    }

    string line;
    int buttonClicks = 0;
    
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        int l = line.find('[');
        int r = line.find(']');
        string diagram = line.substr(l + 1, r - l - 1);

        int lights = diagram.size();
        vector<int> targetLights(lights);
        for (int i = 0; i < lights; i++)
            targetLights[i] = (diagram[i] == '#');

        int lb = line.find('{');
        int rb = line.find('}');
        vector<int> targetJolt;
        {
            stringstream ss(line.substr(lb + 1, rb - lb - 1));
            while (ss.good()) {
                int x;
                char c;
                ss >> x;
                targetJolt.push_back(x);
                ss >> c;
            }
        }

        vector<vector<int>> buttons;
        int pos = 0;
        while (true) {
            int lp = line.find('(', pos);
            if (lp == string::npos || lp > lb) break;
            int rp = line.find(')', lp);

            vector<int> btn;
            string inside = line.substr(lp + 1, rp - lp - 1);
            if (!inside.empty()) {
                stringstream ss(inside);
                while (ss.good()) {
                    int x;
                    char c;
                    ss >> x;
                    btn.push_back(x);
                    ss >> c;
                }
            }
            buttons.push_back(btn);
            pos = rp + 1;
        }

        buttonClicks += initiate_machines(lights, buttons, targetLights);
    }

    cout << "Fewest total presses: " << buttonClicks << "\n";
    return 0;
}
