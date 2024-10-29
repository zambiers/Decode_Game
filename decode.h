#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

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

  bool input_correct(string input);

  bool encode(const string& filename, bool Key);
  bool code_assign(const string& filename, bool encode);

/*
  Helper functions
*/

  char getCipher(char ch, int shift);
  

/*
  Display functions
*/

  // void print_encoded(vector<string> text[]);
  

private:
  string input;
  vector<string> text[];
  
/*
  Helper functions
*/


}
