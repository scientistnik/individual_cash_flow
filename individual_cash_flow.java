import java.util.Scanner;

public class individual_cash_flow 
{
	final int INCOME = 1, EXPENSE = 2, ACTIVE = 3, PASSIVE = 4;
	int income = 0, expense = 0, active = 0, passive = 0;
	individual_cash_flow()
	{
		income = expense = active = passive = 0;
	}

	void MenuDraw()
	{
		System.out.print("\033[2J\033[1;1H");
		System.out.println(INCOME + ". Income = " + income);
		System.out.println(EXPENSE + ". Expense = " + expense);
		System.out.println(ACTIVE + ". Active = " + active);
		System.out.println(PASSIVE + ". Passive = " + passive);
		System.out.println("0. EXIT");
		System.out.print("Your choice: ");
	}

	public static void main(String[] args) 
	{
		individual_cash_flow BeginCash = new individual_cash_flow();
		BeginCash.MainCycle();
	}

	void MainCycle()
	{
		Scanner in = new Scanner(System.in);
		while(true)
		{
			MenuDraw();
			int key = in.nextInt();
			switch(key)
			{
				case INCOME: System.out.println(income++); break;
				case EXPENSE: System.out.println(expense++); break;
				case ACTIVE: System.out.println(active++); break;
				case PASSIVE: System.out.println(passive++); break;
				default: return;
			}
		}
	}
}
