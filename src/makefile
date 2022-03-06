all: graph.o render.o structs.o calc.o RPN.o table.o
	gcc -Wall -Werror -Wextra graph.o render.o structs.o calc.o RPN.o table.o -o ../build/graph

calc.o: calc.c
	gcc -Wall -Werror -Wextra -c calc.c -o

render.o: render.c
	gcc -Wall -Werror -Wextra -c render.c -o

rpn.o: rpn.c
	gcc -Wall -Werror -Wextra -c rpn.c -o

table.o: table.c
	gcc -Wall -Werror -Wextra -c table.c -o

graph.o: graph.c
	gcc -Wall -Werror -Wextra -c graph.c -o

structs.o: structs.c
	gcc -Wall -Werror -Wextra -c structs.c -o

clean:
	rm -rf *.o	

rebuild: clean all