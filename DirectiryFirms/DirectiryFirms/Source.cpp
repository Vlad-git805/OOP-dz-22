#include <iostream>
#include <string>
#include <fstream>
#include "Directory.h"
#include "Firm.h"
using namespace std;

int main()
{

	Firm firm1("228", "Vlad", "0509636139", "lytsk", "gamedev");
	Firm firm2("322", "Vas9", "0501234569", "Rivne", "webdev");

	Directory frstDir;

	frstDir.AddFirmToList(firm1);
	frstDir.AddFirmToList(firm2);

	frstDir.Write_to_file();

	Directory frstDir2;

	frstDir2.Load_from_file();
	frstDir2.ShowAllFirmsInDirectory();

	system("pause");
	return 0;
}