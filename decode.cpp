#include "decode.h"

#include <iostream>
#include <ifstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex> // to look for a pattern

using namespace std;

/*
  Constructors and Destructors
*/

Decrypt::Decrypt(): input(""), text(NULL){}

Decrypt::~Decrypt(){
    clear();
}

/*
    Helper Functions
*/


/*
  This function will read in the file, look for the encryption key
  then sends that information for assignment
*/
bool Decrypt::getline(const string& filename){
  ifstream inFile(filename);

    if(!inFile){
      return false;
    }

    string line;

    while(getline(inFile, line) ){
      size_t grabKey = line.find("Encryption Key: ");

      if(grabKey != string::npos){

        if(!code_assign(filename, line.substr(pos + 16)) ){
          cerr << "Could not grab key for encryption for: " << filename << end;
        }

        return true;
      }

    }
    
    cerr << "Encryption key not found in: " << filename << endl;
    return false;
}

/*
  Main functions
*/

/*  
  Code_assign will take the key, create an unordered map to send for decryption
*/
bool Decrypt::code_assign(const string& filename, const string& Key){
  
  if(key == NULL){
    cerr << "Key not found in file: " << filename << endl;
    return false;
  }
  
  unordered_map<char, int> freq;

  for( char c : encodeKey){
    encodeKey++;
    decode(freq, key, message);
  }

  return false;
}

string Decrypt::decode(unordered_map<char, int>& freq, const string& Key, string& message){
  
  return
}


bool Decrypt::input_correct(const string& input, const string& Key){
    return false;
}

// bool Decrypt::encode(const string& filename, bool Key){

// }
