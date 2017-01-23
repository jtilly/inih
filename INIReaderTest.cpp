// Example that shows simple usage of the INIReader class

#include <iostream>
#include <sstream>
#include "INIReader.h"

int main()
{
    INIReader reader("test.ini");

    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
        return 1;
    }
    std::cout << "Config loaded from 'test.ini': found sections=" << [&reader]() {
                    std::stringstream ss;
                    auto sections = reader.Sections();
                    for (auto it = sections.cbegin(); it != sections.cend(); ++it)
                        ss << *it << ",";
                    return ss.str();
              }() << " version="
              << reader.GetInteger("protocol", "version", -1) << ", name="
              << reader.Get("user", "name", "UNKNOWN") << ", email="
              << reader.Get("user", "email", "UNKNOWN") << ", multi="
              << reader.Get("user", "multi", "UNKNOWN") << ", pi="
              << reader.GetReal("user", "pi", -1) << ", active="
              << reader.GetBoolean("user", "active", true) << "\n";
    return 0;
}
