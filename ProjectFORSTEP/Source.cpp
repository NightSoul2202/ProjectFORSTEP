#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<experimental/filesystem>
#include<map>
#include<list>
#include"md5.h"
#include"Login.h"

using namespace std;

using namespace std::experimental::filesystem;


// Каждый раз человек при регстрации пишщет свой логин на англ ( желательно ) и тем самым идет сохранение в файл с названием логин.тхт, при след регистрации
// человек вводя лои=гин такую-же, что и уже имеется в файле, получает предупреждение, что уже сущечтвует такой логин, и просит написать по другому


// нужнор будет запихнуть это BTree<string, List<Protocol*>> base;


class MENU
{
public:
	void mainmenu();
	void menuforadmin();
	void menuforguest();
	/*void enterAdmin();
	void enterGuest();*/
};

void MENU::mainmenu()
{
	while (true)
	{
		system("cls");
		system("MODE CON COLS=80 LINES=25");
		cout << endl;
		cout << "\t\t      ###    ### ####### ###   ## ##    ##" << endl;
		cout << "\t\t      ####  #### ##      ####  ## ##    ##" << endl;
		cout << "\t\t      ## #### ## #####   ## ## ## ##    ##" << endl;
		cout << "\t\t      ##  ##  ## ##      ##  #### ##    ##" << endl;
		cout << "\t\t      ##      ## ####### ##   ###  ###### " << endl;
		vector<string> v = { "Admin", "Guest", "Exit" };
		Menu m;
		int menu = m.select_vertical(v) + 1;
		admin a;
		guest g;
		switch (menu)
		{
		case 1: system("cls"); a.enter(); menuforadmin(); break;
		case 2: system("cls"); g.enter(); menuforguest(); break;
		case 3: exit(0); break;
		}
	}
}

inline void MENU::menuforadmin()
{
	while (true)
	{
		system("cls");
		cout << endl;
		cout << "\t\t      ###    ### ####### ###   ## ##    ##" << endl;
		cout << "\t\t      ####  #### ##      ####  ## ##    ##" << endl;
		cout << "\t\t      ## #### ## #####   ## ## ## ##    ##" << endl;
		cout << "\t\t      ##  ##  ## ##      ##  #### ##    ##" << endl;
		cout << "\t\t      ##      ## ####### ##   ###  ###### " << endl;
		vector<string> v = { "Add Catagory", "Add new test", "Add new test name", "Delete test", "Delete User", "Search result", "Back" };
		Menu m;
		int menu = m.select_vertical(v) + 1;
		admin a;
		switch (menu)
		{
		case 1: system("cls"); a.addCategory(); break;
		case 2: system("cls"); a.addtest(); break;
		case 3: system("cls"); a.addnameoftest(); break;
		case 4: system("cls"); a.deletetest(); break;
		case 5: system("cls"); a.deleteguest(); break;
		case 6: system("cls"); /*changepassword();*/ break;
		case 7: mainmenu(); break;
		}
	}
}

inline void MENU::menuforguest()
{
	while (true)
	{
	system("cls");
	cout << endl;
	cout << "\t\t      ###    ### ####### ###   ## ##    ##" << endl;
	cout << "\t\t      ####  #### ##      ####  ## ##    ##" << endl;
	cout << "\t\t      ## #### ## #####   ## ## ## ##    ##" << endl;
	cout << "\t\t      ##  ##  ## ##      ##  #### ##    ##" << endl;
	cout << "\t\t      ##      ## ####### ##   ###  ###### " << endl;
	vector<string> v = { "Do task", "Check result", "Change password", "Back" };
	Menu m;

	int menu = m.select_vertical(v) + 1;
	guest g;

	switch (menu)
	{
	case 1: system("cls"); /*g.dotask();*/ break;
	case 2: system("cls"); /*g.resultsearch();*/ break;
	case 3: system("cls"); /*g.changepassword();*/ break;
	case 4: mainmenu(); break;
	}
	}
}

//
//

int main()
{
	MENU m;
	m.mainmenu();
	system("pause");
}







//inline void MENU::enterAdmin()
//{
//	ifstream in("adminpass.txt");
//	if (in.is_open())
//	{
//		int ras = 0;
//		while (ras != 5 /*&&*/ )				//или пока не будет правильные парольи и логин*/)
//		{
//			string l, p;
//			cout << "Hello, please, enter your login and password" << endl;
//			cout << endl;
//			cout << "Login : ";
//			cin >> l;
//			cout << endl;
//			cout << "Password : ";
//			cin >> p;
//			ras++;
//
//
//			/*printAll();
//			cout << endl;
//			string log;
//			cout << "Enter the number of a car : ";
//			cin >> log;
//			List<Protocol*>* list = base.get(num);
//			list->print();
//			system("pause");*/
//		}
//		if (ras > 5)
//		{
//			//если попыток больше 5 выдать ошибку и отправить в меню
//			mainmenu();
//		}
//		menuforadmin();
//	}
//	else
//	{
//		bool s;
//		cout << "You aren`t have admin account, do you want to add admin account?" << endl;
//		cout << "Warnings! If you forgot your pass or login, call to your it admin to change pass." << endl;
//		cout << "You can do only one account, in future you will can change pass and login." << endl;
//		cout << "Write 1 to do account, or 0 to leave." << endl;
//		cin >> s;
//		if (s == true)
//		{
//			string l, p;
//			cout << "Hello, please, enter your login and password" << endl;
//			cout << endl;
//			cout << "Login : ";
//			cin >> l;
//			cout << endl;
//			cout << "Password : ";
//			cin >> p;
//			ofstream out("adminpass.txt", ios::app);
//			//out << prot->getNumTS() << endl;
//			//out << prot->getdate() << endl;
//			//out << prot->getsum() << endl;
//			out.close();
//			menuforadmin();
//		}
//		else
//		{
//			mainmenu();
//		}
//	}
//
//
//	//Check for trust enter
//	//if(trustcheck == 1)
//	//{
//	//	menuforadmin();
//	// 	system("cls");
//	//}
//}
// 
// 
// 
// 
// 
// 
// 
//void MENU::enterGuest()
//{
//	bool bb;
//	cout << "Do you want to registration or login?" << endl;
//	cout << "Enter 1 to registration or 0 to login : ";
//	cin >> bb;
//	if (bb == 1)
//	{
//		//регистрация с использорванием фио, телефона, улицы. Сохранение в отдельный файл с названием, которое укажет в логине
//		menuforguest();
//	}
//	else if (bb == 0)
//	{
//		//Логиниться, по логину искать файл, в папке гостей, если нет, выдать ошибку, и после 5 попыток отправить в мейн меню. Елси нашел то в меню для гостей
//		menuforguest();
//	}
//}
