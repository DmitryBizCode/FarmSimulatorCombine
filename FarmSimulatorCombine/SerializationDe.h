#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include "JsonAccess.h"

using namespace std;
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class SerializationDe {
private:
    JsonAccess jsonAccess;
    bool ResetBalance();
    //friend to reset ballance
protected:
    bool SetSizeFieldRows(const int& setSize);
    bool SetSizeFieldColumns(const int& setSize);
    bool SetUserBallance(const double& money);

    bool SetAuditSpend(const double& money);
    bool SetAuditAll(const double& money);
    bool SetUserYears(const unsigned int& years);

    bool UpdateDurability( double resizeTo, const string& id_nam);

    bool UpdateField(const int& newSize, const bool& coRo);

    bool UpdateUserYears();
    bool UpdateUserBallance(double money);
    bool UpdateAuditSpend(double money);
    bool UpdateAuditAll(double money);
    const map<string, double> GetCharacteristicsM(const string& nam_Id);

public:    
    bool AddCombine(const string& id_nam);
    bool SellCombine(const string& id_nam);

    SerializationDe() { jsonAccess.data = jsonAccess.Load();}
    bool SetFuelLevel(const double& resizeTo, const string& id_nam);
    bool UpdateFuelLevel(const double& resizeTo, const string& id_nam);

    const map<string, double> GetCharacteristics(const string& nam_Id);
    const vector<string> GetCharacteristicsArrayName();

    const tuple<vector<string>, vector<map<string, double>>> GetCharacteristicsMarket();
    const double GetUserBallance();
    const int GetFieldRows();   
    const int GetFieldColumns();
    const double GetAuditSpend();
    const double GetAuditAll();
    const unsigned int GetYears();
};
