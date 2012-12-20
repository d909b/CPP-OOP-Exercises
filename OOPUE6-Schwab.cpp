//
//  main.cpp
//  OOPUE6
//
//  Created by patrick on 12/20/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <iostream>

/** By default a template parameter is not a pointer. */
template <typename T>
class IsPointer
{
public:
    static const bool RESULT = false;
};

/** 
 * Provide a partial template specialization for pointer types.
 * The compiler will instantiate this template,
 * if the template argument T is a pointer type. 
 */
template <typename T>
class IsPointer<T*>
{
public:
    static const bool RESULT = true;
};

int main(int argc, const char** argv)
{
    bool test  = IsPointer<int>::RESULT; // false
    bool test2 = IsPointer<int*>::RESULT; // true
    bool test3 = IsPointer<const void*>::RESULT; // true
    
    return 0;
}

