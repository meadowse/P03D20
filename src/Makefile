all: graph clean
graph: graph.o
	gcc graph.o -o ../build/graph
graph.o: graph.c graph.h
	gcc -Wall -Werror -Wextra -c graph.c
clean:
	rm -rf graph.o