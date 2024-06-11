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

    bool ResetBalance();
protected:
    bool SetSizeFieldRows(const int& setSize);
    bool SetSizeFieldColumns(const int& setSize);
    bool SetUserBallance(const double& money);



    bool SetFuelLevel(const double& resizeTo, const string& id_nam);
    bool SetAuditSpend(const double& money);
    bool SetAuditAll(const double& money);

    bool UpdateDurability( double resizeTo, const string& id_nam);
    bool UpdateFuelLevel(double resizeTo, const string& id_nam);

    bool UpdateField(const int& newSize, const bool& coRo);

    bool UpdateUserBallance(double money);
    bool UpdateAuditSpend(double money);
    bool UpdateAuditAll(double money);

public:    

    SerializationDe() {data = Load();}

    const map<string, double> GetCharacteristics(const string& nam_Id);
    const double GetUserBallance();
    const int GetFieldRows();
    const int GetFieldColumns();
    const double GetAuditSpend();
    const double GetAuditAll();





    bool AddCombine(const std::string& id_nam);
    bool SellCombine(const std::string& id_nam);
};
