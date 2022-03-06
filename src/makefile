all: graph clean
graph: graph.o structs.o calc.o RPN.o
	gcc -Wall -Werror -Wextra graph.o structs.o calc.o RPN.o -o ../build/graph
graph.o: graph.c structs.h calc.h RPN.h defines.h graph.h
	gcc -Wall -Werror -Wextra -c graph.c
structs.o: structs.c structs.h
	gcc -Wall -Werror -Wextra -c structs.c
calc.o: calc.c defines.h calc.h structs.h
	gcc -Wall -Werror -Wextra -c calc.c
RPN.o: RPN.c RPN.h structs.h defines.h
	gcc -Wall -Werror -Wextra -c RPN.c
clean:
	rm -rf *.o