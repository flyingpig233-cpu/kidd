#include <argparse/argparse.hpp>
#include "kidd.h"
#include "utils/logger.h"
#include "config/global_info.h"
#include "config/arg_config.h"
#include <spdlog/spdlog.h>

int main(int argc, type::os_char_type **argv)
{
    //init logger
    auto logger = spdlog::basic_logger_mt(info::LOGGER_NAME, "logs/log.txt");
    spdlog::set_default_logger(logger);
    spdlog::flush_on(spdlog::level::info);

    // parse args
    argparse::ArgumentParser program(info::PROGRAM_NAME);
    program.add_description(info::PROGRAM_DISCRIPTION);
    program.add_argument("f", "filename")
        .help("target file to open")
        .default_value(std::vector<std::string>({""}))
        .remaining();

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }


    const auto filenames =  program.get<std::vector<std::string>>("f");
    std::string list;

    list.append("[");
    for (auto &&e : filenames)
    {
        list.append("\"" + e + "\"");
        list.push_back(',');
    }
    list.pop_back();
    list.append("]");
    
    log_info("file list: {}", list);
    ArgConfig config;
    config.filenames = std::move(filenames);
    Kidd kidd(config);
    return kidd.run();
}
