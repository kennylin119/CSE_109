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

size_t totalBuckets;
size_t percentUsage;
size_t worstChainLength;
size_t usedBuckets;

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
      if (++i >= argc){
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

Node** createHashTable(Node **currHTptr, size_t initialBuckets){
  Node** hashTable;
  usedBuckets = initialBuckets * .75;

  if (initialBuckets < 1){
    return NULL;
  }
  
  if (currHTptr == NULL){
    //allocates table entries
    hashTable = (Node**) Malloc(sizeof(Node*) * initialBuckets); 
    totalBuckets += initialBuckets;
    for (uint i = 0; i < initialBuckets; i++){
      hashTable[i] = NULL;
    }
  } else{
    //might need to free currHTptr
    currHTptr = (Node **) Malloc(sizeof(Node*) * totalBuckets);
    hashTable = currHTptr;
  }
  
  return hashTable;
}

uint32_t hash(uint64_t key){
  uint32_t hash = 5381;
  uint8_t byte;

  for (uint8_t i = 0; i < 8; i++) {             /* iterate over bytes in the key */
    byte = key & 0xFF;                 /* shift right the key a multiple of 8 bits and AND it with b11111111, to obtain a more significant byte each time */
    hash = ((hash << 5) + hash) ^ (uint8_t) byte;         /* multiply hash by 33 and XOR with byte */
    key >>= 8;
  }

  return hash;
}

void copyHashTable(Node **newHTptr, Node **currHTptr, size_t sizeCurrHt){
  totalBuckets = sizeCurrHt * (1.0 + (sizeCurrHt * (RESIZEPERCENTAGE / 100.0) ) );
  newHTptr = createHashTable(currHTptr, totalBuckets);
  
  for (uint i = 0; i < sizeCurrHt; i++){
    if (currHTptr[i] != NULL){
      /*size_t newIndex = hash(currHTptr[i]->key) % newSize;
	newHTptr[newIndex] = currHTptr[i];
      */
      
      create(newHTptr, (currHTptr[i])->key, (currHTptr[i])->value);
      while ( (currHTptr[i])->next != NULL){
	Node *nextNode = currHTptr[i]->next;
	create(newHTptr, nextNode->key, nextNode->value);	  
      }
    }
  }
}

int create(Node **HTptr, uint64_t key, int value){
  uint32_t index = hash(key) % totalBuckets;
  //0 for success, 1 for update
  
  Node *currNode = (Node*) Malloc(sizeof(Node));
  
  //for (int i = 0; i < totalBuckets; i++){    
  
  if (currNode != NULL){
    if(currNode->key == key){
      update(HTptr, key, value);
      return 1;
    }
  }

  /*else if (currNode == NULL){
    currNode->value = value;
    currNode->key = key;
    currNode->next = NULL;
    return 0;
    }*/

  //else { //(currNode != NULL){
      
  currNode->value = value;
  currNode->key = key;
  currNode->next = NULL;

  //Node *prevNode = currNode; 
  //Node *newNode = NULL;

  //this loops until you reach end of linked list
  while (currNode->next != NULL){
    //prevNode = currNode;
    if (currNode->key == key){
      update(HTptr, key, value);
      return 1;
    }
    currNode = currNode->next;
  }
    
  //currNode = prevNode;
  //currNode->next = newNode;

  //this is the newly created Node
  /*newNode->value = value;
  newNode->key = key;
  newNode->next = NULL;
  */
  
  HTptr[index] = currNode;
  return 0;
}

int update(Node **HTptr, uint64_t key, int value){
  uint32_t index = hash(key) % totalBuckets;
  if ( (HTptr[index]) == NULL){
    //create node
    create(HTptr, key, value);
    return 1;
  } else {
    HTptr[index]->value = value;
    HTptr[index]->key = key;
    return 0;
  }
  //return 0 for success or 1 when create occured
}

int read(Node **HTptr, uint64_t key, int *value){
  uint32_t index = hash(key) % totalBuckets;
  if ( (HTptr[index])->value == '\0' ){
    //issue warning
    printf("your index value is null just fyi");
    return 2;
  } else{
    value = &(HTptr[index]->value);
    return 0;
  }
}

int delete(Node **HTptr, uint64_t key){
  uint32_t index = hash(key) % totalBuckets;

  //is this part neccessary? 
  HTptr[index]->value = 0;
  HTptr[index]->key = 0;
  HTptr[index]->next = NULL;

  if (HTptr[index]->value == 0 && HTptr[index]->key == 0
      && HTptr[index]->next == NULL){
    return 0;
  } else{
    //was unsuccessful
    return 2;
  }
}

Node** runHashCommands(Node **HTptr, FILE *cmdFilePtr){
  char *line = NULL;
  char input[10][10];
  size_t len = 0;
  int in = 0;
  
  char cmd;
  int value;
  uint64_t key;
  
  while ( (in = (getline(&line, &len, cmdFilePtr)) ) != -1){
    
    //iterating variables
    sscanf(line, "%c %d %lu", &cmd, &value, &key); 

    //c -create r -read u -update d delete
    if (cmd == 'c'){
      //int create(Node **HTptr, uint64_t key, int value){
      create(HTptr, key, value); 
    }

    else if (cmd == 'r'){
      //int read(Node **HTptr, uint64_t key, int *value){
      read(HTptr, key, &value);
    }
    
    else if (cmd == 'u'){
      //int update(Node **HTptr, uint64_t key, int value){
      update(HTptr, key, value);
    }

  }
    
  Fclose(cmdFilePtr);
  getHashTableStats(HTptr);
  printHashTableStats();
  return HTptr;
}

void getHashTableStats(Node **HTptr){
  worstChainLength = 5;
  percentUsage = usedBuckets * 1.0  / totalBuckets; 
}

void printHashTableStats(){
  //print global variables
  fprintf(stdout, "Stats at end: %ld buckets, %ld percent of buckets used, worst chain length = %ld \n", totalBuckets, usedBuckets, worstChainLength);
}

void freeHashTable(Node **HTptr){
  for (uint i = 0; i < totalBuckets; i++){
    if ( (HTptr[i] != NULL) ){
      free((HTptr[i])->next);
      }
    free(HTptr[i]);
  }
  free(HTptr);
}

void *Malloc(size_t len){
  void *ptr;
  char str[128];
  
  if ( (ptr = malloc(len)) == NULL){
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
    sprintf(str, "Unable to close file descriptor %d - %s", fileno(filename), strerror(errno) ); 
    bail(13, str);
  }
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
  printf("prog2 [-h|--help] \n");
  exit(0);
}
