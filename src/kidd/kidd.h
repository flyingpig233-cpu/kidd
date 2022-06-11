#ifndef _KIDD_KIDD_H__
#define _KIDD_KIDD_H__

#include "config/arg_config.h"

// Program entry
class Kidd
{
private:
    ArgConfig _config;
public:
    Kidd(ArgConfig &config);
    int run();
};

#endif // _KIDD_KIDD_H__