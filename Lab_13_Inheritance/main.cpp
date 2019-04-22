#include <vector>
#include <iostream>
#include "Exams.h"
#include "People.h"
#include "Subject.h"


#define INSTUD "students.txt"
#define INTEACHER "teachers.txt"
#define OUT "output.txt"
#define INSUBJECT "subjects.txt"

using namespace std;

std::vector<Subject> Exams::SubjList1;

template<class T>
void From(vector<T> &a, const char* file)
{
	ifstream fin(file);
	while (fin)
	{
		T now;
		bool flag = now.Scan(fin);
		if (!flag)
		{
			a.push_back(now);
		}
	}
	fin.close();
}

template<class T>
void OutList(vector<T> &a)
{
	for (int i = 0; i < (a.end() - a.begin()); i++)
		cout << a[i];
}

template <class T>
void ToFile(vector<T>& a)
{
	ofstream fout(OUT);
	for (int i = 0; i < (a.end() - a.begin()); i++)
			fout << a[i];
	fout.close();
}

int main()
{
	char slct, c;
	string name1;
	setlocale(LC_ALL, "");
	From(Exams::SubjList1, INSUBJECT);
	vector<Student> S;
	vector<Teacher> P;
	do
	{

		cout << "1. Считать список из файла.\n";
		cout << "2. Вывести список на экран.\n";
		cout << "3. Записать список в файл.\n";
		cout << "4. Удалить элемент из списка.\n";
		cout << "5. Добавить элемент в список.\n";
		cout << "6. Изменить информацию о студенте.\n";
		cout << "7. Вывести общий список.\n";
		cout << "8. Удалить студентов с определённой оценкой.\n";
		cout << "9. Завершить выполнение программы.\n";
		cin >> slct;
		switch (slct)
		{
		case'1':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> c;
			if (c == '1')
				From(S, INSTUD);
			if (c == '2')
				From(P, INTEACHER);
			break;
		case'2':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				OutList(S);
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				OutList(P);
			}
			break;
		case'3':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				ToFile(S);
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				ToFile(P);
			}
			break;
		case'5':
		{
			if (S.empty())
			{
				cout << "Список пуст.\n"; break;
			}
			cout << "Введите имя:\n";
			cin >> name1;
			vector<Student>::iterator much = find(S.begin(), S.end(), name1);
			if (much == S.end())
			{
				cout << "Студент не обнаружен.\n"; break;
			}
			much->Edit();
			break;
		}
		case'6':
		{
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				cout << "Введите имя:\n";
				cin >> name1;
				S.erase(remove(S.begin(), S.end(), name1), S.end());
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				cout << "Введите имя:\n";
				cin >> name1;
				P.erase(remove(P.begin(), P.end(), name1), P.end());
			}
			break;
		}
		case'4':
		{
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> c;
			if (c == '1')
			{
				cout << "Введите имя:\n";
				cin >> name1;
				if (find(S.begin(), S.end(), name1) == S.end())
				{
					Student now;
					now.AddData(name1);
					S.push_back(now);
				}
				else
					cout << "Cтудент уже есть в списке.\n";
			}
			if (c == '2')
			{
				cout << "Введите имя:\n";
				cin >> name1;
				if (find(P.begin(), P.end(), name1) == P.end())
				{
					Teacher now;
					now.AddData(name1);
					P.push_back(now);
				}
				else
					cout << "Преподаватель уже есть в списке.\n";
			}
			break;
		}
		case'7':
		{
			if (P.empty() && S.empty())
			{
				cout << "Списки пусты.\n"; break;
			}
			vector<People*> H;
			for (auto i = S.begin(); i < S.end(); i++)
			{
				H.push_back(&*i);
			}
			for (auto i = P.begin(); i < P.end(); i++)
			{
				H.push_back(&*i);
			}
			for (auto i = H.begin(); i < H.end(); i++)
				cout << *(*i);
			break;
		}
		case'8':
		{
			if (S.empty())
			{
				cout << "Список пустой.\n"; break;
			}
			int mark = 2;
			cout << "Введите оценку:\n";
			cin >> mark;
			S.erase(remove(S.begin(), S.end(), mark), S.end());
			break;
		}
		}
	} while (slct != '9');
}