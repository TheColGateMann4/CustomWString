#include <iostream>
#include <windows.h>

#include "CustomString.h"

#define MY_TEST_2


int main()
{
#if defined(MY_TEST_1)

	CustomWString mystring;
	std::wcin >> mystring;
	WCHAR* arar = mystring.get();
	std::wcout << L"|" << arar << L"|";

#elif defined(MY_TEST_2)

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
#endif

	while(true){}

}