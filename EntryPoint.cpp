#include <iostream>
#include <windows.h>

#include "CustomString.h"

#define MY_TEST_8


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
#elif defined(MY_TEST_3)
	CustomWString mystring;
	const WCHAR* arar = L"T9";
	mystring += arar;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"TIUPWERBITUERTUBIOWEBIUIUB";
	mystring += arar;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_4)

	CustomWString mystring;
	CustomWString arar = L"T9";
	mystring += arar;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"RTYRTENREUNTYRUNRTYIRTNYUNITY";
	mystring += arar;

	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_5)
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

#elif defined(MY_TEST_6)

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

#elif defined(MY_TEST_7)

	CustomWString mystring;
	WCHAR arar = L'A';

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L'B';

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#elif defined(MY_TEST_8)

	CustomWString mystring;
	std::wstring arar = L"AAA";

	mystring = arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

	arar = L"BBB";

	mystring += arar;
	std::wcout << L"mystring: " << mystring << std::endl;
	std::wcout << L"arar: " << arar << std::endl;

#endif

	while (TRUE) {}

}