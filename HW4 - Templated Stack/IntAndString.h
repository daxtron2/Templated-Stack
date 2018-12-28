// HW4 - Templated Stack
// TJ Wolschon
#pragma once
#include <string>

using namespace std;

class IntAndString
{
private:
    int number;
    string str;

public:
    IntAndString();
    IntAndString(int _number, string _str);
    ~IntAndString();

    friend ostream& operator<<(ostream& ostr, IntAndString const& rhs);
};

