#Compiler
CC=gcc -std=c99 -c

#Flags
CFLAGS=-Wall -std=gnu99 -I'../include'

#Source files
SRC=$(wildcard *.c)

#Object files
OBJ=$(SRC:.c=.o)

#####MAKE#####
all: $(OBJ)

%.o: %.c
	@echo ==========
	@echo Bhir $@
	@echo ==========
	@$(CC) -o $@ -c $< $(CFLAGS) 
	@echo -
	@echo Aqui nois controi cobra!!
	@echo -
	
clean:
	@del *.o *~
	@echo ---------------
	@echo FAMOSA LIMPEZA
	@echo ---------------