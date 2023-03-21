#include <iostream>
#include <windows.h>

#include "CustomString.h"

#define MY_TEST_9


int main()
{
#if defined(MY_TEST_1) //printing customwstring by the help of WCHAR*

	CustomWString mystring;
	std::wcin >> mystring;
	WCHAR* arar = mystring.get();
	std::wcout << L"|" << arar << L"|";

#elif defined(MY_TEST_2) //checking local operator= 

	CustomWString mystring = L"AAA";
	CustomWString mysecondstring = L"BBB";

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"mysecondstring: " << mysecondstring << std::endl;

	mystring += mysecondstring;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"mysecondstring: " << mysecondstring << std::endl;

	mysecondstring = mystring;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"mysecondstring: " << mysecondstring << std::endl;

#elif defined(MY_TEST_3) //testing capacity with WCHAR*

	CustomWString mystring;
	const WCHAR* arar = L"A";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"1234567890123456789";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"A";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_4) //testing capacity with another customwstring

	CustomWString mystring;
	CustomWString arar = L"A";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"1234567890123456789";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"A";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_5) //checking operator+= for WCHAR

	CustomWString mystring;
	WCHAR arar = L'A';

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L'B';

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_6) // testing operators += and = for std::wstring

	CustomWString mystring;
	std::wstring arar = L"AAA";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"BBB";

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_7) // comparing (== operator)
	CustomWString mystring;
	mystring = L"rawr";



	std::wcout << L"WCHAR*: ";
	if (mystring == L"rawr")
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << L"rawr" << L"|";
	std::wcout << std::endl;



	std::wcout << L"std::wstring: ";
	std::wstring arr = L"rawr";
	if (mystring == arr)
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << arr << L"|";
	std::wcout << std::endl;



	std::wcout << L"customString: ";
	CustomWString mystring2;
	mystring2 = L"rawr";
	if (mystring == mystring2)
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << mystring2 << L"|";
	std::wcout << std::endl;

#elif defined(MY_TEST_8) // testing operator= for WCHAR
	CustomWString mystring;

	mystring = L"A";
	std::wcout << L"|" << mystring << L"|";

	mystring = L"B";
	std::wcout << L"|" << mystring << L"|";

	mystring = L"RUNEWPIRNWIENRINWERINWIOTNOIWTITNWEIUOTNEIWNT";
	mystring = L"C";
	std::wcout << L"|" << mystring << L"|";

#elif defined(MY_TEST_9) // testing operator== for WCHAR

	CustomWString mystring;

	mystring = L'A';
	std::wcout << L"test1: ";
	CustomWString mystring2;
	if (mystring == 'A')
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << L'A' << L"|";
	std::wcout << std::endl;

	mystring = L'B';
	std::wcout << L"test2: ";
	if (mystring == L'B')
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << L'B' << L"|";
	std::wcout << std::endl;

	mystring = L"RUNEWPIRNWIENRINWERINWIOTNOIWTITNWEIUOTNEIWNT";
	mystring = L'C';
	std::wcout << L"test3: ";
	if (mystring == L'C')
		std::wcout << L"passed";
	else
		std::wcout << L"failed" << L"|" << mystring << L"|  vs   |" << L'C' << L"|";
	std::wcout << std::endl;

#endif

	while (TRUE) {}

}