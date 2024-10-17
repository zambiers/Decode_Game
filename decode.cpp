#include "decode.h"
#include <iostream>
#include <string>
using namespace std;

/*
  Constructors and Desstructors
*/

Decrypt::Decrypt(): input(""), text(NULL), generate(NULL){}

Decrypt::~Decrypt(){
    clear();
}

int Decrypt::length(){
//Case: text was not generated so it is null
  if(text == NULL){
    return -1;
  }

  


}

/*
  Main functions
*/

bool Decrypt::input_correct(){
  
  // for(int i = 0; i = text.size(); i++){

  // }
    return false;
}

void Decrypt::encode(){

}


/*
    Helper Functions
*/
void Decrypt::clear(){
  
}