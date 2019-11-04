CFLAGS= -g -DDEBUG -c -Wall -Wextra -Wwrite-strings
CFLAGS= -g -c -Wall -Wextra -Wwrite-strings
LFLAGS= -g

prog2: prog2_funcs.o prog2.o
	gcc ${LFLAGS} -o prog2 prog2_funcs.o prog2.o
prog2.o: prog2_funcs.h prog2.c
	gcc ${CFLAGS} prog2.c
prog2_funcs.o: prog2_funcs.h prog2_funcs.c
	gcc ${CFLAGS} prog2_funcs.c
clean:
	rm -f *.o
	rm -f prog2
