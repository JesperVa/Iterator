#pragma once
#include "String.h"
#include <iterator>
#include <iostream>

class SIterator : public std::iterator<std::forward_iterator_tag, char>
{
protected:
	char* m_container;
	const char* m_startPtr;
	
	friend class reverse_SIterator;

public:
	SIterator() : m_container(nullptr), m_startPtr(nullptr) {}
	SIterator(char* container) : m_container(container), m_startPtr(container) {}
	SIterator(SIterator& iterator)
	{
		m_startPtr = m_container = iterator.m_container;
	}
	virtual ~SIterator() = default;

	SIterator operator=(char c)
	{
		m_container = (char*)std::malloc(sizeof(c));
		*m_container = c;
	}

	char& operator*() { return (*m_container); }
	virtual SIterator& operator++()
	{
		m_container++;
		return *this;
	}
	virtual SIterator& operator--() { --m_container; return *this; }
	virtual SIterator operator++(int rhs)
	{ 
		SIterator temp = SIterator(m_container);
		m_container++;
		return temp;
	}
	virtual SIterator operator+(size_t rhs)
	{
		return SIterator(m_container+rhs); 
	}
	int operator-(SIterator* rhs)
	{
		return this - rhs;
	}
	
	virtual char operator[](int index) { return m_container[index]; }

	bool operator==(const SIterator& rhs) const { return m_container == rhs.m_container; }
	bool operator==(const char& rhs) const { return (*m_container) == rhs; }
	bool operator !=(const SIterator& rhs) const { return m_container != rhs.m_container; }
	bool operator<(const SIterator& rhs) const { return m_container < rhs.m_container; }

	friend std::ostream& operator<<(std::ostream & cout, SIterator it)
	{
		return cout << *it.m_container;
	}

	friend int operator-(SIterator lhs, SIterator rhs)
	{
		return lhs - rhs;
	}
};

class reverse_SIterator : public SIterator
{
public: 
	reverse_SIterator() = default;
	reverse_SIterator(char* container) : SIterator(container) {}
	reverse_SIterator(reverse_SIterator& iterator)
	{
		m_container = iterator.m_container;
	}
	reverse_SIterator(SIterator& iterator)
	{
		m_container = iterator.m_container;
	}


	SIterator& operator++()
	{
		m_container--;
		return *this;
	}
	SIterator& operator--() { ++m_container; return *this; }
	SIterator operator++(int rhs)
	{
		SIterator temp = SIterator(m_container);
		m_container--;
		return temp;
	}
	SIterator operator+(size_t rhs)
	{
		return SIterator(m_container - rhs);
	}

	virtual char operator[](int index) { return *(m_container-index); }
};
