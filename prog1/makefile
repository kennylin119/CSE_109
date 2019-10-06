CC = gcc
CFLAGS = -g -Wall -Wextra -Wwrite-strings 
LFLAGS= -g - Wall -Wextra 

prog1: prog1.o prog1_funcs.o
	${CC} ${LFLAGS} prog1.o prog1_funcs.o -o prog1

prog1.o: prog1.c
	${CC} ${CFLAGS} -c prog1.c

prog0_funcs.o: prog0_funcs.c
	${CC} ${CFLAGS} -DEBUG -c prog1_funcs.c

clean: 
	rm -f *.o
	rm -f prog1