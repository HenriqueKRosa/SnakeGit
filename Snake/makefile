COMPIL=gcc -o

SRCDIR=src

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)

#INCLUDE=$(wildcard include/*.h)

EXEC=snake01

####MAKE#####
all: $(EXEC)

$(EXEC): $(OBJ)
	@echo ************************
	@echo 	GET READY 4 $@
	@echo ************************
	@$(COMPIL) $@ $^
	@echo ------------------
	@echo 	10DI LEK
	@echo ------------------

$(OBJ): $(SRC)
		@$(MAKE) -C $(SRCDIR) -s all	

.PHONY: clean 
