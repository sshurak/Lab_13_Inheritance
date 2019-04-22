#pragma once
#ifndef People_H
#define People_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Exams.h"
#include "Subject.h"


class Exams;
class Subject;

class People
{
protected:
	std::string name;
	int age;
public:
	bool operator==(std::string name1) { return(name == name1); }
	bool PScan(std::ifstream &f);
	virtual std::ostream& OutData(std::ostream &f)
	{
		f << "Name: " << name << "\nAge: " << age << "\n";
		return f;
	}
	virtual void AddData(std::string inname)
	{
		name = inname;
		std::cout << "¬ведите возраст: ";
		std::cin >> age;
	}
	friend std::ostream& operator<<(std::ostream & f, People &data);
};

class Worker
{
protected:
	std::string career;
	int experience;
public:
};

class Student : public People
{
private:
	int size;
	float avg;
	std::vector<Exams> pass;
public:
	Student()
	{
		size = 0;
		avg = 0;
	}
	bool operator==(std::string name1) { return(name == name1); }
	bool operator==(int mark)
	{
		std::vector<Exams>::iterator it = find(pass.begin(), pass.end(), mark);
		if ((it == pass.end()))
			return false;
		else
			return true;
	}
	void DeleteExams();
	std::ostream& OutData(std::ostream &f)
	{
		f << "Student: " << name << "\nAge: " << age << "\nAverage: (" << avg << ")\n";
		OutPass(f);
		return f;
	}
	void AddExams();
	std::ostream& OutPass(std::ostream &f);
	bool Scan(std::ifstream &f);
	void average();
	void AddData(std::string inname)
	{
		name = inname;
		std::cout << "¬ведите возраст: ";
		std::cin >> age;
		AddExams();
		sort(pass.begin(), pass.end());
	}
	void Edit();
};

class Teacher : public People, public Worker
{
private:
	Subject *subj;
public:
	bool Scan(std::ifstream &f);
	std::ostream& OutData(std::ostream &f)
	{
		f << "Teacher: " << name << "\nAge: " << age << "\nCareer: " << career << "\nExperience: " << experience << "\nSubject: " << subj << "\n";
		return f;
	}
	void AddData(std::string input_name)
	{
		name = input_name;
		career = "Teacher";
		std::cout << "¬ведите возраст: ";
		std::cin >> age;
		std::cout << "¬ведите стаж: ";
		std::cin >> experience;
		AddSubject();
	}
	void Delete();
	void AddSubject();
};


#endif