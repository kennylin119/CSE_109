CC=gcc
CFLAGS=-g -Wall -Wextra -Wwrite-strings
LFLAGS=-g -Wall -Wextra

output: prog0.o prog0_funcs.o
	${CC} ${LFLAGS} prog0.o prog0_funcs.o -o output 

prog0.o: prog0.c
	${CC} ${LFLAGS} -c prog0.c 

prog0_funcs.o: prog0_funcs.c
	${CC} ${LFLAGS} -c prog0_funcs.c 

clean: 
	rm -f *.o
	rm -f output