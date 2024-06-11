#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

using namespace std;
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class SerializationDe {
private:
    json data;
    string filename = "database.json";

    json Load();
    bool Save();

protected:
    bool SetSizeFieldRows(const int& setSize);
    bool SetSizeFieldColumns(const int& setSize);
    bool SetUserBallance(const double& money);
    bool AddCombine(const std::string& id, const json& combineData);
    bool SetFuelLevel(const double& resizeTo, const string& id_nam);

public:    

    SerializationDe() {data = Load();}

    bool UpdateFuelLevel(const double& resizeTo, const string& id_nam);
    bool UpdateUserBallance(const double& money);
    bool UpdateField(const int& newSize, const bool& coRo);

    const map<string, double> GetCharacteristics(const string& nam_Id);
    const double GetUserBallance();
    const int GetFieldRows();
    const int GetFieldColumns();

};
