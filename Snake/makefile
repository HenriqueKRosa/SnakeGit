CC=gcc

SRCDIR=src

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)

#INCLUDE=$(wildcard include/*.h)

TGT=SnakeAlpha

####MAKE#####
all: $(TGT)

$(TGT): $(OBJ)
	@echo ******************
	@echo GET READY 4 $@
	@echo ******************
	@$(CC) -o $(TGT) $(OBJ)
	@echo ------------------
	@echo 10DI LEK
	@echo ------------------
	
clean:
	@del *.o *~
	@echo ---------------
	@echo FAMOSA LIMPEZA
	@echo ---------------