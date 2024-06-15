#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <random>
#include "SerializationDe.h"
#include "Combine.h"
#include "FieldStaticArray.h"

using namespace std;

enum FieldType
{
    Wheat,
    HalfWheat,
    Bushes,
    Empty
};
enum SesonTime
{
    Winter,
    Summer,
    Autumn
};

class Field : private SerializationDe {
private:
    int rows;
    int cols;
    SesonTime SesonTime;
    double coin = 0;
    mt19937 rng;
    Combine& Com;
    FieldStaticArray fiStat;
    vector<vector<FieldType>> matrix;
    map<FieldType, double> CoinFlex{
        { Wheat, 0.5},
        { HalfWheat, 0.2},
        { Bushes, 0.0},
        { Empty , 0.0}
    };
    int FieldTypeToInt(FieldType type) const {
        switch (type) {
        case Wheat: return 1;
        case HalfWheat: return 2;
        case Bushes: return 3;
        case Empty: return 0;
        default: return -5;
        }
    }
    FieldType IntToFieldType(int type) const {
        switch (type) {
        case 1: return Wheat;
        case 2: return HalfWheat;
        case 3: return Bushes;
        case 0: return Empty;
        default: return Empty;
        }
    }
    bool doingTask();
    bool ConsistOfField();

public:
    Field(Combine& Com) : Com(Com), rng(random_device{}()) {
        rows = GetFieldRows();
        cols = GetFieldColumns();
        matrix.resize(rows, vector<FieldType>(cols, Empty));
        SesonTime = Autumn;
        vector<vector<int>> matrixInt = fiStat.Deserialize();
        if (matrixInt.size() >= rows || matrixInt[0].size() >= cols)
        {

            rows = matrixInt.size();
            cols = rows > 0 ? matrixInt[0].size() : 0;
            UpdateField(cols, 1);
            UpdateField(rows, 0);
            vector<vector<FieldType>> ttl;
            ttl.resize(rows, vector<FieldType>(cols, Empty));
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    ttl[i][j] = IntToFieldType(matrixInt[i][j]);
            matrix = ttl;
        }
    }
    bool TransmitArrray();
    bool CheckField();
    bool DisplayMatrix();
    bool Harvest();
    bool ResetField();
};

