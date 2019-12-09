CXX = g++
CFLAGS = -g -c -Wall -Wextra -Wwrite-strings 
LFLAGS = -g 
prog4_deps = prog4_funcs.o Count.o prog4.o 
update = -std=c++11

prog4: ${prog4_deps}
	${CXX} ${LFLAGS} -o prog4 ${prog4_deps}

prog4_funcs.o: prog4_funcs.h prog4_funcs.cpp
	${CXX} ${update} ${CFLAGS} prog4_funcs.cpp

Count.o: Count.h Count.cpp
	${CXX} ${update} ${CFLAGS} Count.cpp

prog4.o: prog4.cpp
	${CXX} ${update} ${CFLAGS} prog4.cpp

clean:
	rm -f *.o
	rm -f prog4
