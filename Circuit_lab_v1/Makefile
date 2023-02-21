GCC=gcc

CFLAGS=-Wall -Wextra -pedantic -std=c99 -D_XOPEN_SOURCE=600

circuit: circuit.o components.o simulate_circuit.o 
	$(GCC) -o circuit circuit.o components.o simulate_circuit.o

circuit.o: components.h simulate_circuit.h

clean:
	rm circuit circuit.o components.o simulate_circuit.o
