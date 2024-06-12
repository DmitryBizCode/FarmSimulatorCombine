#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

using namespace std;
#include "nlohmann/json.hpp"

using json = nlohmann::json;
class JsonAccess
{
private:
    json data;
    string filename = "database.json";
public:
    json Load();
    bool Save();
    friend class SerializationDe;
};

