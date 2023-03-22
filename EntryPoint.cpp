#include <iostream>
#include <windows.h>

#include "CustomString.h"


int main()
{
	std::wcout << std::endl << L"printing customwstring by the help of WCHAR*: " << std::endl;
	{
		CustomWString mystring;
		std::wcin >> mystring;
		WCHAR* arar = mystring.get();
		std::wcout << L"|" << arar << L"|";
		std::wcout << std::endl;
	}


	std::wcout << std::endl << L"checking local operator+= and operator=: " << std::endl;
	{
		CustomWString mystring = L"AAA";
		CustomWString mysecondstring = L"BBB";

		mystring += mysecondstring;

		if (mystring == L"AAABBB")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		mysecondstring = mystring;

		if (mysecondstring == L"AAABBB")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;
	}

	std::wcout << std::endl << L"testing capacity with WCHAR*: " << std::endl;
	{
		CustomWString mystring;
		const WCHAR* arar = L"A";

		mystring = arar;

		if (mystring == L"A")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		arar = L"1234567890123456789";

		mystring = arar;

		if (mystring == L"1234567890123456789")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		arar = L"A";

		mystring = arar;

		if (mystring == L"A")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;
	}


	std::wcout << std::endl << L"testing capacity with another customwstring: " << std::endl;
	{
		CustomWString mystring;
		CustomWString arar = L'A';

		mystring = arar;

		if (mystring == L'A' && mystring == L'A')
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		arar = L"1234567890123456789";

		mystring = arar;

		if (mystring == L"1234567890123456789" && arar == L"1234567890123456789")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		arar = L"A";

		mystring = arar;

		if (mystring == L'A' && mystring == L'A')
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;
	}


	std::wcout << std::endl << L"checking operator+= for WCHAR: " << std::endl;
	{
		CustomWString mystring;
		WCHAR arar = L'A';

		mystring += arar;

		if (mystring == L'A')
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		mystring += L'B';

		if (mystring == L"AB")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;
	}


	std::wcout << std::endl << "testing operators += and = for std::wstring: " << std::endl;
	{
		CustomWString mystring;
		std::wstring arar = L"AAA";

		mystring = arar;
		if (mystring == L"AAA")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;

		arar = L"BBB";

		mystring += arar;

		if (mystring == L"AAABBB")
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|";
		std::wcout << std::endl;
	}


	std::wcout << std::endl << L"comparing (== operator): " << std::endl;
	{
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
	}


	std::wcout << std::endl << L"testing operator= for WCHAR: " << std::endl;
	{
		CustomWString mystring;

		mystring = L'A';

		if (mystring == L'A' && mystring.capacity() == 16)
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|  " << mystring.capacity();
		std::wcout << std::endl;

		mystring = L'B';

		if (mystring == L'B' && mystring.capacity() == 16)
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|  " << mystring.capacity();
		std::wcout << std::endl;

		mystring = L"RUNEWPIRNWIENRINWERINWIOTNOIWTITNWEIUOTNEIWNT";
		mystring = L'C';

		if(mystring == L'C' && mystring.capacity() == 16)
			std::wcout << L"passed";
		else
			std::wcout << L"failed" << L"|" << mystring << L"|  " << mystring.capacity();
		std::wcout << std::endl;
	}


	std::wcout << std::endl << "testing operator== for WCHAR: " << std::endl;
	{
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
	}

	while (TRUE) {}

}