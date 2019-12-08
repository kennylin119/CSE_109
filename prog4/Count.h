#ifndef COUNT
#define COUNT

#include <iostream>  // for C++ I/O
#include <vector>    // for vector

class Count {
public:
  Count();                                                      // constructor: initialize category counts
  void increment(char);                                         // setter: increment whitespace, other, or extended counts
  void increment(char, unsigned char);                          // setter: increment letter or digit counts
  unsigned int getTotal();                                      // getter: return total of all counts
  friend std::ostream & operator <<(std::ostream &, Count &);   // <<operator: support printing of counts
  ~Count();                                                     // destrucotr: print counts and total when done
private:
  std::vector<unsigned int> numLetter{26};
  std::vector<unsigned int> numDigit{10};
  unsigned int numWhiteSpace = 0;
  unsigned int numOther = 0;
  unsigned int numExtended = 0;
  unsigned int numNewline = 0;
};

#endif
