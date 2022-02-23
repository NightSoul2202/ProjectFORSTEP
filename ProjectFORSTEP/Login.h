#pragma once
#include"MENU.h"

	class login
	{
	protected:
		
	public:
		virtual void result() = 0;
		virtual void resultsearch() = 0;
		virtual void changepass() = 0;
		// здесь нужны гетеры и сетеры, такие как фио телефон и тд
	};

	class guest : public login
	{
	public:
		/*void registration();*/
		void dotask();
		virtual void changepass() override
		{
			//bool b;
			//bool chpass = false;
			//while (b != 1 && chpass != true)
			//{
			//	
			//	cout << "Do you really want to change your pass?" << endl;
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
		virtual void resultsearch() override
		{
			/*printAll();
			cout << endl;
			string log;
			cout << "Enter the number of a car : ";
			cin >> log;
			List<Protocol*>* list = base.get(num);
			list->print();
			system("pause");*/
	
		}
	};



	class admin : public login
	{
		/*bool logintrue = false;*/
	public:
		void changeguest(); //создавать в разные файлы новых кентиков, а потом удалять, номер который не нужен
		void deleteguest(); //просто удалить по номеру кента
		void changetask(); //удалить тест, а потом добавить его вновь
		void donewtask(); // добавление нового задание, через стринг текст теста, потом ответ и так каждая строка, чтобы можнео было считать тест
		virtual void changepass() override;
		/*bool checkpass();*/
		virtual void result() override;
		virtual void resultsearch() override;
	};

	inline void admin::changeguest()
	{
	}

	inline void admin::deleteguest()
	{
	}

	inline void admin::changetask()
	{
	}

	inline void admin::donewtask()
	{
	}

	inline void admin::changepass()
	{
		//bool b;
		//bool chpass = false;
		//while (b != 1 && chpass != true)
		//{
		//	
		//	cout << "Do you really want to change your pass?" << endl;
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
	void newtask();
	void task();
	void edittask();

	void deletetask();
	void newcategory();
	void category();
};




