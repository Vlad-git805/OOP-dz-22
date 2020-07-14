#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Firm
{
private:
	string name_firm;
	string owner;
	string telephone;
	string adress;
	string kind_of_activity;
public:
	Firm() : name_firm(" "), owner(" "), telephone(" "), adress(" "), kind_of_activity(" ") {}
	Firm(string nama_firm, string owner, string telephone, string adress, string kind_of_activity) : name_firm(nama_firm), owner(owner), telephone(telephone), adress(adress), kind_of_activity(kind_of_activity) {}
	void ShowInfo()const
	{
		cout << "Name of firm: " << name_firm << endl;
		cout << "Owner: " << owner << endl;
		cout << "Telephone: " << telephone << endl;
		cout << "Adress: " << adress << endl;
		cout << "Kind of activity: " << kind_of_activity << endl;
	}

	string Get_name()
	{
		return name_firm;
	}

	string Get_owner()
	{
		return owner;
	}

	string Get_telephone()
	{
		return telephone;
	}

	string Get_adress()
	{
		return adress;
	}

	string Get_kind_of_activity()
	{
		return kind_of_activity;
	}

	friend ofstream& operator<<(ofstream& fout, const Firm& fl);
	friend ifstream& operator>>(ifstream& ifs, Firm& fl);
};

ofstream& operator<<(ofstream& fout, const Firm& fl)
{
	fout << fl.name_firm << endl;
	fout << fl.owner << endl;
	fout << fl.telephone << endl;
	fout << fl.adress << endl;
	fout << fl.kind_of_activity << endl;

	return fout;
}

ifstream& operator>>(ifstream& ifs, Firm& fl)
{
	ifs >> fl.name_firm;
	ifs >> fl.owner;
	ifs >> fl.telephone;
	ifs >> fl.adress;
	ifs >> fl.kind_of_activity;
	return ifs;
}