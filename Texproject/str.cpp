#include <iostream>
#include <vector>
#include <algorithm>
#include "str.h"
#include <cstring>

MyString::MyString() : data(nullptr), size(0) {
	std::cout << "Default constructor called\n";
}

size_t MyString::get_len(char* source)
{
	size_t len = 0;
	while (source[len] != '\0')
		len++;
	return len;
}

size_t MyString::get_len(const char* source)
{
	size_t len = 0;
	while (source && source[len] != '\0') {
		len++;
	}
	return len;
}

MyString::MyString(char* source)
{
	if (!source) {
		data = nullptr;
		size = 0;
		return;
	}
	size = get_len(source);
	data = new char[size + 1];
	memcpy(data, source, size);
	data[size] = '\0';
}
MyString::MyString(const char* source)
{
	if (source) {
		size = get_len(source);
		data = new char[size + 1];
		std::memcpy(data, source, size);
		data[size] = '\0';  // Завершающий нуль-символ
	}
	else {
		data = nullptr;
		size = 0;
	}
}


MyString::MyString(std::vector<char> source)
{
	size = source.size();
	data = new char[size + 1];
	memcpy(data, source.data(), size);
}
MyString::~MyString()
{
	if (data) {
	delete[] data;
	data = nullptr;
	}
	size = 0;
}

MyString& MyString::operator=(const MyString& source)
{
	if (this != &source) {
		delete[] data;
		size = source.size;
		data = new char[size + 1];
		memcpy(data, source.data, size);
		data[size] = '\0';
	}
	return *this;
}
MyString& MyString::operator=(char* source)
{
	delete[] data;
	size = get_len(source);
	data = new char[size + 1];
	memcpy(data, source, size);
	return *this;
}
MyString& MyString::operator=(const char* source)
{

	if (data == source)
		return *this;
	delete[] data;
	size = get_len(source);
	data = new char[size + 1];
	memcpy(data, source, size);
	data[size] = '\0';
	return *this;
}

bool MyString::operator==(const MyString& source)
{
	if (size != source.size)
		return false;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source.data[pos])
			return false;
		pos++;
	}
	return true;
}
bool MyString::operator==(char* source)
{
	if (size != get_len(source))
		return false;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source[pos])
			return false;
		pos++;
	}
	return true;
}
bool MyString::operator==(const char* source)
{
	if (size != get_len(source))
		return false;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source[pos])
			return false;
		pos++;
	}
	return true;
}
bool MyString::operator!=(const MyString& source)
{
	if (size != source.size)
		return true;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source.data[pos])
			return true;
		pos++;
	}
	return false;
}
bool MyString::operator!=(char* source)
{
	if (size != get_len(source))
		return true;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source[pos])
			return true;
		pos++;
	}
	return false;
}
bool MyString::operator!=(const char* source)
{
	if (size != get_len(source))
		return true;
	size_t pos = 0;
	while (pos < size)
	{
		if (data[pos] != source[pos])
			return true;
		pos++;
	}
	return false;
}
MyString& MyString::operator+=(const MyString& source)
{
	char* new_data = new char[size + source.size + 1];
	memcpy(new_data, data, size);
	memcpy(new_data + size, source.data, source.size);
	new_data[size + source.size] = '\0';
	size += source.size;
	delete[] data;
	data = new_data;
	return *this;
}
MyString& MyString::operator+=(char* source)
{
	const size_t source_len = get_len(source);
	char* new_data = new char[size + source_len + 1];
	memcpy(new_data, data, size);
	memcpy(new_data + size, source, source_len);
	size += source_len;
	delete[] data;
	data = new_data;
	return *this;
}
MyString& MyString::operator+=(const char* source)
{
	size_t source_len = get_len(source);
	char* new_data = new char[size + source_len + 1];
	memcpy(new_data, data, size);
	memcpy(new_data + size, source, source_len);
	new_data[size + source_len] = '\0';
	delete[] data;	
	data = new_data;
	size += source_len;
	return *this;
}

MyString& MyString::lower()
{
	MyString* result =new MyString(this->data);
	for (size_t i = 0; i < size; i++)
	{
		auto it = lower_list.find(result->data[i]);
		if (it != lower_list.end())
			result->data[i] = it->second;
	}
	return *result;
}
MyString& MyString::upper()
{
	MyString* result = new MyString(this->data);
	for (size_t i = 0; i < size; i++)
	{
		auto it = upper_list.find(result->data[i]);
		if (it != upper_list.end())
			result->data[i] = it->second;
	}
	return *result;
}
MyString& MyString::to_lower()
{
	for (size_t i = 0; i < size; i++)
	{
		auto it = lower_list.find(data[i]);
		if (it != lower_list.end())
			data[i] = it->second;
	}
	return *this;
}
MyString& MyString::to_upper()
{
	;
	for (size_t i = 0; i < size; i++)
	{
		auto it = upper_list.find(data[i]);
		if (it != upper_list.end())
			data[i] = it->second;
	}
	return *this;
}
const char* MyString::c_str()
{
	return data ? data : "";
}
size_t MyString::length() const {
	return size;
}

std::unordered_map<char, char> MyString::lower_list = {
	{'A', 'a'}, {'B', 'b'}, {'C', 'c'}, {'D', 'd'}, {'E', 'e'}, {'F', 'f'}, {'G', 'g'},
	{'H', 'h'}, {'I', 'i'}, {'J', 'j'}, {'K', 'k'}, {'L', 'l'}, {'M', 'm'}, {'N', 'n'},
	{'O', 'o'}, {'P', 'p'}, {'Q', 'q'}, {'R', 'r'}, {'S', 's'}, {'T', 't'}, {'U', 'u'},
	{'V', 'v'}, {'W', 'w'}, {'X', 'x'}, {'Y', 'y'}, {'Z', 'z'}
};
std::unordered_map<char, char> MyString::upper_list = {
	{'a', 'A'}, {'b', 'B'}, {'c', 'C'}, {'d', 'D'}, {'e', 'E'}, {'f', 'F'}, {'g', 'G'},
	{'h', 'H'}, {'i', 'I'}, {'j', 'J'}, {'k', 'K'}, {'l', 'L'}, {'m', 'M'}, {'n', 'N'},
	{'o', 'O'}, {'p', 'P'}, {'q', 'Q'}, {'r', 'R'}, {'s', 'S'}, {'t', 'T'}, {'u', 'U'},
	{'v', 'V'}, {'w', 'W'}, {'x', 'X'}, {'y', 'Y'}, {'z', 'Z'}
};