all: build clean

build: graph.o structs.o calc.o RPN.o
	gcc -Wall -Werror -Wextra -c calc.c RPN.c graph.c  structs.c
	gcc -Wall -Werror -Wextra graph.o structs.o calc.o RPN.o -o ../build/graph
calc.o: calc.c
	gcc -Wall -Werror -Wextra -c calc.c -o

rpn.o: rpn.c
	gcc -Wall -Werror -Wextra -c rpn.c -o

graph.o: graph.c
	gcc -Wall -Werror -Wextra -c graph.c -o

structs.o: structs.c
	gcc -Wall -Werror -Wextra -c structs.c -o

clean:
	rm -rf *.o	

rebuild: clean all