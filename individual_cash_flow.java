import java.util.Scanner;
import java.util.ArrayList;
import java.lang.String;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.IOException;

public class individual_cash_flow 
{
	public static void main(String[] args) 
	{
		DataBase BeginCash;
		Scanner in = new Scanner(System.in);
		
		System.out.print("\033[2J\033[1;1H");
		System.out.print("Please, enter file name for log: ");
		String file = in.nextLine();
		File fl = new File(file);

		if ( fl.exists() ) BeginCash = new DataBase(file);
		else BeginCash = new DataBase();

		while(true)
		{
			BeginCash.Show();
			System.out.print("Your choice: ");
			int key = in.nextInt();
			if(BeginCash.Add(key)) break;
		}
		in.nextLine();
		System.out.print("Save changes of file [y/n]? ");
		String key = in.nextLine();
		if (key.equals("y")) BeginCash.SaveFile();
	}
}

class DataBase
{
	int income, expense, active, passive;
	final int INCOME = 1, EXPENSE = 2, ACTIVE = 3, PASSIVE = 4;
	String log_file = "";
	ArrayList<Check> DataInc, DataExp, DataAct, DataPas;
	Scanner in = new Scanner(System.in);

	DataBase()
	{
		income = expense = active = passive = 0;
		DataInc = new ArrayList<Check>();
		DataExp = new ArrayList<Check>();
		DataAct = new ArrayList<Check>();
		DataPas = new ArrayList<Check>();
		log_file = "temp.log";
	}

	DataBase(final String path)
	{
		log_file = path;
		income = expense = active = passive = 0;
		DataInc = new ArrayList<Check>();
		DataExp = new ArrayList<Check>();
		DataAct = new ArrayList<Check>();
		DataPas = new ArrayList<Check>();

		String check_str = "";
		Scanner in_file;

		try
		{
			in_file = new Scanner(new File(path));
		} 
		catch( FileNotFoundException ex)
		{
			ex.printStackTrace();
			in.nextLine();
			return;
		}
		
		ArrayList<Check> list_select = new ArrayList<Check>();
		while(in_file.hasNext())
		{
			check_str = in_file.nextLine();
			if( check_str.equals("[INCOME]") )	list_select = DataInc;
			else if( check_str.equals("[EXPENSE]") ) list_select = DataExp;
			else if (check_str.equals("[ACTIVE]") ) list_select = DataAct;
			else if (check_str.equals("[PASSIVE]") ) list_select = DataPas;
			//else if (list_select == null) continue;
			else 
			{
				int pos_separator = check_str.indexOf(':');
				if ( pos_separator == -1) continue;
				Check buf = new Check();
				buf.value = Integer.parseInt( check_str.substring(0, pos_separator));
				buf.reason = check_str.substring(pos_separator+1);
				System.out.println(buf.value + " - " + buf.reason);
				list_select.add(buf);
			}
		}
		in_file.close();
		ReCount();
	}

	void ReCount()
	{
		income = expense = active = passive = 0;

		for (int i=0; i < DataInc.size(); i++) income +=DataInc.get(i).value;
		for (int i=0; i < DataExp.size(); i++) expense += DataExp.get(i).value;
		for (int i=0; i < DataAct.size(); i++) active += DataAct.get(i).value;
		for (int i=0; i < DataPas.size(); i++) passive += DataPas.get(i).value;
	}

	void Show()
	{
		System.out.print("\033[2J\033[1;1H");
		System.out.println(log_file);
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

		System.out.print("You want add data [y/n]? ");
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

	void SaveFile()
	{
		String str = "";
		str = "[INCOME]\n";
		for ( int i =0; i < DataInc.size(); i++) str += DataInc.get(i).value + ":" + DataInc.get(i).reason + "\n";
		str += "[EXPENSE]\n";
		for ( int i =0; i < DataExp.size(); i++) str += DataExp.get(i).value + ":" + DataExp.get(i).reason + "\n";
		str += "[ACTIVE]\n";
		for ( int i =0; i < DataAct.size(); i++) str += DataAct.get(i).value + ":" + DataAct.get(i).reason + "\n";
		str += "[PASSIVE]\n";
		for ( int i =0; i < DataPas.size(); i++) str += DataPas.get(i).value + ":" + DataPas.get(i).reason + "\n";

		try
		{
		PrintWriter out = new PrintWriter( new File(log_file).getAbsoluteFile());
		out.print(str);
		out.close();
		}
		catch(IOException ex){}
	}
}

class Check
{
	int value;
	String reason;
}

