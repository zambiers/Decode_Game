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
    ~Decrypt();

    /*
      Main functions
    */
    bool code_assign(const string& filename, const string& key);
    string decode(const unordered_map<char, char>& decryption_mapping, const string& message);

    /*
      Helper functions
    */
    bool readFile(const string& filename); // Renamed from `getline` to avoid conflict

private:
    string input;
    string key;
    string message;
};