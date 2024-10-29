#pragma once

#include <iostream>
#include <ifstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex> // to look for a pattern

using namespace std;

class Decrypt{
public:
/*
  Constructors and Desstructors
*/

  Decrypt();
  ~Decrypt();

  int size();

/*
  Main functions
*/

  bool input_correct(string input, const string& Key);
  bool code_assign(const string& filename, const string& Key);

  string decode(unordered_map<char, int>& freq, const string& Key, string& message);

/*
  Helper functions
*/
  bool getline(const string& filename);

/*
  Display functions
*/

  // void print_encoded(vector<string> text[]);
  

private:
  string input;
  string Key;
  string message;
  
/*
  Helper functions
*/


}
