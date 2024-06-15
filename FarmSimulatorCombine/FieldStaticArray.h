#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include "nlohmann/json.hpp"
using json = nlohmann::json;
class FieldStaticArray {
private :
    string filename = "databasearray.json";
    vector<vector<int>> matrix;
    void writeToFile(const json& j) {
        ofstream file(filename);
        if (file.is_open()) {
            file << j.dump(4);
            file.close();
        }
        else {
            cerr << "Не вдалося відкрити файл для запису!" << endl;
        }
    }

    json readFromFile() {
        ifstream file(filename);
        json j;
        if (file.is_open()) {
            file >> j;
            file.close();
        }
        else {
            cerr << "Не вдалося відкрити файл для читання!" << endl;
        }
        return j;
    }
public:
    void Serialize(const vector<vector<int>>& data) {
        json j = data;
        writeToFile(j);
    }

    vector<vector<int>> Deserialize() {
        json j = readFromFile();
        return j.get<vector<vector<int>>>();
    }
};

