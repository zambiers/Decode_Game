#include "decode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

/*
  Constructors and Desstructors
*/

Decrypt::Decrypt(): input(""), text(NULL){}

Decrypt::~Decrypt(){
    clear();
}


/*
  Main functions
*/

bool Decrypt::code_assign(const string& filename, bool encode){
  getCipher()


  return false;
}


bool Decrypt::input_correct(string input){


    return false;
}

bool Decrypt::encode(const string& filename, bool Key){

    ifstream inFile(filename);

    if(!inFile){
      return false;
    }

    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    

}

/*
    Helper Functions
*/

char Decrypt::getCipher(char ch, int shift){
    if (isalpha(ch)) {
        bool isUpper = isupper(ch);
        char base = isUpper ? 'A' : 'a';
        return base + (ch - base + shift + 26) % 26;
    } else {
        return ch;
    }
}

// void Decrypt::clear(){
  
// }