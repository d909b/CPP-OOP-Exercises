//
//  main.cpp
//  OOPUE5
//
//  Created by patrick on 12/12/12.
//  Copyright (c) 2012 patrick schwab. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <algorithm>

template <typename T>
class Array
{
    T* m_data;
    size_t m_size;
public:
    explicit Array(size_t size) :
        m_data(new T[size]),
        m_size(size)
    {
        ;
    }
    
    Array(const Array& other) :
        m_data(new T[other.m_size]),
        m_size(other.m_size)
    {
        std::copy(other.m_data, other.m_data + other.m_size, m_data);
    }
    
    Array& operator=(const Array& other)
    {
        if(this != &other)
        {
            delete[] m_data;
            m_data = new T[other.m_size];
            m_size = other.m_size;
            
            std::copy(other.m_data, other.m_data + other.m_size, m_data);
        }
        
        return *this;
    }
    
    ~Array()
    {
        delete[] m_data;
    }
    
    T& operator[](size_t idx) const
    {
        assert(idx >= 0 && idx < m_size);
        
        return m_data[idx];
    }
    
    inline size_t size() const
    {
        return m_size;
    }
};

template <typename T>
void Print(T elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
void PrintArray(const Array<T>& a)
{
    for(size_t i = 0; i < a.size(); ++i)
    {
        std::cout << "Array[" << i << "] = ";
        Print(a[i]);
    }
}

int main(int argc, const char * argv[])
{
    Array<float> fiveFloats(5);
    fiveFloats[0] = 10;
    
    PrintArray(fiveFloats);
    
    Array<int> threeInts(3);
    threeInts[2] = 1;
    
    PrintArray(threeInts);
    
    return 0;
}

