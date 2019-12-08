CXX = g++
CFLAGS = -g -c -Wall -Wextra -Wwrite-strings 
LFLAGS = -g 
prog4_deps = prog4_funcs.o Count.o prog4.o 

prog4_funcs.o: prog4_funcs.h prog4_funcs.cpp
	${CXX} ${CFLAGS} prog4_funcs.cpp

Count.o: Count.h Count.cpp
	${CXX} ${CFLAGS} Count.cpp

prog4.o: prog4_funcs.h Count.h prog4.cpp
	${CXX} ${CFLAGS} prog4.cpp

prog4: ${prog4_deps}
	${CXX} ${LFLAGS} -o prog4 ${prog4_deps}

clean:
	rm -f *.o
	rm -f prog4
