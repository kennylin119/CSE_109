/*
 * Course: CSE109
 * Semester and Year: Fall 2019
 * Assignment: Count
 * File Purpose: counts the amount of bytes in each category
 * Author: Lin, Kenny
 * User ID: kel422
 */

#include "Count.h"
#include <iostream>  // for C++ I/O
#include <vector>    // for vector
#include <numeric>

Count::Count(){
  // constructor: initialize category counts

  //set vectors to 0
  //numLetter(26, 0);
  //numDigit(10, 0);
  std::fill(numLetter.begin(), numLetter.end(), 0);
  std::fill(numDigit.begin(), numDigit.end(), 0);
    
  //set variables to 0
  numWhiteSpace = 0;
  numOther = 0;
  numExtended = 0;
  numNewline = 0;

  std::cout << "Count object and category counts initialized" << std::endl;
}
  
void Count::increment(char signifier){
  // setter: increment whitespace, other, or extended counts
  switch(signifier){
  case 'w':
    numWhiteSpace += 1;
    break;
  case 'o':
    numOther += 1;
    break;
  case 'e':
    numExtended += 1;
    break;
  case 'l':
    numNewline += 1;
    break;
  }
}
  
void Count::increment(char value, unsigned char index){
  // setter: increment letter or digit counts
  switch(value){
  case 'a'...'z':
    numLetter[index] += 1;
    break;
  default:
    numDigit[index] += 1;
    break;
  }
}
  
unsigned int Count::getTotal(){
  // getter: return total of all counts
  int sum = 0;
  accumulate(numLetter.begin(), numLetter.end(), sum);
  accumulate(numDigit.begin(), numDigit.end(), sum);

  sum += numWhiteSpace;
  sum += numWhiteSpace;
  sum += numWhiteSpace;

  return sum;
}
  
 std::ostream & operator <<(std::ostream & output, Count & count){
   // <<operator: support printing of counts
   
}
  
Count::~Count(){
  // destrucotr: print counts and total when done
  std::cout << numWhiteSpace << "/n";
  std::cout << numOther << "/n";
  std::cout << numExtended << "/n";
  std::cout << numNewline << "/n";

  std::cout << "Count object destroyed" << std::endl;
}
  
