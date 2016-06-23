CC=gcc

SRCDIR=src

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:.c=.o)

TGT=SnakeAlpha

####MAKE#####
all: $(TGT)

$(TGT): $(OBJ)
	@echo ******************************
	@echo * GET READY 4 SUM $@ *
	@echo ******************************
	@$(CC) -o $(TGT) $(OBJ)
	@echo +----------------------------+
	@echo * SAI DO RU COMI PRA CARALHO *
	@echo +----------------------------+
	
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@echo ================
	@echo EH $@ CARALHO
	@echo ================
	@$(CC) -o $@ -c $< $(CFLAGS) 
	@echo *****************************
	@echo * Aqui nois controi cobra!! *
	@echo ***************************** 
	
clean:
	@del $(SRCDIR)\*.o $(SRCDIR)\*~
	@echo ---------------
	@echo FAMOSA LIMPEZA
	@echo ---------------