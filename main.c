#include <stdio.h>
#include <curses.h>

enum {
	INCOME=1,
	EXPENSE,
	ACTIVE,
	PASSIVE, 
	EXIT,
}; 

int income, expense, active, passive;

void Menu(void)
{
	printf("\033[2J"); /* Clear the entire screen. */ 
	printf("\033[0;0f"); /* Move cursor to the top left hand corner */ 
	printf("\n1.Income: \t%6d", income);
	printf("\n2.Expanse: \t%6d", expense);
	printf("\n3.Active: \t%6d", active);
	printf("\n4.Passive: \t%6d\n", passive);
	printf("5.EXIT\n");
	printf("Your choise: ");
}

int main(int argc, char **argv)
{
	int buf, choise;
	income = expense = active = passive = 0;
	for(;;)
	{
		switch(choise)
		{
			case INCOME: printf("Enter Add income: "); scanf("%d",&buf); income+= buf; break;
			case EXPENSE: printf("Enter Add expense: "); scanf("%d",&buf); expense+= buf; break;
			case ACTIVE: printf("Enter Add active: "); scanf("%d",&buf); active+= buf; break;
			case PASSIVE: printf("Enter Add passive: "); scanf("%d",&buf); passive+= buf; break;
			case EXIT: return 0;
			default: break;
		}
		Menu();
		scanf("%d", &choise);
	}
}
