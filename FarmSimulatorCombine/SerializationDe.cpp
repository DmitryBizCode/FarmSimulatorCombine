#include "SerializationDe.h"
#define S SerializationDe

bool S::Save() {
    ofstream file(filename);
    try {
        if (file.is_open()) {
            file << data.dump(4);  // 4 - кількість відступів для форматування
            file.close();
            return true;
        }
        else {
            cerr << "Cant open a file to rewrite" << endl;
            return false;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error to ofstream file save: " << e.what() << endl;
        return false;
    }
}
json S::Load() {
    try
    {
        ifstream file(filename);
        json data;
        if (file.is_open()) {
            file >> data;
            file.close();
        }
        else {
            cerr << "Cant open a file" << std::endl;
        }
        return data;
    }
    catch (const std::exception& e)
    {
        cerr << "Error to load a file" << e.what() << endl;
    }
}

bool S::ResetBalance() {
    try
    {
        Load();
        data["Audit"]["All"] = 0;
        data["Audit"]["Spend"] = 0;
        Save();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error reset balance: " << e.what() << endl;
        return false;
    }
}

bool S::AddCombine(const std::string& id_nam) {
    Load();
    try
    {
        for (const auto ttl : data["CombinesMall"])        
            if (ttl["ID_Name"] == id_nam)
            {
                json new_combine = {
                    {"ID_Name", id_nam},
                    {"Characteristics", {
                        {"Durability", ttl["Characteristics"]["Durability"]},
                        {"DurabilityData", ttl["Characteristics"]["DurabilityData"]},
                        {"Fuel", ttl["Characteristics"]["Fuel"]},
                        {"FuelCapacity", ttl["Characteristics"]["FuelCapacity"]},
                        {"FuelConsumption", ttl["Characteristics"]["FuelConsumption"]}
                    }}
                };
                data["Combines"].push_back(new_combine);
                break;
            }        
        Save();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error add new combine: " << e.what() << endl;
        return false;
    }
}

bool S::UpdateUserBallance(double money) {
    try
    {
        money += data["User"]["Balance"];
        data["User"]["Balance"] = money;
        Save();
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
        money += data["Audit"]["All"];
        data["Audit"]["All"] = money;
        Save();
        return true;
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
        money += data["Audit"]["Spend"];
        data["Audit"]["Spend"] = money;
        Save();
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
            data["Field"]["Columns"] = data["Field"]["Columns"] + newSize;
            Save();
            return true;
        }
        else
        {
            data["Field"]["Rows"] = data["Field"]["Rows"] + newSize;
            Save();
            return true;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error update field: " << e.what() << endl;
        return false;
    }
}
bool S::UpdateFuelLevel(double resizeTo, const string& id_nam) {
    Load();
    try {
        for (auto& combine : data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                resizeTo += combine["Characteristics"]["Fuel"].get<double>();
                combine["Characteristics"]["Fuel"] = resizeTo;
                Save();
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
    Load();
    try {
        for (auto& combine : data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                resizeTo += combine["Characteristics"]["Durability"].get<double>();
                combine["Characteristics"]["Durability"] = resizeTo;
                Save();
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
    data = Load();
    return data["User"]["Balance"];
}
const int S::GetFieldRows() {
    data = Load();
    return data["Field"]["Rows"];
}
const int S::GetFieldColumns() {
    data = Load();
    return data["Field"]["Columns"];
}
const map<string, double> S::GetCharacteristics(const string& nam_Id) {
    Load();
    try {
        for (const auto& ttl : data["Combines"]) {
            if (ttl["ID_Name"] == nam_Id) {
                map<string, double> mapCharacter{
                    {"Durability", ttl["Characteristics"]["Durability"].get<double>()},
                    {"Fuel", ttl["Characteristics"]["Fuel"].get<double>()},
                    {"FuelCapacity", ttl["Characteristics"]["FuelCapacity"].get<double>()},
                    {"DurabilityData", ttl["Characteristics"]["DurabilityData"].get<double>()},
                    {"FuelConsumption", ttl["Characteristics"]["FuelConsumption"].get<double>()}
                };
                return mapCharacter;
            }
        }
        return {};
    }
    catch (const std::exception& e) {
        cerr << "Error GetCharacteristics: " << e.what() << endl;

        //throw runtime_error("Error get array from characteristics combine: " + string(e.what()));
    }
}
const double S::GetAuditSpend() {
    data = Load();
    return data["Audit"]["Spend"];
}
const double S::GetAuditAll() {
    data = Load();
    return data["Audit"]["All"];
}

bool S::SetSizeFieldRows(const int& setSize){
    try
    {
        data["Field"]["Rows"] = setSize;
        Save();
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
        data["Field"]["Columns"] = setSize;
        Save();
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
        data["User"]["Balance"] = money;
        Save();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error set new value to current ballance user: " << e.what() << endl;
        return false;
    }
}
bool S::SetFuelLevel(const double& resizeTo, const string& id_nam) {
    Load();
    try {
        for (auto& combine : data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                combine["Characteristics"]["Fuel"] = resizeTo;
                Save();
                return true;
            }
        }
        throw runtime_error("ID_Name not found: " + id_nam);
    }
    catch (const std::exception& e) {
        throw runtime_error("Error updating fuel value: " + string(e.what()));
    }
}
bool S::SetAuditSpend(const double& money) {
    try
    {
        data["Audit"]["All"] = money;
        Save();
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
        data["Audit"]["Spend"] = money;
        Save();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update audit spend: " << e.what() << endl;
        return false;
    }
}
