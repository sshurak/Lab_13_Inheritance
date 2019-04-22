#pragma once
#ifndef Subject_H
#define Subject_H
#include <iostream>
#include <fstream>
#include <string>

class Subject
{
private:
	std::string NameSubj;
public:
	bool operator==(std::string namesubj1) { return(NameSubj == namesubj1); }
	friend std::ostream& operator<<(std::ostream & f, Subject *data);
	friend std::ostream& operator<<(std::ostream & f, Subject &data);
	std::string GetNameSubj() { return NameSubj; }
	bool Scan(std::ifstream &f);
};

#endif