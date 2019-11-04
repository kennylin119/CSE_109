
/* 
   Course: CSE109
   Semester and Year: Fall 2019
   Assignment: Hash Table
   Author: Lin, Kenny 
   User ID: userid 
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //for unit32_t and uint64_t
#include "global_defs.h" 
#include "prog2_funcs.h"
#include <errno.h>
#include <string.h>

void parseArgs(int argc, char *argv[]){
  //if there are no args print help()
  if (argc == 1){
    help();
  }
  for (int i = 1; i < argc; i++){
    //if not different, return nonzero
    if ( (!strcasecmp(argv[i], "-h")) || (!strcasecmp(argv[i], "--help")) ) {
      help();
    } else if((!strcasecmp(argv[i], "-i")) || (!strcasecmp(argv[i], "--input")) ) {
      if (++i > argc){
	//missing input arg
	bail(3, "No argument after '-i|--input'");
      }
    } else{
      bail(1, "Incorrect/unexpected argument entered");
    }
  }
}

/*
typedef struct {
  Node **array; //this defines an array of nodes
} hT;
*/

Node** createHashTable(Node **currHTptr, size_t numBuckets){
  Node** hashTable;
  if (numBuckets < 1){
    return NULL;
  }
  if (currHTptr == NULL){
    //allocates table entries 
    hashTable = malloc(sizeof(Node*) * numBuckets); 
  
    for (uint i = 0; i < numBuckets; i++){
      hashTable[i] = NULL;
    }
  } else{
    *currHTptr = malloc(sizeof(Node*) * numBuckets);
    hashTable = currHTptr;
  }
  
  return hashTable;
}

uint32_t hash(uint64_t key){
  uint32_t hash = 5381;
  uint8_t byte;

  //fprintf(stdout, "key = "); print8Bytes(key); fprintf(stdout, " (%lu)\n", key);
  //fprintf(stdout, "initial hash = "); print4Bytes(hash); fprintf(stdout, " (%u)\n", hash);
  for (uint8_t i = 0; i < 8; i++) {             /* iterate over bytes in the key */
    byte = key & 0xFF;                 /* shift right the key a multiple of 8 bits and AND it with b11111111, to obtain a more significant byte each time */
    /*switch (i) {
      case 0 : fprintf(stdout, "first  "); break;
      case 1 : fprintf(stdout, "second "); break;
      case 2 : fprintf(stdout, "third  "); break;
      case 3 : fprintf(stdout, "fourth "); break;
      case 4 : fprintf(stdout, "fifth  "); break;
      case 5 : fprintf(stdout, "sixth  "); break;
      case 6 : fprintf(stdout, "seventh"); break;
      case 7 : fprintf(stdout, "eighth "); break;
    }
    fprintf(stdout, " byte of key = "); print1Byte(byte); fprintf(stdout, "\n");*/
    
    hash = ((hash << 5) + hash) ^ (uint8_t) byte;         /* multiply hash by 33 and XOR with byte */
    //fprintf(stdout, "intermediate hash value multiplied by 33 and XOR'd with a byte of the key = "); print4Bytes(hash); fprintf(stdout, "\n");
    key >>= 8;
  }

  return hash;
}

void copyHashTable(Node **newHTptr, Node **currHTptr, size_t sizeCurrHt){
  
}

int create(Node **HTptr, uint64_t key, int value){
  //return 0 for success or 1 when update occured  
  return 0;
}

int update(Node **HTptr, uint64_t key, int value){
  //return 0 for success or 1 when create occured  
  return 0;
}

int read(Node **HTptr, uint64_t key, int *value){
  return 0;
}

int delete(Node **HTptr, uint64_t key){
  return 0;
}

Node** runHashCommands(Node **HTptr, FILE *cmdFilePtr){
  return HTptr;
}

void getHashTableStats(Node **HTptr){

}

void printHashTableStats(){
  //print global variables 
}

void freeHashTable(Node ** HTptr){
  
}

void *Malloc(size_t len){
  void *ptr;
  char str[128];
  
  if ( (ptr = (char *) malloc(len * sizeof(char))) == NULL){
    sprintf(str, "Could not allocate space - %s", strerror(errno));
    bail(99, str);  
  }
  return ptr;
}

FILE* Fopen (const char *filename, const char *mode){
  
  char str[128];
  FILE *filep;
  
  if ( (filep = fopen(filename,mode)) == NULL){
    sprintf(str, "Unable to open %s with mode %s - %s", filename, mode, strerror(errno)); 
    bail(10, str);
  }
  return filep;

}

void Fclose(FILE *filename){
  char str[128];
  
  //filename != NULL && fclose fails
  //fclose returns 0 if it fails 
  if (filename && fclose(filename) ){
      sprintf(str, "Unable to close file descriptor %d - s", fileno(filename), strerror(errno) ); 
  }
    bail(13, str);
}

void bail(int rCode, const char *msg){
  fprintf(stderr, "(%d) %s\n", rCode, msg);
  exit(rCode);
}

void help(){
  printf("\n");
  printf("prog2 prog2 creates, retrieves, updates, and deletes key-value pairs in a hash table.\n");
  printf("The table auto-resizes to maintain “optimum” performance. Run program as follows.\n");
  printf("prog2 -i|--input <input file>\n");
  printf("      or\n");
  printf("prog2 [-h|--help]");
  exit(0);
}
