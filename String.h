#pragma once
#include <iostream>
#include <vector>
#include "SIterator.hpp"

class String
{
private:
	char* string;
	size_t string_size, string_capacity;

	friend class SIterator;

public:

	typedef SIterator iterator;
	typedef reverse_SIterator reverse_iterator;

	String() : string_size(0), string_capacity(1) 
	{
		string = new char[string_capacity];
		string[0] = '\0';
	}

	String(const String&);
	String(const char*);
	String& operator=(const String&);
	explicit operator bool();

	char& at(size_t);
	char& operator[](size_t);
	const char& operator[](size_t) const;


	const char* data() const;
	int size() const;
	void reserve(size_t);
	int capacity() const;
	void shrink_to_fit();
	void push_back(char);
	void resize(size_t);
	String& operator+=(const String&);
	String& operator+(const String&);

	SIterator begin() { return SIterator(string); }
	SIterator end() { return SIterator(string + string_size); }

	reverse_iterator rbegin() { return reverse_SIterator(string + string_size - 1); }
	reverse_iterator rend() { return reverse_SIterator(string); }

	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);

	friend std::ostream& operator<<(std::ostream& cout, String& rhs)
	{
		for (size_t i = 0; i < rhs.string_size ; ++i)
		{
			cout << rhs.string[i];
		}
		return cout;

	}


	~String();

};

