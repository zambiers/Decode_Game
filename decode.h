#pragma once
#include <iostream>
#include <string>
#include <vector>
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
  void encode(vector<string> text[]);
  void decode(const string input, vector<string> text[]);
  vector generate(vector<string> text[]);

/*
  Display functions
*/

  void print_encoded(vector<string> text[]);
  

private:
  string input;
  vector<string> text[];
  
/*
  Helper functions
*/

  void clear();

}
