//
//  main.cpp
//  OOPUE4
//
//  Created by patrick on 12/4/12.
//  Copyright (c) 2012 patrick schwab. All rights reserved.
//

#include <algorithm>
#include <vector>

template <typename T>
void Reverse(T* array, int length)
{
    std::vector<T> copy(array, array+length);
    std::copy(copy.rbegin(), copy.rend(), array);
}


int main(int argc, const char * argv[])
{
    int intArray[4]={1,2,3,4};
    bool boolArray[5] = { false, true, false, true, true };
    char* strArray[3] = { "Hello", "World", "Test" };
    
    Reverse(intArray, 4);
    Reverse(boolArray, 5);
    Reverse(strArray, 3);
    
    return 0;
}

/**
 * Questions:
 * Could the same have been achieved without using templates?
 * -- Yes.
 *
 * § How could it be done?
 * -- Using void* instead.
 *
 * § Pros/cons of such an approach?
 * -- Pros: (1) Smaller executable size (one code fits all)
 *          (2) Function can be split in declaration / definition.
 * -- Cons: (1) Not a type-safe solution.
 *          (2) (Arguably) Worse API, because instead of length the size in bytes would have to be passed.
 */