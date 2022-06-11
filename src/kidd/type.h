#ifndef _KIDD_TYPE_H__
#define _KIDD_TYPE_H__

#include <string>


namespace type
{

using pos_type = unsigned int;

using os_char_type = char;
using os_string = std::basic_string<os_char_type>;
#define __(s) s

#ifdef UNICODE
using char_type = wchar_t;
using string = std::basic_string<char_type>;
#define _(s) L##s
#else
using char_type = char;
using string = std::basic_string<char_type>;
#define _(s) s
#endif // UNICODE

};


struct Position
{
    type::pos_type x;
    type::pos_type y;
};

#endif //_KIDD_TYPE_H__