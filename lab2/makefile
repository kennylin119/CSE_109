CFLAGS=-g -c -Wall -Wextra -Wwrite-strings
LFLAGS=-g

hashLab: hashLab.o
	gcc ${LFLAGS} -o hashLab deBits.o hashLab.o
hashLab.o: hashLab.c
	gcc ${CFLAGS} hashLab.c
clean:
	rm -f hashLab.o
	rm -f hashLab

