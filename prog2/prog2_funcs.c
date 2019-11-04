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

typedef struct {
  Node **entries; //this defines an array of nodes
} hT;

Node ** createHashTable(Node **currHTptr, size_t numBuckets){
  if (numBuckets < 1){
    return NULL;
  }

  //allocates table
  hT *hashTable = malloc(sizeof(hT) * 1); 

  //allocates table entries 
  hashTable->entries = malloc(sizeof(Node) * numBuckets); 
  
  //create array of nodes, populate all with nulls
  
  return hashTable;
  //return pointer to new hash table
}

void copyHashTable(Node **newHTptr, size_t sizeCurrHT){
  
}

int create(Node **HTptr, uint64_t key, int value){
  //return 0 for success or 1 when update occured  
  return 0;
}

int update(Node ** HTptr, uint64_t key, int value){
  //return 0 for success or 1 when create occured  
  return 0;
}

int read(Node **HTptr, uint64_t something){
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
