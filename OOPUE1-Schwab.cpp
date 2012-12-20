//
//  OOPUE1-Schwab.cpp
//  String
//
//  Created by Patrick Schwab on 10/9/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <cstdlib>
#include <cstdio>

class String
{
public:
    String(const char* cstr)
    {
        int len = LengthOf(cstr);
        data_ = new char[len + 1];
        
        CopyStr(data_, cstr, len + 1);
    }
    
    ~String()
    {
        delete[] data_;
    }
    
    void Concatenate(const String& other)
    {
        const int len      = Length();
        const int otherLen = other.Length();
        
        char* tmp = new char[len + otherLen + 1];
        
        CopyStr(tmp, data_, len);
        CopyStr(tmp + len, other.c_str(), otherLen + 1);
        
        delete[] data_;
        data_ = tmp;
    }
    
    int Length() const
    {
        return LengthOf(data_);
    }
    
    const char* c_str() const
    {
        return data_;
    }
private:
    int LengthOf(const char* cstr) const
    {
        int len = 0;
        
        for(; cstr[len] != '\0'; ++len);
        
        return len;
    }
    
    void CopyStr(char* str1, const char* str2, int len) const
    {
        for(int i = 0; i < len; ++i)
        {
            str1[i] = str2[i];
        }
    }
    
    char* data_;
};

int main(int argc, const char * argv[])
{
    String myString("Hello");
    myString.Concatenate(" World. ");
    myString.Concatenate(myString);
    printf("%s\n", myString.c_str());
    
    return EXIT_SUCCESS;
}
