#pragma once
#include"MENU.h"

using namespace std::experimental::filesystem;

void gotoxy(int, int);

	class gotomenu //��������� �����, ����� ���������� � ������� ����.
	{
	public:
		void go()
		{
			system("cls");
			int gotx = 10;
			gotoxy(30, ++gotx);
			cout << "Ok. Go to main menu.";
			Sleep(2000);
		}
	};

	class login
	{
	protected:
		string log;
		string pass;
		string folder = "LoginAccounts";
		string UserStat = "UserStat";
		string TestFolder = "TestFolder";
		string emptyFile = "emptyFile.txt"; //������, ������ ���� ��������� �������� �� ����� ���������, ����� �� ������� �����.(���������� �� ���)
		string testname = "testname.txt";
		string testquantity = "testquantity.txt";

		/*string UsersFolder = "UsersFolder";
		string StudentsFile = "StudentsFile.txt";*/

	public:
		login() {};
		~login() {};
		virtual void enter() = 0;
		virtual void resultsearch() = 0;
		virtual void changepassword() = 0;
		string getla() { return this->folder; }
		
		
		string getpass() { return this->pass; }
		string getlogin() { return this->log; }
		void setpass(string setpass) { pass = setpass; }
		void setlogin(string setlogin) { log = setlogin; }

	
		// ����� ����� ������ � ������, ����� ��� ��� ������� � ��
	};

	class guest : public login
	{
	public:
		guest() {};
		~guest() {};
		/*void registration();*/
		void dotask();
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
		cout << "Login : "; // �������� � ����� � ��������������, ����� ���� � ������� �� �������.
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
				//���� ������� ������ 5 ������ ������ � ��������� � ����
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
			int s;
			cout << "Account registration. Take the steps you need. Remember all data." << endl;
			cout << "Replacement of data is possible when you confirm the necessary data." << endl;
			cout << "Enter \"1\" to continue registration, or \"0\" to exit" << endl;
			cin >> s;
			if (s == 1)
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
						break; // �������� ��������
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
				exit(0);
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
		void addnameoftest();
		void addtest();
		void deletetest();
		void editguest(); //��������� � ������ ����� ����� ��������, � ����� �������, ����� ������� �� �����
		void deleteguest(); //������ ������� �� ������ �����
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
			ofs.close();//
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

	inline void admin::addnameoftest()
	{
		system("cls");
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
			ifq.close();
		}
		else
		{
			cout << "You have not added category yet." << endl;
			cout << "Do you want to add new category? (yes = 1 / no = 0)" << endl;
			int yy;
			cin >> yy;
			if (yy == 1)
			{
				addCategory();
			}
			else
			{
				gotomenu g;
				g.go();
			}
		}
		if (mp.size())
		{
			cout << "List categories that have been added : " << endl;
			cout << endl;
			for (auto i = mp.begin(); i != mp.end(); ++i)
			{
				cout << i->first << ". " << i->second << endl;
			}
			cout << endl;

			cout << "Enter the category number in which you want to add a new test name." << endl;
			string findkey;
			cin >> findkey;

			auto it = mp.find(findkey);

			if (it != mp.end())
			{
				map<string, string> m;
				count = 0;
				ifstream id(ad->TestFolder + "/" + it->second + "/" + ad->testname);
				if (id.is_open())
				{			
					while (!id.eof())
					{

						getline(id, key);
						getline(id, category);

						if (key != "")
							m[key] = category;
						count++;
					}
					count--;
					id.close();

					string nt;
					bool ch3 = false;
					while (ch3 != true)
					{
						system("cls");
						if (m.size())
						{
							cout << "List categories that have been added : " << endl;
							cout << endl;
							for (auto i = m.begin(); i != m.end(); ++i)
							{
								cout << i->first << ". " << i->second << endl;
							}
							cout << endl;
						}

						cout << "Enter the name of test :" << endl;
						cout << endl;
						cin >> nt;
					
						ifstream ifr(ad->TestFolder + "/" + it->second + "/" + nt + "/" + ad->emptyFile);
						if (ifr.is_open())
						{
							cout << "____________________________________________________" << endl;
							cout << endl;
							cout << "This name of test is already in the list. Try again." << endl;
							cout << "____________________________________________________" << endl;
							cout << endl;
							system("pause");
						}
						else
						{
							ch3 = true;
						}
					}
					create_directory(ad->TestFolder + "/" + it->second + "/" + nt);
					ofstream ofs(ad->TestFolder + "/" + it->second + "/" + ad->testname, ios::app);
					ofs << ++count << endl;
					ofs << nt << endl;
					ofs.close();
					ofstream emp(ad->TestFolder + "/" + it->second + "/" + nt + "/" + ad->emptyFile);
					emp.close();
				}
				else
				{
					system("cls");
					cout << "You have not test in " << it->second << " category." << endl;
					int c = 0;
					cout << "Enter the name of test" << endl;
					string nt;
					cin >> nt;

					create_directory(ad->TestFolder + "/" + it->second + "/" + nt);
					ofstream ofs(ad->TestFolder + "/" + it->second + "/" + ad->testname);
					ofs << ++c << endl;
					ofs << nt << endl;
					ofs.close();
					ofstream emp(ad->TestFolder + "/" + it->second + "/" + nt + "/" + ad->emptyFile);
					emp.close();
				}	
			}
		}
	}

	inline void admin::addtest()
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
			ifq.close();
		}
		else
		{
			cout << "You have not added category yet." << endl;
			cout << "Do you want to add new category? (yes = 1 / no = 0)" << endl;
			int yy;
			cin >> yy;
			if (yy == 1)
			{
				addCategory();
			}
			else 
			{
				gotomenu g;
				g.go();
			}
		}
		if (mp.size())
		{
			cout << "List categories that have been added : " << endl;
			cout << endl;
			for (auto i = mp.begin(); i != mp.end(); ++i)
			{
				cout << i->first << ". " << i->second << endl;
			}
			cout << endl;

			cout << "Enter the category number in which you want to add a new test." << endl;
			string findkey;
			cin >> findkey;

			auto it = mp.find(findkey);

			if (it != mp.end())
			{
				
				map<string, string> m;
				ifstream id(ad->TestFolder + "/" + it->second + "/" + ad->testname);
				while (!id.eof())
				{
					getline(id, key);
					getline(id, category);

					if (key != "")
						m[key] = category;
					count++;
				}
				count--;

				if (!id.is_open())
				{
					cout << "You haven`t the test name folder. Do you want to add? ( yes = 1 / no = 0 )" << endl;
					int bb;
					cin >> bb;
					if (bb == 1)
					{
						addnameoftest();
					}
					else
					{
						gotomenu g;
						g.go();
					}
				}
				else
				{
					system("cls");
					if (m.size())
					{
						cout << "List categories that have been added : " << endl;
						cout << endl;
						for (auto i = m.begin(); i != m.end(); ++i)
						{
							cout << i->first << ". " << i->second << endl;
						}
						cout << endl;
					}
					id.close();
					cout << "You have this test." << endl;
					cout << "Do you want to add new test name? ( yes = 1 / no = 0 )" << endl;
					int qq;
					cin >> qq;
					if (qq == 1)
					{
						addnameoftest();
					}
					else
					{
						system("cls");
						if (m.size())
						{
							cout << "List categories that have been added : " << endl;
							cout << endl;
							for (auto i = m.begin(); i != m.end(); ++i)
							{
								cout << i->first << ". " << i->second << endl;
							}
							cout << endl;
						}
						cout << "Enter the category number in which you want to add a new test." << endl;
						string findkey_test;
						cin >> findkey_test;
						auto ite = m.find(findkey_test);
						if (ite != m.end())
						{
							cout << "How much questions do you want to add?" << endl;
							int quest;
							cin >> quest;
							int col = 0;
							
							while (col != quest)
							{
								count = 1;
								int q_key = 0, a_key = 0;
								string question, answer;

								map<int, string> mquestion;
								map<int, string> manswer;
								system("cls");
								cout << "Enter question :" << endl;
								

								ifstream ifs(ad->TestFolder + "/" + it->second + "/" + ite->second + "/" + ad->testquantity);
								if (!ifs.is_open())
								{
									cout << "You dont have questions in this test." << endl;
									ofstream of(ad->TestFolder + "/" + it->second + "/" + ite->second + "/" + ad->testquantity);
									of.close();
								}
								else
								{
									while (!ifs.eof())
									{
										char* buff = new char[5];
										ifs.getline(buff, 5);
										count = atoi(buff);
										delete[] buff;
										ifs.close();
									}
									cout << "You have " << count << " question in this test;" << endl;
									count++;
									int fline = -1;
									string test_q;
									for (size_t i = 1; i < count; i++)
									{
										ifstream ifr(ad->TestFolder + "/" + it->second + "/" + ite->second + "/" + to_string(i) + ".txt");
										if (ifr.is_open())
										{
											for (size_t q = 0; q < 2; q++)
											{
												getline(ifr, test_q);
												if (!fline)
												{
													cout << i << ". " << test_q << endl;
													fline = -2;
												}
												fline++;
											}
											ifr.close();
										}
										else
										{
											cout << "Error, file haven`t been opened. Maybe you haven`t had a file." << endl;
											system("pause");
										}
									}

									cout << "Enter the " << count << " question." << endl;
									cin.ignore();
									cin >> question;
									q_key = count;
									mquestion.emplace(q_key, question);
									int n;
									cout << "Enter amount of responses : " << endl;
									cin.ignore();
									cin >> n;
									cout << "Enter answers to the question : " << endl;

									cin.ignore();

									for (size_t i = 1; i < n + 1; i++)
									{
										cout << i << ". ";
										getline(cin, answer);
										manswer.emplace(++a_key, answer);
									}

									cout << "Enter the number of the correct answer to the question : " << endl;
									cin >> n;

									ofstream ofs;

									ofs.open(ad->TestFolder + "/" + it->second + "/" + ite->second + "/" + ad->testquantity);
									ofs << q_key;
									ofs.close();
									ofs.open(ad->TestFolder + "/" + it->second + "/" + ite->second + "/" + to_string(q_key) + ".txt");
									ofs << n << endl;

									for (auto it = mquestion.begin(); it != mquestion.end(); ++it)
									{
										ofs << it->second << endl;
									}

									for (auto it = manswer.begin(); it != manswer.end(); ++it)
									{
										ofs << it->first << ". " << it->second << endl;
									}

									ofs.close();
								}
								col++;
							}
						}
						else
						{
							cout << "Uncorrect number of test." << endl;
							system("pause");
						}
					}
				}
			}
			else
			{
				cout << "Uncorrect number of test." << endl;
				system("pause");
			}
		}
		else
		{
			cout << "You have not added category yet." << endl;
			cout << "Do you want to add new category? (yes = 1 / no = 0)" << endl;
			int yy;
			cin >> yy;
			if (yy == 1)
			{
				addCategory();
			}
			else
			{
				gotomenu g;
				g.go();
			}
		}
	}

	inline void admin::deletetest()
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
			ifq.close();
		}
		else
		{
			cout << "You have not added category yet." << endl;
			system("pause");
			gotomenu g;
			g.go();
		}
		if (mp.size())
		{
			cout << "List categories that have been added : " << endl;
			cout << endl;
			for (auto i = mp.begin(); i != mp.end(); ++i)
			{
				cout << i->first << ". " << i->second << endl;
			}
			cout << endl;

			cout << "Enter the category number in which you want to add a new test." << endl;
			string findkey;
			cin >> findkey;

			auto it = mp.find(findkey);

			if (it != mp.end())
			{
				map<string, string> m;
				ifstream id(ad->TestFolder + "/" + it->second + "/" + ad->testname);
				while (!id.eof())
				{
					getline(id, key);
					getline(id, category);

					if (key != "")
						m[key] = category;
					count++;
				}
				count--;

				if (!id.is_open())
				{
					cout << "You haven`t the test." << endl;
					system("pause");
					gotomenu g;
					g.go();
				}
				else
				{
					system("cls");
					if (m.size())
					{
						cout << "List categories that have been added : " << endl;
						cout << endl;
						for (auto i = m.begin(); i != m.end(); ++i)
						{
							cout << i->first << ". " << i->second << endl;
						}
						cout << endl;
					}
					else
					{
						cout << "You haven`t test to delete them." << endl;
						system("pause");
						gotomenu g;
						g.go();
					}
					cout << "Enter the number of test which do you want to delete." << endl;
					string findkey_test;
					cin >> findkey_test;
					auto ite = m.find(findkey_test);
					if (ite != m.end())
					{
						path p = ad->TestFolder + "/" + it->second + "/" + ite->second;
						string p1 = ad->TestFolder + "/" + it->second + "/" + ad->testname;
						remove_all(p);
						m.erase(ite->first);
						ofstream ofs;
						ofs.open(p1);

						int c = 1;
						for (auto it = m.begin(); it != m.end(); ++it)
						{
							ofs << c++ << endl << it->second << endl;
						}
						ofs.close();
					}
					else
					{
						cout << "Uncorrect number of test." << endl;
						system("pause");
					}
				}
			}
			else
			{
				cout << "Uncorrect number of test." << endl;
				system("pause");
			}
		}
		else
		{
			cout << "You have not added category yet." << endl;
			system("pause");
			gotomenu g;
			g.go();
		}

	}

	inline void admin::editguest()
	{
	}

	inline void admin::deleteguest()
	{
		unique_ptr<admin> ad(new admin);
		map<string, string> mp;
		map<string, string> m;
		string key, category, key_l, category_l;
		ifstream ifq(ad->UserStat + "/" + "DatabaseStudents.txt");
		if (ifq.is_open())
		{
			while (!ifq.eof())
			{
				getline(ifq, key);
				getline(ifq, category);

				if (key != "")
					mp[key] = category;
			}
			ifq.close();
			ifstream i(ad->UserStat + "/" + "UserInfo.txt");
			if (i.is_open())
			{
				while (!i.eof())
				{
					getline(i, key_l);
					getline(i, category_l);

					if (key_l != "")
						m[key_l] = category_l;
				}
				i.close();
				if (mp.size())
				{
					cout << "List user that have been added : " << endl;
					cout << endl;
					for (auto i = mp.begin(); i != mp.end(); ++i)
					{
						cout << "Phone number : " << i->first << " . " << i->second << endl;
					}
					cout << endl;
				}
				else
				{
					cout << "You haven`t users in system." << endl;
					system("pause");
					gotomenu g;
					g.go();
				}
				cout << "Enter phone number to delete user." << endl;
				cin >> key;
				auto it = mp.find(key);
				if (it != mp.end())
				{
					cout << "Enter LOGIN to confirm" << endl;
					string login;
					cin >> login;
					string logcheck;
					logcheck = this->getla() + "/" + md5(login) + ".txt";

					remove(logcheck);
					mp.erase(key);
					m.erase(key);
					string p = ad->UserStat + "/" + login;
					remove_all(p);
					string p1 = ad->UserStat + "/" + "DatabaseStudents.txt";
					string p2 = ad->UserStat + "/" + "UserInfo.txt";
					ofstream of;
					of.open(p1);
					for (auto it = mp.begin(); it != mp.end(); ++it)
					{
						of << it->first << endl << it->second << endl;
					}
					of.close();

					of.open(p2);
					for (auto it = mp.begin(); it != mp.end(); ++it)
					{
						of << it->first << endl << it->second << endl;
					}
					of.close();
				}
				else
				{
					cout << "In system wasnt found this user." << endl;
					system("pause");
					gotomenu g;
					g.go();
				}
			}
			else
			{
				cout << "You haven`t usera in system." << endl;
				system("pause");
				gotomenu g;
				g.go();
			}
		}
		else
		{
			cout << "You haven`t user in system." << endl;
			system("pause");
			gotomenu g;
			g.go();
		}
		

		
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
				//���� ������� ������ 5 ������ ������ � ��������� � ����
				cout << "Sorry, but you had to much wrong attempts, try again later." << endl;
				system("pause");
				exit(0);
				/*mainmenu();*/
			}
		}
		else
		{
			int s;
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
				exit(0); /*mainmenu();*/
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

	

