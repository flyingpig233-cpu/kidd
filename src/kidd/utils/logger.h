#ifndef _KIDD_LOGGER_H__
#define _KIDD_LOGGER_H__

#include <spdlog/spdlog.h>
#include "config/global_info.h"


template<typename... Args_t>
static inline void log_info(std::string info, Args_t &&...args)
{
    spdlog::get(info::LOGGER_NAME)->info(info, args...);
}

#endif // _KIDD_LOGGER_H__