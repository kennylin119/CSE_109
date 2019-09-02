#include <stdio.h>  /* for fprintf and getline */
#include <ctype.h>  /* for toupper */
#include <string.h> /* for strlen */
#include <stdlib.h> /* for free */

/* compile with: gcc -g -Wall -Werror -Wwrite-strings -o parseargs parseargs.c */ 
/* check for memory leaks with: valgrind --leak-check=yes parseargs */

/* By adding argc and argv[] to the parameter list of the main function,
 * we can know how many arguments were entered on the command line when
 * our program was called AND we can access each command line argument
 * via the argv[] array.  
 * Note that argc is a global variable equal to the number of command-
 * line arguments, and argv[] is a global variable which is an array of 
 * character string pointers.
 */

int main(int argc, char * argv[]) {

  /* If we simply want to access the command-line arguments, we can do the
   * following.
   */

  fprintf(stdout, "argc = %d\n", argc); /* "%d" displays argc as a decimal integer */
  for (int i = 0; i < argc; i++) {      /* iterate over all the arguments */
    if (argv[i][0] == 'u') {            /* if argument starts with 'u' character */
      int len = strlen(argv[i]);        /* get length of argv[i] argument */
      fprintf(stdout, "arg[%d] = ", i);
      for (int j = 0; j < len; j++)     /* loop as many times as there are characters */
        fprintf(stdout, "%c", toupper(argv[i][j])); /* convert chars to uppercase */
      fprintf(stdout, "\n");
    } else {                            /* if argument does NOT start with 'u' character */
      fprintf(stdout, "arg[%d] = %s\n", i, argv[i]);  /* print the argument in position i */
    }
  }

  /* Had we wanted to compare the first 2 characters of the argument in position i 
   * with the string "-u" (ignoring the case), we could do the following.
   *
   * if (strncasecmp(argv[i], "-u", 2)) {
   */

  /* To request the user input something and capture that input, 
   * we can do the following.
   * Note that Cntl+D pass the end-of-file character, "EOF",
   * which equals -1.
   */
  char *line = NULL;  /* same as '\0' character */
  size_t length = 0;  /* size_t is unsigned integer */
  ssize_t read;       /* ssize_t is signed integer */

  fprintf(stdout, "Enter something, Cntl+D to end\n");

  /* The following loop reads stdin (a file) each time the user hits 
   * the Enter key; the loop is exited when the user enters Cntl+D.
   * The number of characters entered is returned and assigned to the
   * variable "read".
   * The getline function will automatically allocate memory to hold all the 
   * characters
   * The line input by the user, including the newline character ('\n') will be
   * stored in the line variable, and the length of the line will be stored in the
   * length variable.
   * While the stdin file is being read here, any file could be opened and read this
   * way.
   */
  while ((read = getline(&line, &length, stdin)) != -1 ) {  
    fprintf(stdout, "Retreived line of length %zu :\n", read); /* %zu for ssize_t */
    /* following also works:
     * fprintf(stdout, "Retreived line of length %d :\n", (unsigned int)read); 
     */
    fprintf(stdout, "%s", line);
  }

  if (line)    /* release the memory allocated by the getline function */
    free(line);

  return 0;  /* return a value to function which called main */
}
