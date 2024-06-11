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

bool S::AddCombine(const std::string& id, const json& combineData) {
    data["Combines"].push_back({
        {"ID_Name", id},
        {"Charackter", combineData}
        });
    Save();
    return true;
}

bool S::UpdateUserBallance(const double& money) {
    try
    {
        data["User"]["Balance"] += money;
        Save();
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error update user ballance: " << e.what() << endl;
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
bool S::UpdateFuelLevel(const double& resizeTo, const string& id_nam) {
    Load();
    try {
        for (auto& combine : data["Combines"]) {
            if (combine["ID_Name"] == id_nam) {
                double ttl = combine["Characteristics"]["Fuel"];
                double resoult = ttl + resizeTo;
                combine["Characteristics"]["Fuel"] = resoult;
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

