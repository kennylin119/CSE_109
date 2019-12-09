/*
 * Course: CSE109
 * Semester and Year: Fall 2019
 * Assignment: Count
 * File Purpose: contains functions for parsing through user input
 * Author: Lin, Kenny
 * User ID: kel422
 */


#include "prog4_funcs.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

//use vector, string, accumulate libraries

//using typedef instead of using namespace std
//typedef std::cout cout_std;
//typedef std::cin cin_std;
//typedef std::cerr cerr_std;
//typedef std::endl endl_std;


//using namespace std;

void parseArgs(int argc, char* argv[]){
  
  switch(argc){
  
    //only one argument
  case 1: {    
    break;
  }
  default: {
    help();
    exit(0);
  }

  }
}

void parseFile(Count * count){
  
  std::string input;
  std::vector<std::string> v;
  
  //this is getting user input
  while(getline(std::cin, input)){
    //this will handle the CTRL - D case 
    if (std::cin.eof()){
      exit(0);
    }
    v.push_back(input + "\n"); 
  }
  
  //this is iterating through the user input
  std::vector<std::string>::iterator it;
  for (it = v.begin(); it != v.end(); it++){
    //std::cout << *it << '\n';
    for (unsigned int i = 0; i < (*it).size(); i++){
      
      switch((int) (*it)[i]){
      case 'a'...'z':
	count->increment( (*it)[i], (*it)[i] - 97);
	break;
      case 'A'...'Z':
	count->increment( (*it)[i], (*it)[i] - 65);
	break;
      case 48 ... 57:
	count->increment( (*it)[i], (*it)[i] - 48);
	break;
      case ' ':
	count->increment('w');
	break;
      case '\n':
	count->increment('l');
	break;
      case 128 ... 255:
	//extedned ASCII
	count->increment('e');
	break;
      default: 
	count->increment('o');
      }
    }/*
       for (int i = 0; i < v.size(); i++){
       std::cout << v[i] << '\n';
       }*/
    
  }
}
  //const char* is a mutable pointer to an immutable character/string
  //thus the contents of msg cannot be changed
  void bail(int returnCode, const char *msg){
    std::cerr << "(" << returnCode << ")" << msg << "\n";
    exit(returnCode);
  }

  //help not in .h file might have to move this up
  void help(){
    std::cout << "This program counts the occurrences of each type of byte streaming from STDIN."
      "Specifically, it will count occurrences of each letter (regardless of case),"
      "each digit, each whitespace, all other printable characters (except extended-ASCII),"
      "all extended-ASCII characters, and all newline characters."
      "\n"
      "Usage: prog4 < someFile"
      "     or"
      "   prog4                  (Note: type input followed by Cntl+D)"
	      << std::endl;
  }
