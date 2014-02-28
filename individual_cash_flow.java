import java.util.Scanner;
import java.util.ArrayList;
import java.lang.String;

public class individual_cash_flow 
{

	public static void main(String[] args) 
	{
		DataBase BeginCash = new DataBase();
		Scanner in = new Scanner(System.in);
		
		while(true)
		{
			BeginCash.Show();
			System.out.print("Your choice: ");
			int key = in.nextInt();
			if(BeginCash.Add(key)) break;
		}
	}
}

class DataBase
{
	int income, expense, active, passive;
	final int INCOME = 1, EXPENSE = 2, ACTIVE = 3, PASSIVE = 4;
	ArrayList<Check> DataInc, DataExp, DataAct, DataPas;
	Scanner in = new Scanner(System.in);

	DataBase()
	{
		income = expense = active = passive = 0;
		DataInc = new ArrayList<Check>();
		DataExp = new ArrayList<Check>();
		DataAct = new ArrayList<Check>();
		DataPas = new ArrayList<Check>();
	}

	void Show()
	{
		System.out.print("\033[2J\033[1;1H");
		System.out.println(INCOME + ". Income = " + income);
		System.out.println(EXPENSE + ". Expense = " + expense);
		System.out.println(ACTIVE + ". Active = " + active);
		System.out.println(PASSIVE + ". Passive = " + passive);
		System.out.println("0. EXIT");
	}

	boolean Add(final int choice)
	{
		ArrayList<Check> list_select;
		switch(choice)
		{
			case INCOME: list_select = DataInc; break;
			case EXPENSE: list_select = DataExp; break;
			case ACTIVE: list_select = DataAct; break;
			case PASSIVE: list_select = DataPas; break;
			default: return true;
		}
				
		for(int i=0; i< list_select.size(); i++)
			System.out.println(list_select.get(i).value + " - " + list_select.get(i).reason);

		System.out.print("You want add data [y/n]?");
		String str = in.nextLine();

		if(str.equals("y") != true) return false;

		Check buf = new Check();
		System.out.print("Enter number: ");
		buf.value = in.nextInt();
		in.nextLine();
		System.out.print("Enter reason: ");
		buf.reason = in.nextLine();

		list_select.add(buf);
		switch(choice)
		{
			case INCOME: income += buf.value; break;
			case EXPENSE: expense += buf.value; break;
			case ACTIVE: active += buf.value; break;
			case PASSIVE: passive += buf.value; break;
			default: return true;
		}
		return false;
	}
}

class Check
{
	int value;
	String reason;
}

