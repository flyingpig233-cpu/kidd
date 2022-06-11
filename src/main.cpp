#include <argparse/argparse.hpp>
#include "kidd.h"
#include "type.h"
#include "config/global_info.h"
#include "config/arg_config.h"

int main(int argc, type::os_char_type **argv)
{
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
    ArgConfig config;
    config.filenames = std::move(filenames);
    Kidd kidd(config);
    return kidd.run();
}
