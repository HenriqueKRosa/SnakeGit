all: Snekao

Snekao: Snake0.2.c CobraBib.o MenuBib.o
	@gcc -o Snake1 Snake0.2.c CobraBib.o MenuBib.o	
	@echo "*********************"	
	@echo " HORA DO SNAKE PORRA"
	@echo "*********************"	

CobraBib.o: CobraBib.c
	@gcc -o CobraBib.o -c CobraBib.c 
	@echo "**************"	
	@echo " 37 COBRA KRL"
	@echo "**************"

MenuBib.o: MenuBib.c
	@gcc -o MenuBib.o -c MenuBib.c
	@echo "****************************"	
	@echo " TA SAINDO DA JAULA A COBRA"
	@echo "****************************"	

clean:
	@-rm -f *.o *.c~ *.swp
	@echo "**********************************"	
	@echo " AQUI NOIS CONSTRÓI COBRA CARALHO"
	@echo "**********************************"
