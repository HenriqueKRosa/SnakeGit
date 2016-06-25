#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

int main(){
	int ratos, q;
	char t= 'i';

	ratos = 500;
	do
	{
		if(t != 'i')
		{
			while(!kbhit())
			{
				Sleep(ratos);
				printf("%c\n", t);
			}
			t = getch();
			if(t == 'q')
				q = 1;
		}
		else
			t = getch();
	}while(q != 1);

	printf("Out %c",t);

	getch(); 
	return 0;
}
