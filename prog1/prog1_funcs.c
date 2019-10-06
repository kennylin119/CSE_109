#include <stdio.h>       /* for fprintf, sprintf */
#include <stdlib.h>      /* for exit */
#include <errno.h>       /* error handling */
#include <string.h>      /* for ? */
#include "prog1_funcs.h"

/* if we compile with gcc -DDEBUG, we will set the DEBUG macro to 1 */
#ifdef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif


void bail(int rc, const char *msg) {
  fprintf(stderr, "(%d) %s\n", rc, msg);
  exit(rc);
}
