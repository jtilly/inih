// Example that shows simple usage of the INIReader class

#include <iostream>
#include <sstream>
#include "INIReader.h"

std::string sections(const INIReader &reader)
{
    std::stringstream ss;
    std::set<std::string> sections = reader.sections();
    for (std::set<std::string>::iterator it = sections.begin(); it != sections.end(); ++it)
        ss << *it << ",";
    return ss.str();
}

template <typename T>
std::string vector_to_str(const std::vector<T> vec) {
    std::stringstream ss;
    ss << "[";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin())
            ss << ", ";
        ss << *it;
    }
    ss << "]";
    return ss.str();
}

int main()
{
    INIReader reader("test.ini");

    if (reader.error() < 0) {
        std::cout << "Can't load 'test.ini'\n";
        return 1;
    }
    std::cout << "Config loaded from 'test.ini': found sections=" << sections(reader) << "\n"
              << "version=" << reader.get<int>("protocol", "version", -1)  << "\n"
              << "name=" << reader.get<std::string>("user", "name", "UNKNOWN")  << "\n"
              << "email=" << reader.get<std::string>("user", "email", "UNKNOWN")  << "\n"
              << "multi=" << reader.get<std::string>("user", "multi", "UNKNOWN")  << "\n"
              << "pi=" << reader.get<double>("user", "pi", -1)  << "\n"
              << "active=" << reader.get<bool>("user", "active", true) << "\n"
              << "array=" << vector_to_str(reader.get_array<int>("user", "array")) << "\n"
              << "main:global_value=" << reader.get<std::string>("main", "global_value", "UNKNOWN") << "\n"
              << "user:global_value=" << reader.get<std::string>("user", "global_value", "UNKNOWN") << "\n"
              << "user:overwriten_value=" << reader.get<std::string>("user", "overwriten_value", "UNKNOWN") << "\n"
              << "\n";
    return 0;
}
