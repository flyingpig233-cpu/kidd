#ifndef _KIDD_ARG_CONFIG_H__
#define _KIDD_ARG_CONFIG_H__

#include <vector>
#include "type.h"


struct ArgConfig {
    std::vector<type::os_string> filenames;    
};

#endif // _KIDD_ARG_CONFIG_H__