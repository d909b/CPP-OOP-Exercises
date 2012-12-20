//
//  OOPUE2-Schwab.cpp
//  String
//
//  Created by Patrick Schwab on 10/20/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <cstdlib>
#include <cstring>
#include <iostream>

class String
{
public:
	explicit String(const char* const str) :
      m_length(strlen(str)),
      m_string(new char [m_length+1])
	{
		// copies null-terminator as well
		memcpy(m_string, str, m_length+1);
	}
    
    String(const String& other) :
      m_length(other.m_length),
      m_string(new char[m_length + 1])
    {
        // copies null-terminator as well
		memcpy(m_string, other.m_string, m_length + 1);
    }
    
	inline ~String(void)
	{
		delete[] m_string;
	}
    
    String& operator=(const String& other)
    {
        // check for self assignment
        if(this != &other)
        {
            m_length = other.m_length;
            delete[] m_string;
            m_string = new char[m_length + 1];
            
            // copies null-terminator as well
            memcpy(m_string, other.m_string, m_length + 1);
        }
        
        return *this;
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
    
private:
	size_t m_length;
	char* m_string;
};

int main(int argc, const char * argv[])
{
    String myString("Hello");
    myString.Concatenate("World");
    myString.Concatenate(myString);
    String otherString(myString);
    String yetAnotherString("AnotherWorld");
    otherString = yetAnotherString;
    
    std::cout << otherString.c_str() << std::endl;
    
    return EXIT_SUCCESS;
}
