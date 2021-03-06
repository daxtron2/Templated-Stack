// HW4 - Templated Stack
// TJ Wolschon

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <crtdbg.h>
#include "IntAndString.h"
#include "MyStack.h"
#include <string>
#define _CRTDBG_MAP_ALLOC

using namespace std;
void wrapper()
{
    //test with ints
    cout << "Testing with int" << endl;
    MyStack<int> test = MyStack<int>();
    test.Push(10);
    test.Push(15);
    test.Print();
    test.Pop();
    test.Push(50);
    test.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;


    //test with strings
    cout << "Testing with string" << endl;
    MyStack<string> str = MyStack<string>();
    str.Push("First");
    str.Push("Second");
    str.Push("Third");
    str.Print();
    str.Pop();
    str.Push("Fourth");
    str.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;


    //test copy constructor
    cout << "About to test copy constructor by copying string stack" << endl;
    MyStack<string> str2 = MyStack<string>(str);
    str2.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;


    //test with float
    cout << "Testing with float" << endl;
    MyStack<float> flt = MyStack<float>();
    flt.Push(3.2f);
    flt.Push(4.1f);
    flt.Print();
    flt.Pop();
    flt.Push(32.122134f);
    flt.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;


    //test copy assignment operator with float
    cout << "About to test copy assignment operator by copying float stack" << endl;
    MyStack<float> flt2 = MyStack<float>();
    flt2 = flt;
    flt2.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;

    //test array index operator overload
    cout << "About to test array index operator by indexing from str2" << endl;
    cout << "str2 contains " << str2[-1] << " at index 2" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl << endl;

    //test with custom type
    cout << "About to test with custom IntAndString type" << endl;
    MyStack<IntAndString> ias = MyStack<IntAndString>();
    ias.Push(IntAndString(10, "Ten"));
    ias.Push(IntAndString(20, "Twenty"));
    ias.Print();
    ias.Pop();
    ias.Push(IntAndString(12, "Twelve"));
    ias.Print();
    cout << "-----------------------------------------------------------------------------------" << endl << endl;
    

}

int main()
{
    wrapper();
    _CrtDumpMemoryLeaks();
    return 0;
}