
To link your .cpp and .h files, here’s what you need to address and adjust in each file. There are a few mismatches between function signatures in your header and implementation files, so I’ll help align them.

Updated .h File (decode.h)
Ensure that the header file has correct function signatures matching the implementation file. In this case, the code_assign function should not take filename as a parameter, and you may want to add readFile and clear functions as public if they’ll be called from main.

cpp
Copy code
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

class Decrypt {
public:
    /*
      Constructors and Destructors
    */
    Decrypt();

    /*
      Main functions
    */
    bool readFile(const string& filename); // Renamed from `getline` to avoid conflict
    bool code_assign(const string& key); // Remove `filename` parameter
    string decode(const unordered_map<char, char>& decryption_mapping, const string& message);

    /*
      Other utilities
    */
    void clear();

private:
    string input;
    string key;
    string message;
    unordered_map<char, char> decryption_mapping; // Added this since it's used in the cpp file
};