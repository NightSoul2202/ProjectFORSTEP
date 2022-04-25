#pragma once
#include"MENU.h"

using namespace std::experimental::filesystem;

	class login
	{
	protected:
		
	public:
		virtual void resultsearch() = 0;
		virtual void changepassword() = 0;
		// здесь нужны гетеры и сетеры, такие как фио телефон и тд
	};

	class guest : public login
	{
	public:
		
		/*void registration();*/
		void dotask();
		virtual void changepassword() override;
		//{
		//	//bool b;
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
		//}
		virtual void resultsearch() override;
		//{
		//	/*printAll();
		//	cout << endl;
		//	string log;
		//	cout << "Enter the number of a car : ";
		//	cin >> log;
		//	List<Protocol*>* list = base.get(num);
		//	list->print();
		//	system("pause");*/
	
		//}
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
		/*bool logintrue = false;*/
		
	public:

		void editguest(); //создавать в разные файлы новых кентиков, а потом удалять, номер который не нужен
		void deleteguest(); //просто удалить по номеру кента
		virtual void changepassword() override;
		/*bool checkpass();*/
		void result();
		virtual void resultsearch() override;
	};

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

class Task
{
	//alltask
public:
	void newtask(); // добавление нового задание, через стринг текст теста, потом ответ и так каждая строка, чтобы можнео было считать тест
	void task();
	void edittask(); //удалить тест, а потом добавить его вновь

	void deletetask();
	/*void newcategory();*/// тоесть новая папка с опреденными заданиями.
	/*void category();*/
};

inline void Task::newtask()
{
	// проверка на существование уже таких категорий
	cout << "Do new category of test" << endl; //Например тесты по школьным предметам
	path p;
	cin >> p;
	create_directory(p);
	cout << "What the new academic subject?" << endl; //Например тесты по математике
	path s;
	cin >> s;
	create_directory(s);


}

inline void Task::edittask()
{
	system("pause");
}




