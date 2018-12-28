// HW4 - Templated Stack
// TJ Wolschon
#include "pch.h"
#include "IntAndString.h"


IntAndString::IntAndString()
{
    number = 0;
    str = "NULL";
}

IntAndString::IntAndString(int _number, string _str)
{
    number = _number;
    str = _str;
}

IntAndString::~IntAndString()
{
}

ostream & operator<<(ostream & ostr, IntAndString const & rhs)
{
    ostr << "[" << rhs.number << ", \"" << rhs.str << "\"]";
    return ostr;
}
