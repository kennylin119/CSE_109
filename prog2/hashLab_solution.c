#define RUNTIMES 1
#define BUCKETS 100
#include <stdint.h>   /* for uint32_t (4 byte) and uint64_t (8 byte) types */
#include <stdlib.h>   /* for random function */
#include <stdio.h>    /* for fprintf function */
#include "deBits.h"   /* for DE's printBits function */

uint64_t genRandom8Bkey();       /* uint64_t is an unsigned 64-bit (8-byte) integer */

uint32_t gen4BhashDE_PointerVersion(uint64_t);  /* remove */
uint32_t gen4BhashDE_MaskVersion(uint64_t);     /* remove */

int main() {
  for (size_t i = 0; i < RUNTIMES; i++) {
    uint64_t key  = genRandom8Bkey();          /* call genRandom8Bkey which returns a random 8-byte key */
    uint32_t hash = gen4BhashDE_MaskVersion(key);            /* call gen4Bhash which returns a 4-byte hash value from the 8-byte key */
    fprintf(stdout, "%ckey = %20lu -> hash = %10u -> hash table index = %2u%c\n", i==0?'\n':'\0', key, hash, hash % BUCKETS, i==RUNTIMES-1?'\n':'\0');  
             hash = gen4BhashDE_PointerVersion(key);            /* call gen4Bhash which returns a 4-byte hash value from the 8-byte key */
    fprintf(stdout, "%ckey = %20lu -> hash = %10u -> hash table index = %2u%c\n", i==0?'\n':'\0', key, hash, hash % BUCKETS, i==RUNTIMES-1?'\n':'\0');  
  }
  return 0;
}

uint64_t genRandom8Bkey() {                    /* call random and shift its result 4 bytes to the left, then */
  return random() << 32 | random();            /* OR that result with the result from another random call */
}

uint32_t gen4BhashDE_MaskVersion(uint64_t key) {    /* remove */
  uint32_t hash = 5381;
  uint8_t byte;

  fprintf(stdout, "key = "); print8Bytes(key); fprintf(stdout, " (%lu)\n", key);
  fprintf(stdout, "initial hash = "); print4Bytes(hash); fprintf(stdout, " (%u)\n", hash);
  for (uint8_t i = 0; i < 8; i++) {             /* iterate over bytes in the key */
    byte = key & 0xFF;                 /* shift right the key a multiple of 8 bits and AND it with b11111111, to obtain a more significant byte each time */
    switch (i) {
      case 0 : fprintf(stdout, "first  "); break;
      case 1 : fprintf(stdout, "second "); break;
      case 2 : fprintf(stdout, "third  "); break;
      case 3 : fprintf(stdout, "fourth "); break;
      case 4 : fprintf(stdout, "fifth  "); break;
      case 5 : fprintf(stdout, "sixth  "); break;
      case 6 : fprintf(stdout, "seventh"); break;
      case 7 : fprintf(stdout, "eighth "); break;
    }
    fprintf(stdout, " byte of key = "); print1Byte(byte); fprintf(stdout, "\n");
    hash = ((hash << 5) + hash) ^ (uint8_t)byte;         /* multiply hash by 33 and XOR with byte */
    fprintf(stdout, "intermediate hash value multiplied by 33 and XOR'd with a byte of the key = "); print4Bytes(hash); fprintf(stdout, "\n");
    key >>= 8;
  }

  return hash;
}

uint32_t gen4BhashDE_PointerVersion(uint64_t key) {    /* remove */
  uint32_t hash = 5381;
  uint8_t *byteOfKey = &key;

  fprintf(stdout, "key = "); print8Bytes(key); fprintf(stdout, " (%lu)\n", key);
  fprintf(stdout, "initial hash = "); print4Bytes(hash); fprintf(stdout, " (%u)\n", hash);
  for (uint8_t i = 0; i < 8; i++) {             /* iterate over bytes in the key */
    switch (i) {
      case 0 : fprintf(stdout, "first  "); break;
      case 1 : fprintf(stdout, "second "); break;
      case 2 : fprintf(stdout, "third  "); break;
      case 3 : fprintf(stdout, "fourth "); break;
      case 4 : fprintf(stdout, "fifth  "); break;
      case 5 : fprintf(stdout, "sixth  "); break;
      case 6 : fprintf(stdout, "seventh"); break;
      case 7 : fprintf(stdout, "eighth "); break;
    }
    fprintf(stdout, " byte of key = "); print1Byte(*byteOfKey); fprintf(stdout, "\n");
    hash = ((hash << 5) + hash) ^ byteOfKey[i];         /* multiply hash by 33 and XOR with byte */
    fprintf(stdout, "intermediate hash value multiplied by 33 and XOR'd with a byte of the key = "); print4Bytes(hash); fprintf(stdout, "\n");
  }

  return hash;
}

