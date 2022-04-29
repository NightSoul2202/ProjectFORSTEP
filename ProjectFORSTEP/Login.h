#pragma once
#include"MENU.h"

using namespace std::experimental::filesystem;

	class login
	{
	protected:
		string log;
		string pass;
		string folder = "LoginAccounts";
		string UserStat = "UserStat";
		string TestFolder = "TestFolder";
		string emptyFile = "emptyFile.txt"; //Хитрый, пустой файл благодаря которому мы можем проверять, можно ли открыть папку.(Существует ли она)
		/*string UsersFolder = "UsersFolder";
		string StudentsFile = "StudentsFile.txt";*/

	public:
		login() {};
		~login() {};
		virtual void enter() = 0;
		virtual void resultsearch() = 0;
		virtual void changepassword() = 0;
		
		
		string getpass() { return this->pass; }
		string getlogin() { return this->log; }
		void setpass(string setpass) { pass = setpass; }
		void setlogin(string setlogin) { log = setlogin; }

	
		// здесь нужны гетеры и сетеры, такие как фио телефон и тд
	};

	class guest : public login
	{
	public:
		guest() {};
		~guest() {};
		/*void registration();*/
		void dotask();
		string gettxtname() { return txtname; }
		void load()
		{
			/*ifstream in("guest.txt");
			if (in.is_open())
			{
				while (!in.eof())
				{
					char* buff = new char[80];
					Protocol* prot = new Protocol;
					int s;
					in.getline(buff, 80);
					prot->setNumTS(buff);
					in.getline(buff, 80);
					prot->setdate(buff);
					in.getline(buff, 80);
					s = atoi(buff);
					prot->setsum(s);

					List<Protocol*>* list = base.get(prot->getNumTS());
					if (!list)
					{
						List<Protocol*> newList;
						newList.push_front(prot);
						base.push_r(prot->getNumTS(), newList);

					}
					else
					{
						list->push_front(prot);
					}
				}
			}*/
		}
		virtual void changepassword() override;
		virtual void enter() override;
		virtual void resultsearch() override;
	private:
		string txtname;

		
	};

	inline void guest::dotask()
	{

	}

	inline void guest::changepassword()
	{
		//bool b;
		//	//bool chpass = false;
		//	//while (b != 1 && chpass != true)
		//	//{
		//	//	
		//	//	cout << "Do you really want to edit your pass?" << endl;
		//	//	cout << "Enter 0 to agree or 1 to disagree." << endl;
		//	//	cin >> b;
		//	//	if (b == 0)
		//	//	{
		//	//		remove("adminpass.txt");
		//	//		// plus add new pass with shifr
		//	//		bool chpass = true;
		//	//	}
		//	//	else if (b == 1)
		//	//	{
		//	//		cout << "Recent to mainmenu." << endl;
		//	//	}
		//	//}
	}

	inline void guest::enter()
	{

		unique_ptr<guest> gu(new guest);
		cout << "Hello, please, enter your login and password" << endl;
		cout << endl;
		cout << "Login : "; // добавить в папку с пользователями, чтобы файл с админом не трогали.
		cin >> gu->log;
		string loginhash;
		loginhash = md5(gu->log);
		string checktxt = gu->folder + "/" + loginhash + ".txt";
		ifstream in(checktxt);
		if (in.is_open())
		{
			system("cls");
			bool check = false;
			int ras = 0;
			int count = 0;
			string passcheck, logcheck;
			while (!in.eof())
			{
				while (count != 2)
				{
					if (count == 1)
						getline(in, passcheck);
					else if (count == 0)
						getline(in, logcheck);
					count++;
				}
				break;
			}
			in.close();
			while (ras != 5 && check != true)
			{
				cout << "Hello, please, enter your login and password" << endl;
				cout << endl;
				cout << "Login : " << gu->log << endl;
				cout << endl;
				cout << "Password : ";
				cin >> gu->pass;
				string passhash;
				passhash = md5(gu->pass);
				ras++;

				if (passhash == passcheck && loginhash == logcheck)
				{
					check = true;
				}
				else
				{
					cout << endl;
					cout << "______________________________________" << endl;
					cout << endl;
					cout << "Wrong pass or login. Please try again." << endl;
					cout << "______________________________________" << endl;
					cout << endl;
					cout << endl;
					cout << "You have : " << 5 - ras << " attempts." << endl;
					cout << endl;
					system("pause");
					system("cls");
				}
			}
			if (ras > 4)
			{
				//если попыток больше 5 выдать ошибку и отправить в меню
				cout << "Sorry, but you had to much wrong attempts, try again later." << endl;
				cout << "Perhaps the user with this login is already taken. Try to enter a different login" << endl;
				system("pause");
				exit(0);
				/*mainmenu();*/
			}
		}
		else
		{
			system("cls");
			bool s;
			cout << "Account registration. Take the steps you need. Remember all data." << endl;
			cout << "Replacement of data is possible when you confirm the necessary data." << endl;
			cout << "Enter \"1\" to continue registration, or \"0\" to exit" << endl;
			cin >> s;
			if (s == true)
			{
				bool ch1 = false;
				while (ch1 != true)
				{
					system("cls");
					string l, p;
					cout << "Hello, please, enter your login and password" << endl;
					cout << endl;
					cout << "Login : ";
					cin >> l;

					/*string path = this->folder + "/" + md5(l) + ".txt";*/

					string loginhash;
					loginhash = md5(l);
					cout << endl;
					cout << "Password : ";
					cin >> p;
					cin.ignore();
					cout << endl;
					string passhash;
					passhash = md5(p);
					cout << "FIO : ";
					string fio;
					getline(cin, fio);
					cout << endl;
					cout << "Telephone number : +";
					string tel;
					getline(cin, tel);
					cout << endl;
					cout << "Home address : ";
					string address;
					getline(cin, address);
					ifstream i(gu->folder);
					if (i.is_open())
					{
						break; // Возможна проблема
					}
					else
					{
						create_directory(gu->folder);
						create_directory(gu->UserStat);
					}
					i.close();
					ifstream inf(gu->folder + "/" + loginhash + ".txt");
					if (inf.is_open())
					{
						cout << "______________________________________________" << endl;
						cout << endl;
						cout << "This login already taken. Enter another login." << endl;
						cout << "______________________________________________" << endl;
						cout << endl;
						system("pause");
					}
					else
					{
						ch1 = true;
						string path = gu->folder + "/" + loginhash + ".txt";
						ofstream out(path);
						out << loginhash << endl;
						out << passhash << endl;
						out << fio;
						out.close();
						string path1 = gu->UserStat + "/" + "UserInfo.txt";
						ofstream uout(path1, ios::app);
						uout << tel << "\n" << "FIO : " << fio << " Home address : " << address << "\n";
						uout.close();
						string path2 = gu->UserStat + "/" + "DatabaseStudents.txt";
						ofstream dout(path2, ios::app);
						dout << tel << "\n" << fio << ". Login : " << l << "\n";
						dout.close();
						create_directory(gu->UserStat + "/" + l);
					}
					inf.close();
				}
			}
			else
			{
				exit(0);/*mainmenu();*/
			}
		}
	}

	inline void guest::resultsearch()
	{
		/*printAll();
		//	cout << endl;
		//	string log;
		//	cout << "Enter the number of a car : ";
		//	cin >> log;
		//	List<Protocol*>* list = base.get(num);
		//	list->print();
		//	system("pause");*/
	}



	class admin : public login
	{
	public:
		admin() {};
		~admin() {};

		void addCategory();
		void editguest(); //создавать в разные файлы новых кентиков, а потом удалять, номер который не нужен
		void deleteguest(); //просто удалить по номеру кента
		virtual void changepassword() override;
		/*bool checkpass();*/
		void result();
		virtual void enter() override;
		virtual void resultsearch() override;
	};

	inline void admin::addCategory()
	{
		unique_ptr<admin> ad(new admin);
		map<string, string> mp;
		string key, category;
		int count = 0;
		ifstream ifq(ad->TestFolder + "/" + "category.txt");
		if (ifq.is_open())
		{
			while (!ifq.eof())
			{
				getline(ifq, key);
				getline(ifq, category);

				if (key != "")
					mp[key] = category;
				count++;
			}
			count--;
		}
		else
		{
			cout << "You have not added category yet. File has been added." << endl;
			cout << endl;
			create_directory(ad->TestFolder);
			ofstream ofs(ad->TestFolder + "/" + "category.txt");
		}
		ifq.close();
		bool ch2 = false;
		while (ch2 != true)
		{
			if (mp.size())
			{
				cout << "List categories that have been added : " << endl;
				cout << endl;
				for (auto i = mp.begin(); i != mp.end(); ++i)
				{
					cout << i->first << ". " << i->second << endl;
				}
				cout << endl;
			}
			cout << "Add new category. Please enter a test category name." << endl;
			cin >> category;
			ifstream ifw(ad->TestFolder + "/" + category + "/" + ad->emptyFile);
			if (ifw.is_open())
			{
				cout << "________________________________________________" << endl;
				cout << endl;
				cout << "This category is already in the list. Try again." << endl;
				cout << "________________________________________________" << endl;
				cout << endl;
				system("pause");
				ifw.close();
				system("cls");
			}
			else
			{
				ch2 = true;
				ofstream ofq(ad->TestFolder + "/" + "category.txt", ios::app);
				ofq << ++count << endl;
				ofq << category << endl;
				ofq.close();
				create_directory(ad->TestFolder + "/" + category + "/");
				ofstream emp(ad->TestFolder + "/" + category + "/" + ad->emptyFile);
				emp.close();
				system("pause");
			}
		}
		
	}

	inline void admin::editguest()
	{
	}

	inline void admin::deleteguest()
	{
	}


	inline void admin::changepassword()
	{
		//bool b;
		//bool chpass = false;
		//while (b != 1 && chpass != true)
		//{
		//	
		//	cout << "Do you really want to edit your pass?" << endl;
		//	cout << "Enter 0 to agree or 1 to disagree." << endl;
		//	cin >> b;
		//	if (b == 0)
		//	{
		//		remove("adminpass.txt");
		//		// plus add new pass with shifr
		//		bool chpass = true;
		//	}
		//	else if (b == 1)
		//	{
		//		cout << "Recent to mainmenu." << endl;
		//	}
		//}
	}

	//inline bool admin::checkpass()
	//{
	//	/*printAll();
	//	cout << endl;
	//	string log;
	//	cout << "Enter the number of a car : ";
	//	cin >> log;
	//	List<Protocol*>* list = base.get(num);
	//	list->print();
	//	system("pause");*/
	//	return true;
	//}

	inline void admin::result()
	{
	}

	inline void admin::enter()
	{	
		ifstream in("admin.txt");
		if (in.is_open())
		{
			bool check = false;
			unique_ptr<admin> ad(new admin);
			int ras = 0;
			int count = 0;
			string passcheck, logcheck;
			while (!in.eof())
			{
				while (count != 2)
				{
					if (count == 1)
						getline(in, passcheck);
					else if (count == 0)
						getline(in, logcheck);
					count++;
				}
				break;
			}
			in.close();
			while (ras != 5 && check!= true)
			{
				cout << "Hello, please, enter your login and password" << endl;
				cout << endl;
				cout << "Login : ";
				cin >> ad->log;
				string loginhash;
				loginhash = md5(ad->log);
				cout << endl;
				cout << "Password : ";
				cin >> ad->pass;
				string passhash;
				passhash = md5(ad->pass);
				ras++;
				
				if (passhash == passcheck && loginhash == logcheck)
				{
					check = true;
				}
				else
				{
					cout << endl;
					cout << "______________________________________" << endl;
					cout << endl;
					cout << "Wrong pass or login. Please try again." << endl;
					cout << "______________________________________" << endl;
					cout << endl;
					cout << endl;
					cout << "You have : " << 5 - ras << " attempts." << endl;
					cout << endl;
					system("pause");
					system("cls");
				}
			}
			if (ras > 4)
			{
				//если попыток больше 5 выдать ошибку и отправить в меню
				cout << "Sorry, but you had to much wrong attempts, try again later." << endl;
				system("pause");
				exit(0);
				/*mainmenu();*/
			}
		}
		else
		{
			bool s;
			cout << "You aren`t have admin account, do you want to add admin account?" << endl;
			cout << "Warnings! If you forgot your pass or login, call to your it admin to change pass." << endl;
			cout << "You can do only one account, in future you will can change pass and login." << endl;
			cout << "Write 1 to do account, or 0 to leave." << endl;
			cin >> s;
			if (s == true)
			{
				string l, p;
				cout << "Hello, please, enter your login and password" << endl;
				cout << endl;
				cout << "Login : ";
				cin >> l;
				string loginhash;
				loginhash = md5(l);
				cout << endl;
				cout << "Password : ";
				cin >> p;
				string passhash;
				passhash = md5(p);
				ofstream out("admin.txt");
				out << loginhash << endl;
				out << passhash;
				out.close();
				
			}
			else
			{
				exit(0);/*mainmenu();*/
			}
		}
	}

	inline void admin::resultsearch()
	{
		/*printAll();
		cout << endl;
		string log;
		cout << "Enter the number of a car : ";
	//	cin >> log;
	//	List<Protocol*>* list = base.get(num);
	//	list->print();
	//	system("pause");*/
	//	return true;
	}



