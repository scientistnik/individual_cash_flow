#include <iostream>

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
	using std::cout;
	using std::endl;
	cout << "\n1.Income: \t"<< income << endl;
	cout << "2.Expanse: \t"<< expense << endl;
	cout << "3.Active: \t" << active << endl;
	cout << "4.Passive: \t" << passive<< endl;
	cout << "5.EXIT" << endl;
	cout << "Your choise: ";
}

int main(int argc, char **argv)
{
	int buf, choise;
	using std::cin;
	using std::cout;
	income = expense = active = passive = 0;
	for(;;)
	{
		switch(choise)
		{
			case INCOME: cout << "Enter Add income: "; cin >> buf; income+= buf; break;
			case EXPENSE: cout << "Enter Add expense: "; cin >> buf; expense+= buf; break;
			case ACTIVE: cout << "Enter Add active: "; cin >> buf; active+= buf; break;
			case PASSIVE: cout << "Enter Add passive: "; cin >> buf; passive+= buf; break;
			case EXIT: return 0;
			default: break;
		}
		Menu();
		cin >> choise;
	}
}
