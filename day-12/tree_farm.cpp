/*
Advent of Codde - Day 12: Christmas Tree Farm 

Arrange oddly shaped Gifts under the christmas tree.There are pre-set
number of gift shapes. 

The input also contains the list of regions (lxw) and the list of quantity of
each shape that needs to be fit in the tree.

The presents can be rotated around to optimize the placements. 

The result is the nmber of regions that fits the number of gifts listed.
*/


#include <bits/stdc++.h>
using namespace std;

// ---------- Parsing ----------

struct Region {
    int w, h;
    vector<int> counts;
};

void parse(const string &input_file,
           map<int, vector<string>> &shapes,
           vector<Region> &regions) {

    ifstream file(input_file);
    if (!file) {
        cerr << "Error: Cannot open file " << input_file << endl;
        exit(1);
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    size_t i = 0;
    // Parse shapes
    while (i < lines.size()) {
        line = lines[i];
        if (!line.empty() && line.back() == ':' && isdigit(line[0])) {
            int idx = stoi(line.substr(0, line.size()-1));
            ++i;
            vector<string> grid;
            while (i < lines.size() && !(lines[i].back() == ':' && isdigit(lines[i][0])) && lines[i].find('x') == string::npos) {
                grid.push_back(lines[i]);
                ++i;
            }
            shapes[idx] = grid;
        } else {
            break;
        }
    }

    // Parse regions
    while (i < lines.size()) {
        line = lines[i];
        if (line.find('x') != string::npos && line.find(':') != string::npos) {
            size_t colon_pos = line.find(':');
            string size_str = line.substr(0, colon_pos);
            string rest = line.substr(colon_pos + 1);

            size_t x_pos = size_str.find('x');
            int w = stoi(size_str.substr(0, x_pos));
            int h = stoi(size_str.substr(x_pos + 1));

            vector<int> counts;
            stringstream ss(rest);
            int n;
            while (ss >> n) counts.push_back(n);

            regions.push_back({w, h, counts});
        }
        ++i;
    }
}

// ---------- Fast volume check ----------

int arrange_gifts(const string &input_file) {
    map<int, vector<string>> shapes;
    vector<Region> regions;

    parse(input_file, shapes, regions);

    // Count cells per shape
    map<int, int> cells_per_shape;
    for (auto &[idx, grid] : shapes) {
        int count = 0;
        for (const string &row : grid) {
            count += count_if(row.begin(), row.end(), [](char c){ return c == '#'; });
        }
        cells_per_shape[idx] = count;
    }

    int total_count = 0;
    for (const auto &region : regions) {
        int total_needed = 0;
        for (size_t idx = 0; idx < region.counts.size(); ++idx) {
            total_needed += region.counts[idx] * cells_per_shape[idx];
        }
        if (total_needed <= region.w * region.h) {
            total_count += 1;
        }
    }

    return total_count;
}

// ---------- Main ----------

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    string input_file = argv[1];
    if (!filesystem::exists(input_file)) {
        cerr << "Error: File '" << input_file << "' does not exist." << endl;
        return 1;
    }

    int result = arrange_gifts(input_file);
    cout << "The number of regions that fit all the corresponding gifts that were listed: " << result << endl;

    return 0;
}
