#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

enum {
	INCOME=1,
	EXPENSE,
	ACTIVE,
	PASSIVE, 
	EXIT,
}; 

class Check
{
public:
	Check():value(0),why("XZ"){}
	Check(int val, string& str):value(val),why(str){}
	~Check(){}
	const string& GetString() const { return why;}
	int GetValue() const { return value;}
private:
	int value;
	string why;
};

class DataBase 
{
public:
	DataBase():income(0),expense(0),active(0),passive(0){}
	~DataBase(){}
	void ShowBase();
	int AddData(int choise);
private:
	int income, expense, active, passive;		
	vector<Check> IncomeCheck, ExpenseCheck, ActiveCheck, PassiveCheck;
};

int DataBase::AddData(int choise)
{
	vector<Check>::const_iterator cii, end;
	int value;
	string str;

	switch(choise)
	{
		case INCOME: cii = IncomeCheck.begin(); end = IncomeCheck.end(); break;
		case EXPENSE: cii = ExpenseCheck.begin(); end = ExpenseCheck.end(); break;
		case ACTIVE: cii = ActiveCheck.begin(); end = ActiveCheck.end(); break;
		case PASSIVE: cii = PassiveCheck.begin(); end = PassiveCheck.end(); break;
		default: return 1;
	}
	for( ; cii!= end; cii++)
	{
		cout << cii->GetValue() << " : " << cii->GetString() << endl;
	}
	cout << "You want add data? [y/n] ";
	cin >> str;
	if(str != "y") return 0;
	cout << "Enter number: ";
	cin >> value;
	cout << "Enter reason: ";
	cin.ignore(1,'\n');
	getline(cin,str);

	Check *buf = new Check(value, str);
	switch(choise)
	{
		case INCOME: IncomeCheck.push_back(*buf); income += value; break;
		case EXPENSE: ExpenseCheck.push_back(*buf); expense += value; break;
		case ACTIVE: ActiveCheck.push_back(*buf); active += value; break;
		case PASSIVE: PassiveCheck.push_back(*buf); passive += value; break;
	}
	return 0;
}

void DataBase::ShowBase(void)
{
	using std::cout;
	using std::endl;
	cout << "\033[2J\033[1;1H";
	cout << "1.Income: \t"<< income << endl;
	cout << "2.Expanse: \t"<< expense << endl;
	cout << "3.Active: \t" << active << endl;
	cout << "4.Passive: \t" << passive<< endl;
}

int main(int argc, char **argv)
{
	int buf, choise;
	DataBase Test;
	using std::cin;
	using std::cout;
	using std::endl;
	for(;;)
	{
		Test.ShowBase();
		cout << "5.EXIT" << endl;
		cout << "Your choise: ";
		cin >> choise;
		if(Test.AddData(choise) ) return 0;
	}
}
