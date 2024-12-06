#ifndef COUNTRYDATABASE_HPP
#define COUNTRYDATABASE_HPP

#include <string>
#include <map>

class CountryDatabase
{
public:
    static std::map<std::string, std::string> getCountryData();
};

#endif // COUNTRYDATABASE_HPP