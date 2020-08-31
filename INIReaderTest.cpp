// Example that shows simple usage of the INIReader class

#include <iostream>
#include <sstream>
#include "INIReader.h"

std::string sections(INIReader &reader)
{
    std::stringstream ss;
    std::set<std::string> sections = reader.Sections();
    for (std::set<std::string>::iterator it = sections.begin(); it != sections.end(); ++it)
        ss << *it << ",";
    return ss.str();
}

int main()
{
    INIReader reader("test.ini");

    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
        return 1;
    }
    std::cout << "Config loaded from 'test.ini': found sections=" << sections(reader) << "\n"
              << "version=" << reader.GetInteger("protocol", "version", -1)  << "\n"
              << "name=" << reader.Get("user", "name", "UNKNOWN")  << "\n"
              << "email=" << reader.Get("user", "email", "UNKNOWN")  << "\n"
              << "multi=" << reader.Get("user", "multi", "UNKNOWN")  << "\n"
              << "pi=" << reader.GetReal("user", "pi", -1)  << "\n"
              << "active=" << reader.GetBoolean("user", "active", true) << "\n"
              << "main:global_value=" << reader.Get("main", "global_value", "UNKNOWN") << "\n"
              << "user:global_value=" << reader.Get("user", "global_value", "UNKNOWN") << "\n"
              << "user:overwriten_value=" << reader.Get("user", "overwriten_value", "UNKNOWN") << "\n"
              << "\n";
    return 0;
}
