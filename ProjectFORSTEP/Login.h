#pragma once
#include"MENU.h"

using namespace std::experimental::filesystem;

	class login
	{
	protected:
		
	public:
		virtual void resultsearch() = 0;
		virtual void changepassword() = 0;
		// ����� ����� ������ � ������, ����� ��� ��� ������� � ��
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

		void editguest(); //��������� � ������ ����� ����� ��������, � ����� �������, ����� ������� �� �����
		void deleteguest(); //������ ������� �� ������ �����
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
	void newtask(); // ���������� ������ �������, ����� ������ ����� �����, ����� ����� � ��� ������ ������, ����� ������ ���� ������� ����
	void task();
	void edittask(); //������� ����, � ����� �������� ��� �����

	void deletetask();
	/*void newcategory();*/// ������ ����� ����� � ����������� ���������.
	/*void category();*/
};

inline void Task::newtask()
{
	// �������� �� ������������� ��� ����� ���������
	cout << "Do new category of test" << endl; //�������� ����� �� �������� ���������
	path p;
	cin >> p;
	create_directory(p);
	cout << "What the new academic subject?" << endl; //�������� ����� �� ����������
	path s;
	cin >> s;
	create_directory(s);


}

inline void Task::edittask()
{
	system("pause");
}




