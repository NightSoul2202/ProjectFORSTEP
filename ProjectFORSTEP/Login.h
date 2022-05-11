#pragma once
#include"MENU.h"

using namespace std::experimental::filesystem;

void gotoxy(int, int);

	class gotomenu //мусоргный класс, чтобы переходить в главное меню.
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
		string ltt = "login_test_try.txt";
		string folder = "LoginAccounts";
		string UserStat = "UserStat";
		string TestFolder = "TestFolder";
		string emptyFile = "emptyFile.txt"; //Хитрый, пустой файл благодаря которому мы можем проверять, можно ли открыть папку.(Существует ли она)
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
		int getmark(int correct_answ, int done_answ);
		virtual void changepassword() override;
		virtual void enter() override;
		virtual void resultsearch() override;
	private:
		string txtname;

		
	};

	inline void guest::dotask()
	{
		unique_ptr<guest> gu(new guest);
		map<string, string> mp;
		string key, category;
		int count = 0;
		ifstream ifq(gu->TestFolder + "/" + "category.txt");
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
			cout << "Sorry, but we dont have added tests yet." << endl;
			system("pause");
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

			cout << "Enter the category number test." << endl;
			string findkey;
			cin >> findkey;

			auto it = mp.find(findkey);

			if (it != mp.end())
			{
				map<string, string> m;
				ifstream id(gu->TestFolder + "/" + it->second + "/" + gu->testname);
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
					cout << "Sorry, but we dont have added tests yet." << endl;
					system("pause");
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
						cout << "Sorry, but we dont have added tests yet." << endl;
						system("pause");
						exit(0);
					}
					cout << "Enter the number of test which do you want to do." << endl;
					string findkey_test;
					cin >> findkey_test;
					auto ite = m.find(findkey_test);

					if (ite != m.end())
					{
						string question_load, answer_load;
						int answer_take;
						int correct_answ = 0; //correct answer;
						int done_answ = 0; //done answer;
						ifstream iw(gu->TestFolder + "/" + it->second + "/" + ite->second + "/" + gu->testquantity);
						int n = 0;
						while (!iw.eof())
						{
							char* buff = new char[5];
							iw.getline(buff, 5);
							n = atoi(buff);
							delete[] buff;
						}
						
						if (iw.is_open())
						{
							for (size_t i = 1; i < n + 1; i++)
							{
								system("cls");
								string path = gu->TestFolder + "/" + it->second + "/" + ite->second + "/" + to_string(i) + ".txt";
								ifstream ir;
								ir.open(path);
								getline(ir, answer_load);
								while (!ir.eof())
								{
									question_load = ""; // clear question string;
									getline(ir, question_load);
									cout << question_load << endl;
								}
								ir.close();
								cout << "Question number : " << i << " ;" << endl;
								cout << "Enter number of answer : ";
								cin >> answer_take;
								cout << endl;
								if (to_string(answer_take) == answer_load) // int to string
								{
									correct_answ++;
								}
								done_answ++;
							}
							string login_try;
							ifstream irs;
							irs.open(ltt);
							getline(irs, login_try);
							irs.close();
							cout << endl;
							int test_mark = getmark(correct_answ, done_answ);
							cout << "Congratulation!!!" << endl;
							cout << "Test end. Your result is " << correct_answ << " correct answers of " << done_answ << " questions." << endl;

							ofstream ofq(gu->UserStat + "/" + login_try + "/" + "successful_test.txt", ios::app);
							ofq << "Test: " << ite->second << ";" << endl;
							ofq << "Mark: " << test_mark << ";" << endl;
							ofq << "Question on test: " << done_answ << ";" << endl;
							ofq << "____________________" << endl;
							ofq << endl;
							ofq.close();

							ofstream of(gu->UserStat + "/" + "user_successful_tests.txt", ios::app);
							of << "Login: " << login_try << endl;
							of << "Test: " << ite->second << ";" << endl;
							of << "Mark: " << test_mark << ";" << endl;
							of << "Question on test: " << done_answ << ";" << endl;
							of << "____________________" << endl;
							of << endl;
							of.close();
							system("pause");
						}
						else
						{
							cout << "Sorry, but we dont have added tests yet." << endl;
							system("pause");
						}
					}
					else
					{
						cout << "Sorry, but we dont have added tests yet." << endl;
						system("pause");
					}
				}
			}
			else
			{
				cout << "Sorry, but we dont have added tests yet." << endl;
				system("pause");
			}
		}
		else
		{
			cout << "Sorry, but we dont have added tests yet." << endl;
			system("pause");
		}

	}

	inline int guest::getmark(int correct_answ, int done_answ)
	{
		int mark;

		int uncorrect_answ;
		uncorrect_answ = done_answ - correct_answ;
		double mark100 = (done_answ - uncorrect_answ) / (double)done_answ * 100;
		if (correct_answ == done_answ)
			return mark = 12;
		if (mark100 >= 94)
		{
			mark = 11;
			return mark;
		}
		else if (mark100 >= 86)
		{
			mark = 10;
			return mark;
		}
		else if (mark100 >= 78)
		{
			mark = 9;
			return mark = 9;
		}
		else if (mark100 >= 70)
		{
			mark = 8;
			return mark;
		}
		else if (mark100 >= 62)
		{
			mark = 7;
			return mark;
		}
		else if (mark100 >= 54)
		{
			mark = 6;
			return mark;
		}
		else if (mark100 >= 46)
		{
			mark = 5;
			return mark;
		}
		else if (mark100 >= 34)
		{
			mark = 4;
			return mark;
		}
		else if (mark100 >= 22)
		{
			mark = 3;
			return mark;
		}
		else if (mark100 >= 10)
		{
			mark = 2;
			return mark;

		}
		else
		{
			return mark = 1;
		}
			
	}

	inline void guest::changepassword()
	{
		unique_ptr<guest> gu(new guest);
		map <string, string> mp;
		string loginq, passq, fioq;
		cout << "Enter your login to change password" << endl;
		string login;
		cin >> login;
		string logincheck = md5(login);
		string path = gu->folder + "/" + logincheck + ".txt";
		ifstream ifs(path);
		if (!ifs.is_open())
		{
			cout << "Uncorrect login." << endl;
			system("pause");
		}
		else
		{
			cout << "Enter new password." << endl;
			string pass;
			cin >> pass;
			string passcheck = md5(pass);

			while (!ifs.eof())
			{
				getline(ifs, loginq);
				getline(ifs, passq);
				getline(ifs, fioq);
			}
			bool ch1 = false;
			string passc;
			while (ch1 != true)
			{
				cout << "Enter new password again" << endl;
				cin >> passc;
				if (pass != passc)
				{
					cout << "Uncorrect password." << endl;
					system("pause");
				}
				else
				{
					ch1 = true;
				}
			}
			ofstream of(path);
			of << loginq << endl;
			of << passcheck << endl;
			of << fioq;
			of.close();
		}
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
					ofstream off(ltt);
					off << gu->log;
					off.close();
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
				exit(0);
			}
		}
	}

	inline void guest::resultsearch()
	{
		unique_ptr<guest> gu(new guest);
		string login_test_try;
		string get_result;
		ifstream ifr;
		ifr.open(ltt);
		getline(ifr, login_test_try);
		ifr.close();
		cout << "Your results is : " << endl;
		ifstream ifs;
		ifs.open(gu->UserStat + "/" + login_test_try + "/" + "successful_test.txt");
		while(!ifs.eof())
		{
			get_result = "";
			getline(ifs, get_result);
			cout << get_result << endl;
		}
		ifs.close();
		system("pause");
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
		void deleteguest();
		virtual void changepassword() override;
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
				exit(0);
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
				exit(0);
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
						exit(0);
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
			exit(0);
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
					exit(0);
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
					exit(0);
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
					logcheck = ad->folder + "/" + md5(login) + ".txt";

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
		string login, password;
		path p = "admin.txt";
		remove(p);
		cout << "Enter new login : ";
		cin >> login;
		string logincheck, passcheck;
		logincheck = md5(login);
		cout << "Enter new password : ";
		cin >> password;
		passcheck = md5(password);
		ofstream of("admin.txt");
		of << logincheck << endl;
		of << passcheck;
		of.close();
		cout << "Login and password was changed." << endl;
		system("pause");
	}

	inline void admin::result()
	{
		unique_ptr<admin> ad(new admin);
		string get_result;
		cout << "Your results is : " << endl;
		ifstream ifs;
		ifs.open(ad->UserStat + "/" + "user_successful_tests.txt");
		while (!ifs.eof())
		{
			get_result = "";
			getline(ifs, get_result);
			cout << get_result << endl;
		}
		ifs.close();
		system("pause");
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

	

