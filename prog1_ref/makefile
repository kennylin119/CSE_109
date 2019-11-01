CFLAGS=-g -DDEBUG -c -Wall -Wextra -Wwrite-strings
CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

prog1: prog1_funcs.o prog1.o
	gcc ${LFLAGS} -o prog1 prog1_funcs.o prog1.o
prog1.o: prog1_funcs.h prog1.c
	gcc ${CFLAGS} prog1.c
prog1_funcs.o: prog1_funcs.h prog1_funcs.c
	gcc ${CFLAGS} prog1_funcs.c
clean:
	rm -f *.o
	rm -f prog1

