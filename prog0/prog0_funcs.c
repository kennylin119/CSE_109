
#include <stdio.h>
#include <stdlib.h>

/*
char parseArgs(int * argc, char *argv[]){
    
  if (*argc > 0){
      
  }
  if (strcmp(argv,"sop") == 0){ //equals 0 means two strings are equal
    return 0;
  } else if (strcmp(argv,"pos") == 0){
    return 0;
  } else if (strcmp(argv,"-h") == 0){
      
  } else {
    //some error happened
    return -1;
  }

  size_t unrep = 0;  /* for returning an indicator of overflow/underflow */
/*  return unrep;
}
  
void collectInput(char **name, int *number){
  //char name[20];
  printf("Enter first and last name (Cntl+D to exit):");   
  fgets(name, 20, stdin);
  printf("%s",name);
    
  int favInt;
  printf("Enter favorite integer (Cntl+D to exit):");
  scanf("%s",&favInt); 
  //printf("%d",number);
  printf("%s","test");
}

size_t calcValue(char soemthing, char **name, int number, long *result){
  char op = ' ';  /* for returning 
  return op;
}

void printResult(char op, long result, size_t unrep){
}

/* return code and message to print 
void bail(int temp, const char *changeLater){

}
*/
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
    

//int main(){
//help();
//return 0;
//}

