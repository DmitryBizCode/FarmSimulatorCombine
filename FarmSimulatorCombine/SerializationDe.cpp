#include "SerializationDe.h"
#define S SerializationDe

bool S::ResetBalance() {
    try
    {
        jsonAccess.Load();
        jsonAccess.data["Audit"]["All"] = 0;
        jsonAccess.data["Audit"]["Spend"] = 0;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error reset balance: " << e.what() << endl;
        return false;
    }
}

bool S::AddCombine(const std::string& id_nam) {
    jsonAccess.Load();
    try
    {
        for (const auto& ttl : jsonAccess.data["CombinesMall"])
            if (ttl["ID_Name"] == id_nam)
            {
                json new_combine = {
                    {"ID_Name", id_nam},
                    {"Characteristics", {
                        {"Durability", ttl["Characteristics"]["Durability"]},
                        {"DurabilityData", ttl["Characteristics"]["DurabilityData"]},
                        {"Fuel", ttl["Characteristics"]["Fuel"]},
                        {"FuelCapacity", ttl["Characteristics"]["FuelCapacity"]},
                        {"FuelConsumption", ttl["Characteristics"]["FuelConsumption"]},
                        { "Price", ttl["Characteristics"]["Price"] }
                    }}
                };
                jsonAccess.data["Combines"].push_back(new_combine);
                break;
            }        
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error add new combine: " << e.what() << endl;
        return false;
    }
}
bool S::SellCombine(const std::string& id_nam) {
    jsonAccess.Load();
    try {
        for (auto it = jsonAccess.data["Combines"].begin(); it != jsonAccess.data["Combines"].end(); ++it) {
            if ((*it)["ID_Name"] == id_nam) {
                jsonAccess.data["Combines"].erase(it);
                jsonAccess.Save();
                jsonAccess.Load();
                return true;
            }
        }
        return false;
    }
    catch (const std::exception& e) {
        cerr << "Error removing combine: " << e.what() << endl;
        return false;
    }
}

bool S::UpdateUserBallance(double money) {
    try
    {
        money += jsonAccess.data["User"]["Balance"];
        jsonAccess.data["User"]["Balance"] = money;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update user ballance: " << e.what() << endl;
        return false;
    }
}
bool S::UpdateUserYears() {
    try
    {
        int ttl = jsonAccess.data["User"]["Years"] + 1;
        jsonAccess.data["User"]["Years"] = ttl;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update user ballance: " << e.what() << endl;
        return false;
    }
}

bool S::UpdateAuditAll(double money) {
    try
    { 
        if (money >= 0) {
            money += jsonAccess.data["Audit"]["All"];
            jsonAccess.data["Audit"]["All"] = money;
            jsonAccess.Save();
            jsonAccess.Load();
            return true;
        }
        return false;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update audit all: " << e.what() << endl;
        return false;
    }
}
bool S::UpdateAuditSpend(double money) {
    try
    {
        money += jsonAccess.data["Audit"]["Spend"];
        jsonAccess.data["Audit"]["Spend"] = money;
        jsonAccess.Save();        
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update audit spend: " << e.what() << endl;
        return false;
    }
}

bool S::UpdateField(const int& newSize, const bool& coRo) {
    try
    {
        if (coRo)
        {
            jsonAccess.data["Field"]["Columns"] = jsonAccess.data["Field"]["Columns"] + newSize;
            jsonAccess.Save();
            jsonAccess.Load();
            return true;
        }
        else
        {
            jsonAccess.data["Field"]["Rows"] = jsonAccess.data["Field"]["Rows"] + newSize;
            jsonAccess.Save();
            jsonAccess.Load();
            return true;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error update field: " << e.what() << endl;
        return false;
    }
}
bool S::UpdateFuelLevel(const double& resizeTo, const string& id_nam) {
    jsonAccess.Load();
    try {
        for (auto& combine : jsonAccess.data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                double ttl = resizeTo + combine["Characteristics"]["Fuel"].get<double>();
                combine["Characteristics"]["Fuel"] = ttl;
                jsonAccess.Save();
                jsonAccess.Load();
                return true;
            }
        }
        throw runtime_error("ID_Name not found: " + id_nam);
    }
    catch (const std::exception& e) {
        throw runtime_error("Error updating fuel value: " + string(e.what()));
    }
}

bool S::UpdateDurability(double resizeTo, const string& id_nam) {
    jsonAccess.Load();
    try {
        for (auto& combine : jsonAccess.data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                resizeTo += combine["Characteristics"]["Durability"].get<double>();
                combine["Characteristics"]["Durability"] = resizeTo;
                jsonAccess.Save();
                jsonAccess.Load();
                return true;
            }
        }
        throw runtime_error("ID_Name not found: " + id_nam);
    }
    catch (const std::exception& e) {
        throw runtime_error("Error updating durability value: " + string(e.what()));
    }
}


const double S::GetUserBallance() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["User"]["Balance"];
}
const int S::GetFieldRows() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["Field"]["Rows"];
}
const int S::GetFieldColumns() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["Field"]["Columns"];
}
const map<string, double> S::GetCharacteristics(const string& nam_Id) {
    jsonAccess.Load();
    try {
        for (const auto& ttl : jsonAccess.data["Combines"]) {
            if (ttl["ID_Name"] == nam_Id) {
                map<string, double> mapCharacter{
                    {"Price", ttl["Characteristics"]["Price"].get<double>()},
                    {"Durability", ttl["Characteristics"]["Durability"].get<double>()},
                    {"Fuel", ttl["Characteristics"]["Fuel"].get<double>()},
                    {"FuelCapacity", ttl["Characteristics"]["FuelCapacity"].get<double>()},
                    {"DurabilityData", ttl["Characteristics"]["DurabilityData"].get<double>()},
                    {"FuelConsumption", ttl["Characteristics"]["FuelConsumption"].get<double>()}
                };
                return mapCharacter;
            }
        }
        cerr << "Didnt find combine " << nam_Id <<" in your garage" << endl;
        return {};
    }
    catch (const std::exception& e) {
        cerr << "Error GetCharacteristics: " << e.what() << endl;
        return {};
        //throw runtime_error("Error get array from characteristics combine: " + string(e.what()));
    }
}
const tuple<vector<string>,vector<map<string, double>>> S::GetCharacteristicsMarket()
{
    jsonAccess.Load();
    try {
        vector<string> strVector;
        vector<map<string, double>> mapVector;
        for (const auto& ttl : jsonAccess.data["CombinesMall"]) {
            string str = ttl["ID_Name"];
            map<string, double> mapCharacter{
                {"Price", ttl["Characteristics"]["Price"].get<double>()},
                {"Durability", ttl["Characteristics"]["Durability"].get<double>()},
                {"Fuel", ttl["Characteristics"]["Fuel"].get<double>()},
                {"FuelCapacity", ttl["Characteristics"]["FuelCapacity"].get<double>()},
                {"DurabilityData", ttl["Characteristics"]["DurabilityData"].get<double>()},
                {"FuelConsumption", ttl["Characteristics"]["FuelConsumption"].get<double>()}
            };
            strVector.push_back(str);
            mapVector.push_back(mapCharacter);
        }
        return make_tuple(strVector, mapVector);
    }
    catch (const std::exception& e) {
        cerr << "Error GetCharacteristics market combine: " << e.what() << endl;
        return {};
        //throw runtime_error("Error get array from characteristics combine: " + string(e.what()));
    }
}
const double S::GetAuditSpend() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["Audit"]["Spend"];
}
const double S::GetAuditAll() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["Audit"]["All"];
}
const unsigned int S::GetYears() {
    jsonAccess.data = jsonAccess.Load();
    return jsonAccess.data["User"]["Years"];
}

bool S::SetSizeFieldRows(const int& setSize){
    try
    {
        jsonAccess.data["Field"]["Rows"] = setSize;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error set new value in field rows: " << e.what() << endl;
        return false;
    }
}
bool S::SetSizeFieldColumns(const int& setSize) {
    try
    {
        jsonAccess.data["Field"]["Columns"] = setSize;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error set new value in field columns: " << e.what() << endl;
        return false;
    }
}
bool S::SetUserBallance(const double& money) {
    try
    {
        jsonAccess.data["User"]["Balance"] = money;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error set new value to current ballance user: " << e.what() << endl;
        return false;
    }
}
bool S::SetFuelLevel(const double& resizeTo, const string& id_nam) {
    jsonAccess.Load();
    try {
        for (auto& combine : jsonAccess.data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                combine["Characteristics"]["Fuel"] = resizeTo;
                jsonAccess.Save();
                jsonAccess.Load();
                return true;
            }
        }
        throw runtime_error("ID_Name not found: " + id_nam);
    }
    catch (const std::exception& e) {
        throw runtime_error("Error set fuel value: " + string(e.what()));
    }
}
bool S::SetAuditSpend(const double& money) {
    try
    {
        jsonAccess.data["Audit"]["All"] = money;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e) {
        cerr << "Error update audit all: " << e.what() << endl;
        return false;
    }
}
bool S::SetAuditAll(const double& money) {
    try
    {
        jsonAccess.data["Audit"]["Spend"] = money;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update audit spend: " << e.what() << endl;
        return false;
    }
}
bool S::SetUserYears(const unsigned int& years) {
    try
    {
        jsonAccess.data["User"]["Years"] = years;
        jsonAccess.Save();
        jsonAccess.Load();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error set new value to Years user: " << e.what() << endl;
        return false;
    }
}