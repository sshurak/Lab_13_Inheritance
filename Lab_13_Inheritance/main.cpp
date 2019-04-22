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

		cout << "1. ������� ������ �� �����.\n";
		cout << "2. ������� ������ �� �����.\n";
		cout << "3. �������� ������ � ����.\n";
		cout << "4. ������� ������� �� ������.\n";
		cout << "5. �������� ������� � ������.\n";
		cout << "6. �������� ���������� � ��������.\n";
		cout << "7. ������� ����� ������.\n";
		cout << "8. ������� ��������� � ����������� �������.\n";
		cout << "9. ��������� ���������� ���������.\n";
		cin >> slct;
		switch (slct)
		{
		case'1':
			cout << "�������� ������ ��� �������������:\n1. ��������.\n2. �������������.\n";
			cin >> c;
			if (c == '1')
				From(S, INSTUD);
			if (c == '2')
				From(P, INTEACHER);
			break;
		case'2':
			cout << "�������� ������ ��� �������������:\n1. ��������.\n2. �������������.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "������ ������.\n"; break;
				}
				OutList(S);
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "������ ������.\n"; break;
				}
				OutList(P);
			}
			break;
		case'3':
			cout << "�������� ������ ��� �������������:\n1. ��������.\n2. �������������.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "������ ������.\n"; break;
				}
				ToFile(S);
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "������ ������.\n"; break;
				}
				ToFile(P);
			}
			break;
		case'5':
		{
			if (S.empty())
			{
				cout << "������ ����.\n"; break;
			}
			cout << "������� ���:\n";
			cin >> name1;
			vector<Student>::iterator much = find(S.begin(), S.end(), name1);
			if (much == S.end())
			{
				cout << "������� �� ���������.\n"; break;
			}
			much->Edit();
			break;
		}
		case'6':
		{
			cout << "�������� ������ ��� �������������:\n1. ��������.\n2. �������������.\n";
			cin >> c;
			if (c == '1')
			{
				if (S.empty())
				{
					cout << "������ ������.\n"; break;
				}
				cout << "������� ���:\n";
				cin >> name1;
				S.erase(remove(S.begin(), S.end(), name1), S.end());
			}
			if (c == '2')
			{
				if (P.empty())
				{
					cout << "������ ������.\n"; break;
				}
				cout << "������� ���:\n";
				cin >> name1;
				P.erase(remove(P.begin(), P.end(), name1), P.end());
			}
			break;
		}
		case'4':
		{
			cout << "�������� ������ ��� �������������:\n1. ��������.\n2. �������������.\n";
			cin >> c;
			if (c == '1')
			{
				cout << "������� ���:\n";
				cin >> name1;
				if (find(S.begin(), S.end(), name1) == S.end())
				{
					Student now;
					now.AddData(name1);
					S.push_back(now);
				}
				else
					cout << "C������ ��� ���� � ������.\n";
			}
			if (c == '2')
			{
				cout << "������� ���:\n";
				cin >> name1;
				if (find(P.begin(), P.end(), name1) == P.end())
				{
					Teacher now;
					now.AddData(name1);
					P.push_back(now);
				}
				else
					cout << "������������� ��� ���� � ������.\n";
			}
			break;
		}
		case'7':
		{
			if (P.empty() && S.empty())
			{
				cout << "������ �����.\n"; break;
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
				cout << "������ ������.\n"; break;
			}
			int mark = 2;
			cout << "������� ������:\n";
			cin >> mark;
			S.erase(remove(S.begin(), S.end(), mark), S.end());
			break;
		}
		}
	} while (slct != '9');
}