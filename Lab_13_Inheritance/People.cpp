#include "People.h"
#include "Exams.h"
#include "Subject.h"

bool People::PScan(std::ifstream &f)
{
	try
	{
		f >> name;
		if (name.length() == 0)
			return 1;
		f >> age;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& operator<<(std::ostream & f, People &data)
{
	data.OutData(f);
	return f;
}

bool Student::Scan(std::ifstream &f)
{
	try
	{
		if (PScan(f))
			return 1;
		f >> size;
		for (int i = 0; i < size; i++)
		{
			Exams nexam;
			bool flag = nexam.Scan(f);
			if (!flag)
			{
				pass.push_back(nexam);
			}
		}
		average();
		sort(pass.begin(), pass.end());
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

void Student::average()
{
	float result = 0;
	for (auto i = pass.begin(); i < pass.end(); i++)
		result += i->getMark();
	avg = round((result/size) * 10) / 10;
}

void Student::Edit()
{
	char select = '0';
	do {
		std::cout << "1.Добавить экзамен студенту.\n2.Исправить экзамен студента.\n";
		std::cin >> select;
	} while ((select != '1') && (select != '2'));
	std::cout << "Список экзаменов:\n";
	OutPass(std::cout);
	std::string name1;
	std::cout << "Общий список предметов:\n";
	Exams::OutSubj();
	std::vector<Subject>::iterator chs = Exams::SubjList1.end();
	std::cout << "Предмет, по которому сдан экзамен: ";
	do
	{
		std::cin >> name1;
		chs = find(Exams::SubjList1.begin(), Exams::SubjList1.end(), name1);
		if (chs == Exams::SubjList1.end())
			std::cout << "Предмет не обнаружен.\n";
	} while (chs == Exams::SubjList1.end());
	switch (select)
	{
	case '1':
	{
		std::vector<Exams>::iterator h = find(pass.begin(), pass.end(), name1);
		if (h != pass.end())
		{
			std::cout << "Экзамен уже сдан.\n";
			return;
		}
		Exams a;
		a.setSubj(&(*chs));
		int mark;
		std::cout << "Введите оценку: ";
		std::cin >> mark;
		a.setMark(mark);
		pass.push_back(a);
		size++;
		break;
	}
	case '2':
	{
		std::vector<Exams>::iterator check = find(pass.begin(), pass.end(), name1);
		if (check != pass.end())
		{
			int mark;
			std::cout << "Введите оценку: ";
			std::cin >> mark;
			check->setMark(mark);
			break;
		}
		std::cout << "Экзамен не обнаружен.\n";
		return;
	}
	}
	average();
	sort(pass.begin(), pass.end());
}

void Student::DeleteExams()
{ pass.~vector(); }

bool Teacher::Scan(std::ifstream &f)
{
	try
	{
		if (PScan(f))
			return 1;
		std::string nameofcareer;
		f >> (nameofcareer);
		if (nameofcareer.length() == 0)
			return 1;
		career = nameofcareer;
		f >> experience;
		std::string namesubj1;
		f >> namesubj1;
		subj = &(*find(Exams::SubjList1.begin(), Exams::SubjList1.end(), namesubj1));
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& Student::OutPass(std::ostream &f)
{
	for (auto i = pass.begin(); i < pass.end(); i++)
		f << *i;
	f << std::endl;
	return f;
}

void Student::AddExams()
{
	std::cout << "Введите число экзаменов: ";
	std::cin >> size;
	for (int i = 0; i < size; i++)
	{
		Exams nexam;
		nexam.AddData();
		pass.push_back(nexam);
	}
	average();
	sort(pass.begin(), pass.end());
}

void Teacher::Delete()
{
	subj = NULL;
}

void Teacher::AddSubject()
{
	Exams::OutSubj();
	std::cout << "Введите предмет: ";
	std::string name;
	subj = NULL;
	do {
		std::cin >> name;
		std::vector<Subject>::iterator h = find(Exams::SubjList1.begin(), Exams::SubjList1.end(), name);
		if (h == Exams::SubjList1.end())
			std::cout << "Предмет не обнаружен.\n";
		else
			subj = &(*h);
	} while (subj == NULL);
}