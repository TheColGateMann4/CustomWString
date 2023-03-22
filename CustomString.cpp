#include "CustomString.h"


/*

//				\/ CONSTRUCTORS & DESTUCTOR \/

*/


CustomWString::CustomWString(const WCHAR* text)
{
	UINT32 textLength = (UINT32)wcslen(text);

	this->m_length = textLength;
	this->m_capacity = this->m_length + this->m_additionalCapacity;
	this->m_dataptr = std::malloc((this->m_length + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

	wmemmove(static_cast<WCHAR*>(this->m_dataptr), text, textLength);
	this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + this->m_length, this->m_additionalCapacity + this->m_margin);
}




CustomWString::CustomWString(const WCHAR character)
{
	this->m_length = 1;
	this->m_capacity = this->m_length + this->m_additionalCapacity;
	this->m_dataptr = std::malloc((this->m_length + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

	this->get()[0] = character;
	this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + this->m_length, this->m_additionalCapacity + this->m_margin);
}




CustomWString::CustomWString()
{
	this->m_dataptr = nullptr;
	this->m_length = NULL;
	this->m_capacity = NULL;
}




CustomWString::~CustomWString()
{
	this->m_FreeMemory();
}


/*

//				\/ PUBLIC FUNCTIONS \/

*/


WCHAR* CustomWString::get() const
{
	return static_cast<WCHAR*>(this->m_dataptr);
}




UINT32 CustomWString::length() const
{
	return this->m_length;
}




UINT32 CustomWString::capacity() const
{
	return this->m_capacity;
}


/*

//				\/ OPERATORS \/

*/


CustomWString& CustomWString::operator+=(const WCHAR& character)
{
	void* data = nullptr;

	bool no_container = (this->m_dataptr == nullptr);
	bool length_greater_than_capacity = ((this->m_dataptr != nullptr) && (this->m_length + 1 > this->m_capacity));


	if (length_greater_than_capacity)
		data = std::realloc(this->m_dataptr, (this->m_length + 1 + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));
	if (no_container)
		data = std::malloc((1 + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

	if (length_greater_than_capacity || no_container)
	{
		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_capacity = this->m_length + 1 + this->m_additionalCapacity;
		this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + this->m_length + 1, this->m_additionalCapacity + this->m_margin);
	}

	WCHAR* temp = static_cast<WCHAR*>(this->m_dataptr) + this->m_length;
	*temp = character;

	this->m_length++;

	return *this;
}




CustomWString& CustomWString::operator=(const WCHAR& character)
{
	void* data = nullptr;

	bool no_container = (this->m_dataptr == nullptr);
	bool container_will_have_too_much_capacity = FALSE;

	if (this->m_dataptr != nullptr)
		container_will_have_too_much_capacity = (this->m_capacity - 1) > 15;


	if(container_will_have_too_much_capacity)
		this->m_FreeMemory();

	if (no_container || container_will_have_too_much_capacity)
	{
		data = std::malloc((1 + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_length = 1;
		this->m_capacity = this->m_additionalCapacity + this->m_length;
	}

	this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + 1, this->m_additionalCapacity + this->m_margin);

	this->get()[0] = character;

	return *this;
}




CustomWString& CustomWString::operator=(const CustomWString& customString)
{
	if (this == &customString)
		return *this;

	void* data = nullptr;


	bool no_container = (this->m_dataptr == nullptr);
	bool length_greater_than_capacity = (this->m_dataptr != nullptr) && (customString.length() > this->capacity());
	bool container_will_have_too_much_capacity = FALSE;

	if (this->capacity() > customString.length())
		container_will_have_too_much_capacity = ((this->m_capacity - customString.length()) > 15);


	if (container_will_have_too_much_capacity)
		this->m_FreeMemory();

	if (length_greater_than_capacity)
		data = std::realloc(this->m_dataptr, (customString.length() + this->m_margin + this->m_additionalCapacity) * sizeof(WCHAR));
	else if (no_container || container_will_have_too_much_capacity)
		data = std::malloc((this->m_margin + this->m_additionalCapacity + customString.length()) * sizeof(WCHAR));

	if (container_will_have_too_much_capacity || no_container || length_greater_than_capacity)
	{
		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_capacity = customString.length() + this->m_additionalCapacity;
		this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + customString.length(), this->m_additionalCapacity + this->m_margin);
	}


	wmemmove(static_cast<WCHAR*>(this->m_dataptr), customString.get(), customString.length());
	this->m_length = customString.length();

	return *this;
}




CustomWString& CustomWString::operator=(const WCHAR* text)
{
	UINT32 textLength = (UINT32)wcslen(text);
	void* data = nullptr;


	bool no_container = (this->m_dataptr == nullptr);
	bool length_greater_than_capacity = (this->m_dataptr != nullptr) && (textLength > this->m_capacity);
	bool container_will_have_too_much_capacity = FALSE; 

	if ((this->m_capacity > textLength && (this->m_dataptr != nullptr)))
		container_will_have_too_much_capacity = (this->m_capacity - textLength) > 15;


	if (container_will_have_too_much_capacity)
			this->m_FreeMemory();

	if (length_greater_than_capacity)
		data = std::realloc(this->m_dataptr, (textLength + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));
	else if (no_container || container_will_have_too_much_capacity)
		data = std::malloc((textLength + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));


	if (length_greater_than_capacity || no_container || container_will_have_too_much_capacity)
	{
		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_capacity = textLength + this->m_additionalCapacity;
		this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + textLength, this->m_additionalCapacity + this->m_margin);
	}

	wmemmove(static_cast<WCHAR*>(this->m_dataptr), text, textLength);

	this->m_length = textLength;

	return *this;
}

BOOL CustomWString::m_isEqualToWChar(const WCHAR* text)
{
	UINT32 textLength = (UINT32)wcslen(text);
	if (this->length() != textLength)
		return FALSE;

	WCHAR* localWCHAR = this->get();

	for (UINT32 i = 0;;)
	{
		if (localWCHAR[i] != text[i])
			return FALSE;

		if (i++ == this->length())
			return TRUE;
	}
}




bool CustomWString::operator==(const WCHAR& character)
{
	return this->get()[0] == character;
}




bool CustomWString::operator==(const WCHAR* text)
{
	return m_isEqualToWChar(text);
}




bool CustomWString::operator==(const CustomWString& customString)
{
	return m_isEqualToWChar(customString.get());
}




bool CustomWString::operator==(const std::wstring& text)
{
	return m_isEqualToWChar(text.c_str());
}




CustomWString& CustomWString::operator+=(const CustomWString& customString)
{
	void* data = nullptr;

	bool no_container = (this->m_dataptr == nullptr);
	bool length_greater_than_capacity = ((this->m_dataptr != nullptr) && ((customString.length() + this->m_length) > this->m_capacity));

	if (length_greater_than_capacity)
		data = std::realloc(this->m_dataptr, (this->m_length + customString.length() + this->m_margin + this->m_additionalCapacity) * sizeof(WCHAR));
	else if (no_container)
		data = std::malloc((customString.length() + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

	if (no_container || length_greater_than_capacity)
	{
		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_capacity = this->m_length + customString.length() + this->m_additionalCapacity;
		this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + this->m_length + customString.length(), this->m_additionalCapacity + this->m_margin);
	}

	wmemmove(static_cast<WCHAR*>(this->m_dataptr) + this->m_length, customString.get(), customString.length());

	this->m_length += customString.length();

	return *this;
}




CustomWString& CustomWString::operator+=(const WCHAR* text)
{
	UINT32 textLength = wcslen(text);
	void* data = nullptr;

	bool no_container = (this->m_dataptr == nullptr);
	bool length_greater_than_capacity = (this->m_dataptr != nullptr && ((textLength + this->m_length) > this->m_capacity));


	if (length_greater_than_capacity)
		data = std::realloc(this->m_dataptr, (this->m_length + textLength + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));
	else if (no_container)
		data = std::malloc((textLength + this->m_additionalCapacity + this->m_margin) * sizeof(WCHAR));

	if (length_greater_than_capacity || no_container)
	{
		if (data == nullptr)
			abort();

		this->m_dataptr = data;
		this->m_capacity = this->m_length + textLength + this->m_additionalCapacity;
		this->m_ZeroMemory(static_cast<WCHAR*>(this->m_dataptr) + this->m_length + textLength, this->m_additionalCapacity + this->m_margin);
	}

	wmemmove(static_cast<WCHAR*>(this->m_dataptr) + this->m_length, text, textLength);

	this->m_length += textLength;

	return *this;
}




CustomWString& CustomWString::operator+=(const std::wstring& text)
{
	*this += text.c_str();

	return *this;
}




CustomWString& CustomWString::operator=(const std::wstring& text)
{
	*this = text.c_str();

	return *this;
}




/*

//				\/ PRIVATE MEMORY MANAGEMENT \/

*/


VOID CustomWString::m_FreeMemory()
{
	free(this->m_dataptr);
}




VOID CustomWString::m_ZeroMemory(void* adress, UINT32 size)
{
	if (size == 0)
		return;

	wmemset(static_cast<WCHAR*>(adress), 0, size);
}


/*

//				\/ OVERLOADED STD OPERATORS \/

*/


std::wostream& operator<<(std::wostream& os, const CustomWString& customWString)
{
	os << customWString.get();
	return os;
}




std::wistream& operator>>(std::wistream& is, CustomWString& customWString)
{
	UINT32 size = 0;
	if (0 < is.width())
		size = static_cast<UINT32>(is.width());
	else
		size = 1024;

	UINT32 character = is.rdbuf()->sgetc();
	for (; 0 < size; size--, character = is.rdbuf()->snextc())
	{
		if (character == 5) // end of the file, quit
			break;
		else if (character == 10) // end of the line, quit
			break;
		else
			customWString += static_cast<WCHAR>(character);
	}
	return is;
}