all: frequency
frequency: main.o node.o Thire.o 
	 gcc -Wall -g -o frequency main.o node.o Thire.o 

main.o: main.c Thire.h 
	gcc -Wall -g -c main.c
node.o: node.c node.h 
	gcc -Wall -g -c node.c
Thire.o: Thire.c Thire.h 
	gcc -Wall -g -c Thire.c

.PHONY: clean all
clean:
	rm -f *.o *.a *.so frequency

