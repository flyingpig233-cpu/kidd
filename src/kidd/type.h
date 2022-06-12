#ifndef _KIDD_TYPE_H__
#define _KIDD_TYPE_H__

#include <string>
#include <string_view>
#include <spdlog/sinks/basic_file_sink.h>



namespace type
{

using pos_type = unsigned int;

using os_char_type = char;
using os_string = std::basic_string<os_char_type>;
using os_string_view = std::basic_string_view<os_char_type>;
#define __(s) s

#ifdef UNICODE
using char_type = wchar_t;
typedef wchar_t char_type;
using string = std::basic_string<char_type>;
using string_view = std::basic_string_view<char_type>;
#define _(s) L##s
#else
using char_type = char;
using string = std::basic_string<char_type>;
using string_view = std::basic_string_view<char_type>;
#define _(s) s
#endif // UNICODE

};


struct Position
{
    type::pos_type x;
    type::pos_type y;
};

#endif //_KIDD_TYPE_H__