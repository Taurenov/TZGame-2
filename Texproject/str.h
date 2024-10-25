#pragma once

#include <ostream>
#include <unordered_map>
#include <vector>

class MyString
{
	char* data = nullptr;
	size_t size = 0;
	size_t get_len(char* source);
	size_t get_len(const char* source);
	static std::unordered_map<char, char> lower_list;
	static std::unordered_map<char, char> upper_list;
public:
	MyString();
	MyString(char* source);
	MyString(const char* source);
	MyString(std::vector<char> source);
	~MyString();

	MyString& operator= (const MyString& source);
	MyString& operator= (char* source);
	MyString& operator= (const char* source);

	bool operator== (const MyString& source);
	bool operator== (char* source);
	bool operator== (const char* source);
	bool operator!= (const MyString& source);
	bool operator!= (char* source);
	bool operator!= (const char* source);
	MyString& operator+= (const MyString& source);
	MyString& operator+= (char* source);
	MyString& operator+= (const char* source);

	MyString lower();
	MyString upper();
	MyString& to_lower();
	MyString& to_upper();
	const char* c_str();
	size_t length() const;

	friend MyString operator+ (const MyString& left, const MyString& right)
	{
		MyString result(left);
		result += right;
		return result;
	}
	friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
		if (str.data) {
			os << str.data;
		}
		return os;
	}

};
