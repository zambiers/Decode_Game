#pragma once
#include <iostream>
#include <string>
using namespace std;

class Decrypt{
public:
/*
  Constructors and Desstructors
*/

  Decrypt();
  ~Decrypt();

/*
  Main functions
*/

  bool input_correct();
  void encode();


private:
  string input;
  string text;
  string generate;
  
/*
  Helper functions
*/

  void clear();

}
