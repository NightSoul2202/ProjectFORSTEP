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



class MENU
{
public:
	void mainmenu();
	void menuforadmin();
	void menuforguest();
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
		vector<string> v = { "Add Catagory", "Add new test", "Add new test name", "Result all students", "Delete test", "Delete User", "Change password and login", "Back" };
		Menu m;
		int menu = m.select_vertical(v) + 1;
		admin a;
		switch (menu)
		{
		case 1: system("cls"); a.addCategory(); break;
		case 2: system("cls"); a.addtest(); break;
		case 3: system("cls"); a.addnameoftest(); break;
		case 4: system("cls"); a.result(); break;
		case 5: system("cls"); a.deletetest(); break;
		case 6: system("cls"); a.deleteguest(); break;
		case 7: system("cls"); a.changepassword(); break;
		case 8: mainmenu(); break;
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
	case 1: system("cls"); g.dotask(); break;
	case 2: system("cls"); g.resultsearch(); break;
	case 3: system("cls"); g.changepassword(); break;
	case 4: mainmenu(); break;
	}
	}
}

int main()
{
	MENU m;
	m.mainmenu();
	system("pause");
}
