//
//  main.cpp
//  OOPUE3
//
//  Created by patrick on 10/31/12.
//  Copyright (c) 2012 patrick schwab. All rights reserved.
//

#include <cstring>
#include <cstdlib>
#include <iostream>

class String
{
public:
	explicit String(const char* const str)
    : m_length(strlen(str))
    , m_string(new char [m_length+1])
	{
		// copies null-terminator as well
		memcpy(m_string, str, m_length+1);
	}
    
	String(const String& other)
    : m_length(other.m_length)
    , m_string(new char[m_length+1])
	{
		memcpy(m_string, other.m_string, m_length+1);
	}
    
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] m_string;
            
			m_length = other.m_length;
			m_string = new char[m_length+1];
			memcpy(m_string, other.m_string, m_length+1);
		}
        
		return *this;
	}
    
	inline ~String(void)
	{
		delete[] m_string;
	}
    
	void Concatenate(const char* str)
	{
		const size_t len = strlen(str);
		char* newString = new char [m_length+len+1];
		memcpy(newString, m_string, m_length);
		memcpy(newString+m_length, str, len+1);
		delete[] m_string;
		m_string = newString;
		m_length += len;
	}
    
	inline void Concatenate(const String& str)
	{
		Concatenate(str.c_str());
	}
    
	inline const char* c_str(void) const
	{
		return m_string;
	}
    
	inline size_t Length(void) const
	{
		return m_length;
	}
    
    inline operator const char*() const
    {
        return m_string;
    }
    
    String& operator+=(const String& other)
    {
        Concatenate(other);
        return *this;
    }
    
    inline String operator+(const String& other) const
    {
        return String(*this) += other;
    }
    
    String& operator+=(const char* other)
    {
        Concatenate(other);
        return *this;
    }
    
    inline String operator+(const char* other) const
    {
        return String(*this) += other;
    }
    
private:
	size_t m_length;
	char* m_string;
};

int main(int argc, const char * argv[])
{
    String s1("Hello");
    const String s2("World");
    
    s1 += s2;
    String s3 = s1 + s2;
    s3 += "Hello";
    
    const String s4 = s3 + "World";

    std::cout << s4 << std::endl;
    return EXIT_SUCCESS;
}
