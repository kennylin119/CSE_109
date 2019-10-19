#define RUNTIMES 1
#define BUCKETS 100
#include <stdint.h>   /* for uint32_t (4 byte) and uint64_t (8 byte) types */
#include <stdlib.h>   /* for random function */
#include <stdio.h>    /* for fprintf function */
#include "deBits.h"   /* for DE's printBits function */

uint64_t genRandom8Bkey();                      /* uint64_t is an unsigned 64-bit (8-byte) integer */
uint32_t gen4Bhash_PointerVersion(uint64_t);    /* uint32_t is an unsigned 32-bit (4-byte) integer */
uint32_t gen4Bhash_MaskVersion(uint64_t);       /* uint32_t is an unsigned 32-bit (4-byte) integer */

/* nothing to change in this function */
int main() {
  for (size_t i = 0; i < RUNTIMES; i++) {
    uint64_t key  = genRandom8Bkey();                 /* call genRandom8Bkey which returns a random 8-byte key */
    uint32_t hash = gen4Bhash_PointerVersion(key);    /* call gen4Bhash_PointerVersion which returns a 4-byte hash value from the 8-byte key */
    fprintf(stdout, "%ckey = %20lu -> hash = %10u -> hash table index = %2u%c\n", i==0?'\n':'\0', key, hash, hash % BUCKETS, i==RUNTIMES-1?'\n':'\0');  
             hash = gen4Bhash_MaskVersion(key);       /* call gen4Bhash_MaskVersion which returns a 4-byte hash value from the 8-byte key */
    fprintf(stdout, "%ckey = %20lu -> hash = %10u -> hash table index = %2u%c\n", i==0?'\n':'\0', key, hash, hash % BUCKETS, i==RUNTIMES-1?'\n':'\0');  
  }
  return 0;
}

/* nothing to change in this function */
uint64_t genRandom8Bkey() {                    /* call random and shift its result 4 bytes to the left, then */
  return random() << 32 | random();            /* OR that result with the result from another random call */
}

/* change the function below */
uint32_t gen4Bhash_PointerVersion(uint64_t key) {
  uint32_t hash;
  char * begKey = &key;
  hash = (uint32_t) key;                        /* this is temporary; you need to replace this with an actual, iterative, hash function */
  
  for (int i = 0; i < 8; i++){
    hash = (( hash << 5) + hash) ^ (uint8_t) begKey[i];
  }

  return hash;
}

/* change the function below */
uint32_t gen4Bhash_MaskVersion(uint64_t key) {
  uint32_t hash;

  hash = (uint32_t)key;                        /* this is temporary; you need to replace this with an actual, iterative, hash function */
  for (int i = 0; i < 8; i++){
    uint32_t mask = ((key >> ( i * 8)) & 0xFF);    
    hash = (( hash << 5) + hash) ^ mask;
  }
  return hash;
}

