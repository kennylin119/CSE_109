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
#include "prog2_funcs.h"
#include "global_defs.h"

void parseArgs(int argc, char *argv[]){

}

Node ** createHashTable(Node **currHTptr, size_t numBuckets){
  return 0;
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

Node **runHashCommands(Node **HTptr, FILE *cmdFilePtr){
  
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
  ptr = (char *) malloc(len * sizeof(char) );
  if (ptr == NULL){
    bail(99, "Could not allocate space *");
  }
  return ptr;
}

FILE *Fopen (const char *filename, const char *mode){
  //return file pointer
  FILE *filep;
  filep = fopen(filename,mode);
  if (filep == NULL){
    bail(10, "Unable to open file *");
  }
  return filep;

}

void Fclose(FILE *filename){
  fclose(filename);
  if (filename != NULL){
    bail(13, "Unable to close file *");
  }
}

void bail(int rCode, const char *msg){
  fprintf(stderr, "(%d) %s\n", rCode, msg);
  exit(rCode);
}

void help(){
}
