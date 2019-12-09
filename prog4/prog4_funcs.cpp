/*
 * Course: CSE109
 * Semester and Year: Fall 2019
 * Assignment: Count
 * File Purpose: contains functions for parsing through user input
 * Author: Lin, Kenny
 * User ID: kel422
 */


#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "prog4_funcs.h"

//use vector, string, accumulate libraries

//using typedef instead of using namespace std
//typedef std::cout cout_std;
//typedef std::cin cin_std;
//typedef std::cerr cerr_std;
//typedef std::endl endl_std;


//using namespace std;

void parseargs(int argc, int* argv[]){
  
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

void parseFile(Count &count){
  std::string input;
  std::vector<std::string> v;

  while(std::getline(std::cin, input)){
    //this will handle the CTRL - D case 
    if (std::cin.eof()){
      exit(0);
    }
    v.push_back(input);  
  }
  
  std::vector<std::string>::iterator it;

  for (it = v.begin(); it != v.end(); it++){
    std::cout << *it << '\n';
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
