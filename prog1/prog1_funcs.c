#include <stdio.h>       /* for fprintf, sprintf */
#include <stdlib.h>      /* for exit */
#include <errno.h>       /* error handling */
#include <string.h>      /* for ? */
#include "prog1_funcs.h"
#include <unistd.h> //this is for the getopt function
#include <stdbool.h>


/* if we compile with gcc -DDEBUG, we will set the DEBUG macro to 1 */
#ifdef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

void *Malloc(size_t len){
  void *ptr;
  char str[128]; //this creates a char array of length 128
  if (ptr = (char *) malloc(len * sizeof(char) )  == NULL){
    sprintf(str, "Could not allocate space - %s", strerror(errno);
    bail(99, str);
  }
  return ptr;
} 

void help(){
  printf("prog1 performs an XOR-based encryption/decryption on the specified input file using the\n");
  printf("specified key file to produce the specified output file.\n \n");
  printf("prog1 -i|--input <input file> -o|--output <output file> -k|--key <key file> \n");
  printf("or\n");
  printf("prog1 [-h|--help]\n\n");
}

int containsDash(char *string){
  return (string[0] == '-');
}

void parseArgs(int argc, char *argv[], char **ifile, char **ofile, char **kfile){
    //help message 
  if (argc == 1){
    help();
    exit(0);
  }

  for (int i = 1; i < argc; i++){
    if (!strcasecmp(argv[i], "-o") || !strcasecmp(argv[i], "--output")){
      if (!containsDash(argv[++i]) ){
	*ofile = (char *) Malloc( strlen(argv[i]) + 1);
	strcpy(*ofile, argv[i]);
	 
      } else{
	bail(3, "No argument after '-o|--output' ");			     
      }
    } else if (!strcasecmp(argv[i], "-i") || !strcasecmp(argv[i], "--input")){
      if (!containsDash(argv[++i]) ){
	*ifile = (char *) Malloc(strlen(argv[i] + 1));
	strcpy(*ifile, argv[i]);
      } else{
	bail(4, "No argument after '-i|--input' ");			     
      }
    } else if (!strcasecmp(argv[i], "-k") || !strcasecmp(argv[i], "--key") ) {
      if (!containsDash(argv[++i] ) ) {
	*kfile = (char *) Malloc(strlen(argv[i] +1));
	strcpy(*kfile, argv[i]);
      } else {
	bail(5, "No argument after '-k|--key' ");			      
      }
    } else {
      bail(1, "incorrect/unexpected argument entered, run without any arguments or with '-h|--help");
    }
  }
  if (*ifile == NULL || *kfile == NULL || *ofile == NULL){
    bail(2, "One or more arguments not specified");
  }
}
  /*
    int opt = 0; //used to check that there is still args in the command line  
    int counter = 0;

    while ((opt = getopt(argc, argv, "hi:k:o:")) != -1){
    size_t len;
    switch(opt){
      
    case 'h':
    help();
    exit(0);
    break;
  
    case 'i':
    len = sizeof(optarg);
    *ifile = Malloc(len);
    for (int i = 0; i < len; i++){
    ifile[i] = &optarg[i];
    }
    counter += 1;
    break;

    case 'k':
    len = sizeof(optarg);
    *ofile = Malloc(len);
    for (int i = 0; i < len; i++){
    ifile[i] = &optarg[i];
    }
    counter += 1;
    break;


    case 'o':
    len = strlen(optarg);
    *ofile = Malloc(len);
    for (int i = 0; i < len; i++){
    ifile[i] = &optarg[i];
    }
    counter += 1;
    break;

    
    case '?':
    bail(14, "Incorrect/unexpected argument entered");
    break;
   
    default:
    bail(1, "Incorrect/unexpected argument entered");
    break;
    }

    if (counter < 1){
    bail(2, "One or more arguments not specified");  
    }
 
    } //end of while loop
  */  

  FILE *Fopen(const char *filename, const char *mode){
    FILE *filep;
    char str[128];
    
    if (filep = fopen(filename,mode) == NULL){
      sprintf(str, "Unable to open file - %s", strerror(errno));
      bail(10, str);
    } 
    return filep;
  }

  size_t Fwrite (const void * block, size_t numItems, size_t BLOCKSIZE, FILE * filename){
    fwrite(block, numItems, BLOCKSIZE, filename);
  }

  void Fclose(FILE *filename){
    fclose(filename);
    if (filename != NULL){
      bail(13, "Unable to close file *");
    }
  }

  size_t Fread(void * block, size_t numItems, size_t BLOCKSIZE, FILE * filename){
    fread(block, numItems, BLOCKSIZE, filename);
  }

  void readKey(unsigned char * key, size_t BLOCKSIZE, FILE * fkp){
    char str[128];
    if ( (size_t numItems = Fread(key, 1, BLOCKSIZE, fkp) ) != 0){
      sprintf(str, "Error reading file - %s", strerror(errno);
      bail(11, str);    
    }
  }

  void encryptDecrypt(unsigned char * block, unsigned char * key, size_t BLOCKSIZE, FILE * fip, FILE * fop){
    size_t numItems;
    while ( (numItems = Fread(block, sizeof(char) , BLOCKSIZE, fip)) != 0){
      for (int i = 0; i < numItems; i++) {
	if (DEBUG) fprintf(stdout, "(%#04X) ^ (%#04X) = ", block[i], key[i]);
	block[i] = block[i] ^ key[i];
	if (DEBUG) fprintf(stdout, "(%#04X)\n", block[i]);
      }
      Fwrite(block, 1, numItems, fop);
    }
  }

  void bail(int rc, const char *msg) {
    fprintf(stderr, "(%d) %s\n", rc, msg);
    exit(rc);
  }

