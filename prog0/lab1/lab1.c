#define PAGE 4096                                                        /* no changes */
#define KILO 1024                                                        /* no changes */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void *Malloc(int numBytes);

//int main(int argc, char *argv[]) {
int main() {
  unsigned int i;                                                        /* no changes */
  char **memptr = Malloc(KILO * KILO * sizeof(char *));                  /* no changes */
  for (i = 0; i < KILO * KILO; i++) {                                    /* do not add add'l statements to loop body */
    memptr[i] = Malloc(PAGE);                                            /* no changes */
    memptr[i][KILO] = 255;                                               /* no changes */
    if (i < 10){
      printf("block: %p \n", memptr[i]);
    }
}

  for (int i = 0; i < KILO * KILO; i++){
    free(memptr[i]);
  }
  free(memptr);
}

void *Malloc(int numBytes) {                                             /* no changes */
  void *ptr = NULL;                                                      /* no changes */
  if ((ptr = malloc(numBytes)) == NULL) {                                /* no changes */
    fprintf(stderr, "Could not allocate space - %s", strerror(errno));   /* no changes */
    exit(99);                                                            /* no changes */
  }
  return ptr;
}

//a) i added a return output of int in front of the main header
//b) needed to declare funciton malloc before main
// deleted arguments argc and argc because they aren't being used
//included stdlib.h to allow use of malloc
// added string.h to allow use of strerror
//returned void type ptr at the end of *Malloc funciton
//d) this program defines a 2 dimesional array, **memptr memory equivelent to KILO * KILO * PAGE to it. At each column of the array, it allocates another array the size of PAGE, with each value in this array contianing the int 255.
//e) added for loop to free each value alloccated within memptr
//f) im getting approximately 4112 bits between each pointer which makes sense as the value of each block of memory is defined as page, which is set to 4096. 
