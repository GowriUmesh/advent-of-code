/*
Advent of code - Day 06: Trash Compactor

Help cephalopod with her math homework while we wait for Trash compactor to open. 
The math worksheet consists  of a list of problems:each problem
has a group of numbers that need to be either added or multiplied together.

The problems are in a long horizontal list and each problem's numbers are arranged vertically. 
At the bottom of the problem is the symbol for the operation. 

Part 1 : Calculate the result of each problem and sum them all together.
(ignore the alignment of the numbers within each problem)

Part 2 : Calculate the result when math is written right-to-left in columns.
Each number is given in its own column, with the most significant digit at the top 
and the least significant digit at the bottom.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

vector<vector<string>> parse_worksheet(const string& filePath) {
    ifstream inputFile(filePath);
    vector<vector<string>> problems;
    string line;

    while(getline(inputFile, line)) {
        stringstream ss(line);
        vector<string> row;
        string token;

        while(ss >> token) {
            row.push_back(token);
        }

        problems.push_back(row);
    }

    return problems;
}
vector<cpp_int> solve_problems(const vector<vector<string>>& problems) {
    vector<cpp_int> results;
    int numRows = problems.size();
    int numCols = problems[0].size();

    vector<char> operations(numCols);

    for(int col = 0; col < numCols; ++col) {
        operations[col] = problems[numRows - 1][col][0];
    }

    for(int col = 0; col < numCols; col++) {
        cpp_int result = (operations[col] == '*') ? 1 : 0;

        for(int row = 0; row < numRows - 1; ++row) {
            int number = stoi(problems[row][col]);

            if(operations[col] == '*') {
                result *= number;
            } else if(operations[col] == '+') {
                result += number;
            }
        }

        results.push_back(result);
    }


    return results;
}

vector<string> parse_worksheet_cephalopodway(const string& filePath) {
    ifstream inputFile(filePath);
    vector<string> lines;
    string line;

    while (getline(inputFile, line))
        lines.push_back(line);

    return lines;
}

int custom_stoi(const string& str) {
    int result = 0;
    for(char ch : str) {
        if(ch >= '0' && ch <= '9') {
            result = result * 10 + (ch - '0');
        }
    }
    return result;
}

vector<cpp_int> solve_problems_cephalopodway(const vector<string>& lines) {

    int rows = lines.size();
    int cols = lines[0].size();
    cpp_int grandTotal = 0;

    int numOfProblems = 0;
    for(auto line:lines[rows-1]){
        if(line != ' '){
            numOfProblems++;
        }
    }
    vector<cpp_int> results(numOfProblems);

    string opLine = lines[rows-1];
    vector<char> operations;
    vector<int> columnWidths;
    
    int i = 0;
    while (i < opLine.size()) {
        // Skip leading spaces
        while (i < opLine.size() && opLine[i] == ' ') i++;
        if (i >= opLine.size()) break;
        
        // Found an operator
        char op = opLine[i];
        operations.push_back(op);
        i++;
        
        int width = 0;
        while (i < opLine.size() && opLine[i] != '*' && opLine[i] != '+') {
            width++;
            i++;
        }
        if(i==opLine.size()){
            columnWidths.push_back(width+1);
        }
        columnWidths.push_back(width);
    }
    
    for(int problemIdx = 0; problemIdx < operations.size(); ++problemIdx) {
        cpp_int result = (operations[problemIdx] == '*') ? 1 : 0;
        int colStart = 0;
        for(int k = 0; k < problemIdx; ++k) {
            colStart += columnWidths[k]+1; // +1 for the space between problems
        }
        int colEnd = colStart + columnWidths[problemIdx];
        vector<string> numbersStr;

        for(int row = 0; row < rows - 1; ++row) {
            string numStr=lines[row].substr(colStart, colEnd - colStart);
            numbersStr.push_back(numStr);

        }
        //access each column number from numbersStr
        for(int nIdx = 0; nIdx < numbersStr[0].size(); ++nIdx) {
            string digitStr;
            for(int rIdx = 0; rIdx < numbersStr.size(); ++rIdx) {
                digitStr += numbersStr[rIdx][nIdx];
            }

            int number = custom_stoi(digitStr);

            if(operations[problemIdx] == '*') {
                result *= number;
            } else if(operations[problemIdx] == '+') {
                result += number;
            }
        }
        results.push_back(result);  
    }

    return results;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        cout << "Usage: " << argv[0] << " <path_to_input_file> <0|1>" << endl;
        return 1;
    }
    string inputFilePath = argv[1];
    bool cWay = stoi(argv[2]);
    if(cWay != 0 && cWay != 1) {
        cout << "Invalid value for cWay. Use 0 for normal way, 1 for cephalopod way." << endl;
        return 1;
    }
    vector<cpp_int> results;
    

    if(!cWay) {
        cout << "Solving normally..." << endl;
        vector<vector<string>> problems = parse_worksheet(inputFilePath);
        results = solve_problems(problems);
    }
    else{
        cout << "Solving cephalopod way..." << endl;
        auto lines = parse_worksheet_cephalopodway(inputFilePath);
        results = solve_problems_cephalopodway(lines);
    }  
    cpp_int grandTotal = 0;

    for (const auto& res : results) {
        grandTotal += res;
    }

    cout << "Grand Total: " << grandTotal << endl;

    return 0;
    
}