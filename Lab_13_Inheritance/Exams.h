#pragma once
#ifndef Exams_H
#define Exams_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Subject.h"

class Subject;

class Exams
{
private:
	int mark;
	Subject* subj;
public:
	static std::vector<Subject> SubjList1;
	static void OutSubj()
	{
		for (int i = 0; i < (Exams::SubjList1.end() - Exams::SubjList1.begin()); i++)
			std::cout << Exams::SubjList1[i];
	}
	static Subject* FindSubject(std::string name1)
	{
		for (int i = 0; i < (SubjList1.end() - SubjList1.begin()); i++)
		{
			if (Exams::SubjList1[i] == name1)
				return &Exams::SubjList1[i];
		}
		return NULL;
	}
	Exams()
	{
		subj = NULL;
		mark = 0;
	}
	bool Scan(std::ifstream &f);
	void AddData();
	int getMark() { return mark; }
	void setMark(int inname) { mark = inname; }
	void setSubj(Subject *insubj) { subj = insubj; }
	bool operator!=(int mark1) { return(mark != mark1); }
	bool operator==(int mark1) { return(mark == mark1); }
	bool operator>(int mark1) { return(mark > mark1); }
	bool operator<(int mark1) { return(mark < mark1); }
	bool operator>=(int mark1) { return(mark >= mark1); }
	bool operator<=(int mark1) { return(mark <= mark1); }
	bool operator!=(Exams& A) { return(mark != A.getMark()); }
	bool operator==(Exams& A) { return(mark == A.getMark()); }
	bool operator>(Exams& A) { return(mark > A.getMark()); }
	bool operator<(Exams& A) { return(mark < A.getMark()); }
	bool operator>=(Exams& A) { return(mark >= A.getMark()); }
	bool operator<=(Exams& A) { return(mark <= A.getMark()); }
	bool operator==(std::string name1) { return(*subj == name1); }
	friend std::ostream& operator<<(std::ostream & f, Exams &data);

};

#endif