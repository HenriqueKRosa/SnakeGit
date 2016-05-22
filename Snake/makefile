all: Snake1

Snake1: Snake0.2.c CobraBib.o
	gcc -o Snake1 Snake0.2.c CobraBib.o
	
CobraBib.o: CobraBib.c
	gcc -o CobraBib.o -c CobraBib.c
	
clean:
	-rm -f *.o *.c~
	echo "NÃO É ÁGUA COM MUSCULO"
