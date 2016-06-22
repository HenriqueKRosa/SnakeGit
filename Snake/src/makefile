##############MAKEFILE##############

#####VARIABLES#####
#Compiler
CC=gcc -std=c99 -c

#Flags
CFLAGS=-Wall -std=gnu99 -I'../include'

#Source files
SRC=$(wildcard *.c)

#Object files
OBJ=$(SRC:.c=.o)

#Libraries
#INCLUDE=$(wildcard include/*.h)


#####MAKE#####
all: $(OBJ)

%.o: %.c
	@echo =========================
	@echo Bhir $@
	@echo =========================
	@$(CC) -o $@ -c $< $(CFLAGS) 
	@echo -
	@echo Ta tranquilo, ta compilado.
	@echo -