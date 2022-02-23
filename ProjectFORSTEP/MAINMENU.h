#pragma once

class MENU
{
	admin a;
public:
	void mainmenu();
	void menuforadmin();
	void menuforguest();
};

void MENU::mainmenu()
{



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

	switch (menu)
	{
	case 1: system("cls"); a.enter(); break;
	case 2: system("cls"); menuforguest(); break;
	case 3: exit(0); break;
	}
}

inline void MENU::menuforadmin()
{

	system("MODE CON COLS=80 LINES=25");
	cout << endl;
	cout << "\t\t      ###    ### ####### ###   ## ##    ##" << endl;
	cout << "\t\t      ####  #### ##      ####  ## ##    ##" << endl;
	cout << "\t\t      ## #### ## #####   ## ## ## ##    ##" << endl;
	cout << "\t\t      ##  ##  ## ##      ##  #### ##    ##" << endl;
	cout << "\t\t      ##      ## ####### ##   ###  ###### " << endl;
	vector<string> v = { "Edit task", "Edit guest", "Change password", "Exit" };
	Menu m;
	int menu = m.select_vertical(v) + 1;

	switch (menu)
	{
	case 1: system("cls"); //edittask(); break;
	case 2: system("cls"); //editquest(); break;
	case 3: system("cls"); //changepassword(); break;
	case 4: exit(0); break;
	}
}

inline void MENU::menuforguest()
{
	system("MODE CON COLS=80 LINES=25");
	cout << endl;
	cout << "\t\t      ###    ### ####### ###   ## ##    ##" << endl;
	cout << "\t\t      ####  #### ##      ####  ## ##    ##" << endl;
	cout << "\t\t      ## #### ## #####   ## ## ## ##    ##" << endl;
	cout << "\t\t      ##  ##  ## ##      ##  #### ##    ##" << endl;
	cout << "\t\t      ##      ## ####### ##   ###  ###### " << endl;
	vector<string> v = { "Do task", "Check result", "Change password", "Exit" };
	Menu m;
	int menu = m.select_vertical(v) + 1;

	switch (menu)
	{
	case 1: system("cls"); //dotask(); break;
	case 2: system("cls"); //result(); break;
	case 3: system("cls"); //changepassword(); break;
	case 4: exit(0); break;
	}
}