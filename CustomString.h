#include <iostream>
#include <windows.h>

class CustomWString {
public:
	CustomWString(const WCHAR* text);
	CustomWString();
	~CustomWString();

public:
	WCHAR* get() const;
	UINT32 length() const;
	UINT32 capacity() const;

public:
	CustomWString& operator+=(const WCHAR& character);

	CustomWString& operator=(const CustomWString& customString);
	CustomWString& operator+=(const CustomWString& customString);

	CustomWString& operator=(const WCHAR* text);
	CustomWString& operator+=(const WCHAR* text);

	CustomWString& operator=(const std::wstring& text);
	CustomWString& operator+=(const std::wstring& text);

	friend std::wostream& operator<<(std::wostream& os, const CustomWString& customWString);
	friend std::wistream& operator>>(std::wistream& os, CustomWString& customWString);

private:
	VOID m_FreeMemory();
	VOID m_ZeroMemory(void* adress, UINT32 size);

private:
	void* m_dataptr;
	UINT32 m_length;
	UINT32 m_capacity;

	const static UINT32 m_additionalCapacity = 15;
	const static UINT32 m_margin = 2;
};