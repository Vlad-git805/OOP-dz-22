#pragma once
#include "Firm.h"
#include "List.h"
class Directory
{
private:
	List list;
public:

	void AddFirmToList(const Firm& fr)
	{
		list.AddToTail(fr);
	}

	void Find_by_Name(string name)
	{
		list.Find_by_Name(name).ShowInfo();
	}

	void Find_by_Owner(string owner)
	{
		list.Find_by_Owner(owner).ShowInfo();
	}

	void Find_by_Telephone(string telephone)
	{
		list.Find_by_Telephone(telephone).ShowInfo();
	}

	void Find_by_kind_of_activity(string kind_of_activity)
	{
		list.Find_by_kind_of_activity(kind_of_activity).ShowInfo();
	}

	void ShowAllFirmsInDirectory()
	{
		list.Print();
	}

	void Write_to_file()
	{
		ofstream fout("file.txt");
		fout << list;
		fout.close();
	}

	void Load_from_file()
	{
		ifstream ifs("file.txt");
		ifs >> list;
		ifs.close();
	}
};

