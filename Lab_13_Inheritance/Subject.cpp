#include "Subject.h"

bool Subject::Scan(std::ifstream &f)
{
	try
	{
		f >> (NameSubj);
		if (NameSubj.length() == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& operator<<(std::ostream & f, Subject *data)
{
	f << data->NameSubj;
	return f;
}

std::ostream& operator<<(std::ostream & f, Subject &data)
{
	f << data.NameSubj << "\n";
	return f;
}
