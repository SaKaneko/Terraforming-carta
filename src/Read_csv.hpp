#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <string>
#include <set>
#include <map>
namespace fs = std::filesystem;

namespace csv
{

    std::vector<std::string> split(std::string &input, char delimiter)
    {
        std::istringstream stream(input);
        std::string field;
        std::vector<std::string> result;
        while (std::getline(stream, field, delimiter))
        {
            result.push_back(field);
        }
        return result;
    }

    std::vector<std::vector<std::string>> Read_csv(fs::path &p)
    {
        std::ifstream ifs;
        ifs.open(p);
        std::string line;
        std::getline(ifs, line);
        std::vector<std::vector<std::string>> ret;
        while (std::getline(ifs, line))
        {
            auto strvec = split(line, ',');
            ret.push_back(strvec);
        }
        ifs.close();
        return ret;
    }

}