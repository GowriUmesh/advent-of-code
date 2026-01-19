/*
Advent of code - Day 08: Playground

The elves are trying to figure out which junction boxes to connect 
so that the electrictiy can reach every junction box. 

Elves have a list of junction boxs' position in 3D space (input).
To save on string lights, the elves want to connect the junction boxes that are 
as close to each other as possible.

Part 1 : Find the product of the sizes of the three largest circuits formed when 
connecting the 1000 closest pairs of junction boxes.

Part 2 : Find the product of the x-coordinates of the two junction boxes connected by 
the last connection made when connecting all junction boxes with the minimum total distance.

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v;
    long long distance;
};

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;

        if (size[ra] < size[rb])
            swap(ra, rb);

        parent[rb] = ra;
        size[ra] += size[rb];
        return true;
    }
};

vector<vector<int>> parse_positions(const string& filePath) {

    ifstream inputFile(filePath);
    vector<vector<int>> positions;
    string line;

    while(getline(inputFile, line)) {
        vector<int> coords;
        int coord = 0;
        for(char c : line) {
            if(c == ',') {
                coords.push_back(coord);
                coord = 0;
            } else {
                coord = coord * 10 + (c - '0');
            }
        }
        coords.push_back(coord);
        positions.push_back(coords);
    }
    return positions;
}

long long straight_line_distance(const vector<int>& pos1, const vector<int>& pos2) {
    long long dx = pos1[0] - pos2[0];
    long long dy = pos1[1] - pos2[1];
    long long dz = pos1[2] - pos2[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}
vector<Edge> build_edges(const vector<vector<int>>& junctionBoxes) {
    vector<Edge> edges;

    for(auto i=0; i<junctionBoxes.size(); ++i){
        for(auto j=i+1; j<junctionBoxes.size(); ++j){
            edges.push_back({i, j, straight_line_distance(junctionBoxes[i], junctionBoxes[j])});
        }
    }
    sort(edges.begin(), edges.end(),[](const Edge& a, const Edge& b) 
            { return a.distance < b.distance;});
    return edges;
}

int top_three_circuit_size_product(const vector<vector<int>>& junctionBoxes) {

    vector<Edge> edges = build_edges(junctionBoxes);

    DSU dsu(junctionBoxes.size());    

    // Process first 1000 closest edges
    int LIMIT = min(1000, (int)edges.size());
    for (int i = 0; i < LIMIT; i++) {
        dsu.unite(edges[i].u, edges[i].v);
    }

    // Count circuit sizes
    unordered_map<int, int> circuitSize;
    for (int i = 0; i < junctionBoxes.size(); i++) {
        circuitSize[dsu.find(i)]++;
    }

    // Collect and sort sizes
    vector<int> sizes;
    for (auto& [_, sz] : circuitSize)
        sizes.push_back(sz);

    sort(sizes.begin(), sizes.end(), greater<int>());

    /*
    cout << "Top 3 circuit sizes: "
         << sizes[0] << ", "
         << sizes[1] << ", "
         << sizes[2] << endl;

    */    
    return sizes[0] * sizes[1] * sizes[2];
}

long long last_connection_x_product(const vector<vector<int>>& junctionBoxes) {
    int n = junctionBoxes.size();
    vector<Edge> edges = build_edges(junctionBoxes);

    DSU dsu(n);

    int components = n;
    Edge lastMerged;

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            lastMerged = e;
            components--;

            if (components == 1)
                break;
        }
    }

    int x1 = junctionBoxes[lastMerged.u][0];
    int x2 = junctionBoxes[lastMerged.v][0];

    return (long long)x1 * x2;
}


int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Usage: " << argv[0] << " <path_to_input_file> " << endl;
        return 1;
    }

    string inputFilePath = argv[1];

    vector<vector<int>> junctionBoxes = parse_positions(inputFilePath);
    int circuits_product = top_three_circuit_size_product(junctionBoxes);
    long long last_edge_x_product = last_connection_x_product(junctionBoxes);
    cout<<"Product of sizes of top 3 circuits: "<<circuits_product<<endl;
    cout<<"Last edge product: "<<last_edge_x_product<<endl;

    return 0;
}