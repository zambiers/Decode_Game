#include "decode.h"

#include <iostream>
#include <ifstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex> // to look for a pattern

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // vector<string> lines;
    // string line;

    // while (getline(file, line)) {
    //     lines.push_back(line);
    // }

    // file.close();

    // // Process the lines
    // for (const auto& line : lines) {
    //     cout << line << endl;
    // }

    return 0;
}