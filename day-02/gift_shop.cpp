/*
Advent of Code - Day 2: Gift Shop

Given a set of numeric ID ranges, identify all invalid product IDs.
An ID is considered invalid if it consists of a sequence of digits
part 1: repeated exactly twice (e.g., 11, 6464, 123123).
part 2: repeated atleast twice (e.g., 12341234, 123123123, 1111111).
The task is to scan all provided ranges, find every invalid ID,
and return the sum of those invalid values.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool isInvalidID(long long id) {
    /*

    // for part 1: repeated exactly twice

    string idStr = to_string(id);
    size_t len = idStr.length();
    if (len % 2 != 0) return false; // Must be even length to be repeated twice

    string firstHalf = idStr.substr(0, len / 2);
    string secondHalf = idStr.substr(len / 2);

    return firstHalf == secondHalf;
    
    */ 

    // for part 2: repeated atleast twice
    string idStr = to_string(id);
    size_t len = idStr.length();
    for (size_t subLen = 1; subLen <= len / 2; subLen++) {
        // if (len % subLen != 0) continue; // Must divide evenly
        string pattern = idStr.substr(0, subLen);
        string repeated;
        for (size_t i = 0; i < len / subLen; i++) {
            repeated += pattern;    
        }
        if (repeated == idStr) {
            return true;
        }
    }
    return false;
}

long long sumInvalidIDsInRange(long start, long end) {
    long long sum = 0;
    for (long id = start; id <= end; id++) {
        if (isInvalidID(id)) {
            sum += id;
        }
    }
    return sum;
}

vector<pair<long long, long long>> readRangesFromFile(const string& filename) {
    vector<pair<long long, long long>> ranges;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return ranges;
    }
    string line;
    while (getline(file, line,',')) {
        stringstream ss(line);
        long long start, end;
        char dash;
        if (ss >> start >> dash >> end) {
            ranges.emplace_back(start, end);
        }
    }
    file.close();
    return ranges;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Usage: " << argv[0] << " <path_to_input_file>" << endl;
        return 1;
    }
    string inputFilePath = argv[1];
    vector<pair<long long, long long>> ranges = readRangesFromFile(inputFilePath);
    long long totalSum = 0;
    for (const auto& range : ranges) {
        totalSum += sumInvalidIDsInRange(range.first, range.second);
    }
    cout << "Total sum of invalid product IDs: " << totalSum << endl;
    return 0;
}
