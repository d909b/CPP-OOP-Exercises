//
//  main.cpp
//  OOPUE7
//
//  Created by patrick on 12/20/12.
//  Copyright (c) 2012 Patrick Schwab. All rights reserved.
//

#include <iostream>

/** 
 * We instantiate a template class
 * that inherits from our template argument and adds a virtual function,
 * this should add the virtual table pointer to the class layout,
 * if it does not exist yet. (-> thus increasing its size)
 * If it does already exist (ie. if the class already has virtual functions)
 * the class' size should remain the same.
 * (Work on CLANG, no idea if this is actually guaranteed by the cpp standard)
 */
template <class T>
class inherit_with_virtual_function : public T
{
    virtual void Do()
    {
        ;
    }
};

template <typename T>
class HasVirtualFunctions
{
public:
    /**
     * We compare the template argument class' size with a class that inherits from the template argument 
     * and adds a virtual function. If they are of the same size then a virtual table pointer is already present.
     * This expression is a compile time constant thus can be used to initialize a static const member.
     */
    static const bool RESULT = sizeof(T) == sizeof(inherit_with_virtual_function<T>);
};

/** Begin test classes. */
class EmptyClass
{
};

class NoVirtualFunctions
{
};

class VirtualFunctions
{
    virtual void empty()
    {
        ;
    }
};

class VirtualFunctions2
{
    virtual void empty2()
    {
        ;
    }
};

class SingleInheritanceVirtualFunctions : public VirtualFunctions
{
};

class MultipleInheritanceVirtualFunctions : public NoVirtualFunctions, public VirtualFunctions
{
};

class MultipleInheritance2VirtualFunctions : public VirtualFunctions2, public VirtualFunctions
{
};


class MultipleInheritanceNoVirtualFunctions : public NoVirtualFunctions, public EmptyClass
{
};

/** End test classes. */

std::string boolToString(bool value)
{
    return value ? "true" : "false";
}

int main(int argc, const char** argv)
{
    bool test1 = HasVirtualFunctions<NoVirtualFunctions>::RESULT;
    std::cout << "[Test 1]: " << boolToString(test1) << std::endl;
    
    bool test2 = HasVirtualFunctions<VirtualFunctions>::RESULT;
    std::cout << "[Test 2]: " << boolToString(test2) << std::endl;
    
    bool test3 = HasVirtualFunctions<SingleInheritanceVirtualFunctions>::RESULT;
    std::cout << "[Test 3]: " << boolToString(test3) << std::endl;
    
    bool test4 = HasVirtualFunctions<MultipleInheritanceVirtualFunctions>::RESULT;
    std::cout << "[Test 4]: " << boolToString(test4) << std::endl;
    
    bool test5 = HasVirtualFunctions<MultipleInheritanceNoVirtualFunctions>::RESULT;
    std::cout << "[Test 5]: " << boolToString(test5) << std::endl;
    
    bool test6 = HasVirtualFunctions<MultipleInheritance2VirtualFunctions>::RESULT;
    std::cout << "[Test 6]: " << boolToString(test6) << std::endl;
    
    return 0;
}

