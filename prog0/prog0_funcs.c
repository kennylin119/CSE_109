#include <stdio.h>
#include <stdlib.h>
#include "prog0_funcs.h"
#include <string.h>

//this is to test save

char parseArgs(int argc, char *argv[]){
  char op = ' ';  /* for returning */
  
  if (argc == 2){
    if (strcmp(argv[1],"sop") == 0){ //equals 0 means two strings are equal
      op = '0';
    } else if (strcmp(argv[1],"pos") == 0){
      op = '1';
    } else if (strcmp(argv[1],"-h") == 0){
      help();
      exit(2);
    } else {
      bail(1, "Enter a single argument of either 'sop', 'pos', or '-h' (for help)\n\n");
    }
  } else {
    bail(2, "Enter a single argument of either 'sop', 'pos', or '-h' (for help)\n\n");
  }
  return op;
}

void collectInput(char **name, int *number){
  size_t length = 0;

  printf("Enter first and last name (Cntl+D to exit):");   
  getline(*&name, &length, stdin);

  printf("Enter favorite integer (Cntl+D to exit):");
  number = scanf("%d",number);
}

void removeSpace(char *text){
  int len = strlen(text) -1;
  char newText[len];
  
  int spacesRemoved = 0;
  int temp = 0; 
  for (int i = 0; i < len; i++){
    if (text[i] != ' '){
      newText[temp] =  text[i];
      temp += 1;
    } else{
      spacesRemoved += 1;
    }
  }
  
  for (int i = 0; i < len - spacesRemoved;i++){
    text[i] = newText[i];
  }  
  text[len-spacesRemoved] = 0;
}

//product of sums
long pos(char **name, int number){
  
  removeSpace(&**name);
  
  long product = 1;
  int len = strlen(*name);
  int temp = 0;

  for (int i = 0; i < len; i++){
    
    int numChar = (int) ((*name)[i]);
    int sum = number + numChar;
    product *= sum;
    
    if (temp > product){
      bail(3,"underflow or overflow occurred \n");
    } else{
      temp = product;
    }
    
  }
  return product;
}

//sum of products
long sop(char **name, int number){
  removeSpace(&**name);
  
  long sum = 0;
  int temp = 0; //for checking overflow
  
  int len = strlen(*name);
  for (int i = 0; i < len; i++){
    int numChar = (int) ((*name)[i]);
    int product = number * numChar;
    sum += product;
    if (temp > sum){
      bail(3,"underflow or overflow occurred \n");
    } else{
      temp = sum;
    } 
  }
  return sum;
}

size_t calcValue(char op, char **name, int number, long *result){
  
  long ans;
  if (op == '0'){ //this means sop
    ans = sop(name, number);
  } else if (op == '1'){
    ans = pos(name, number);
  }
  
  *result = ans;
  
  size_t unrep = 0;  /* for returning an indicator of overflow/underflow */
  return unrep;
}


void printResult(char op, long result, size_t unrep){
  if (op == '0'){
    printf("sop \n");
  } else if (op == '1'){
    printf("pos \n");
  } else{
    bail(2, "wrong operation yo");
 }
  printf("%ld \n", result); 
}

/* return code and message to print */
void bail(int err, const char *message){
  fprintf(stderr, "(%d): %s", err, message);
  exit(0);
}

void help(){
  printf("\
prog0 prompts the user for their first and last name and their favorite integer and\n\
calculates the sum-of-products or product-of-sums based on the integer entered and\n\
the ASCII value of each character in the first and last name entered. Note that\n\
non-alphabetical characters, except for hyphen and apostrophe, are ignored.\n\
\n\
* If the user enters 'sop' or 'pos' (case-insensitive) as the only argument, the\n\
  user will be prompted to enter their first and last name and their favorite integer,\n\
  and the program will calculate the sum-of-products or product-of-sums, respectively.\n\
* If the user enters '-h' (case-insensitive) as the only argument, this help message\n\
  will be displayed on stdout.\n\
* If the user does not provide any arguments or provides too many arguments, an error\n\
  message is printed to stderr and the return code will be 1.\n\
* If the user enters an invalid single argument, an error message is printed to stderr\n\
  and the return code will be 2.\n\
* If the calculation results in an overflow/underflow, the program will continue to run\n\
  and operate normally, but the return code will be 3.\n\
* The user can expect prompts on stdout as follows:\n\
        Enter first and last name (Cntl+D to exit):\n\
        Enter favorite integer (Cntl+D to exit):\n\
* The user can expect outputs on stdout as follows, where 'mode' is either 'sop'\n" );
}
    

