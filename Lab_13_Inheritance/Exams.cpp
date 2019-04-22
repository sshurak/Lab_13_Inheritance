#include "Exams.h"

bool Exams::Scan(std::ifstream &f)
{
	std::string namesubj1;
	f >> (namesubj1);
	if (namesubj1.length() == 0)
		return 1;
	subj = &(*find(SubjList1.begin(),SubjList1.end(), namesubj1));
	f >> (mark);
	return 0;
}

std::ostream& operator<<(std::ostream & f, Exams &data)
{
	f << data.subj << "(" << data.mark << ")\n";
	return f;
}

void Exams::AddData()
{
	OutSubj();
	std::cout << "Введите предмет: ";
	std::string name;
	do {
		std::cin >> name;
		std::vector<Subject>::iterator h = find(SubjList1.begin(), SubjList1.end(), name);
		if (h == SubjList1.end())
			std::cout << "Предмет не обнауржен.\n";
		else
			subj == &(*h);
	} while (subj == NULL);
	std::cout << "Введите оценку: ";
	std::cin >> mark;
}