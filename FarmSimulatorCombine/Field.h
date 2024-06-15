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

class Field : protected SerializationDe {
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
        if (matrixInt.size() >= 19)
        {
            // Кількість рядків
            rows = matrixInt.size();
            cols = rows > 0 ? matrixInt[0].size() : 0;
            for (size_t i = 0; i < rows; i++)
                for (size_t j = 0; j < cols; j++)
                    matrix[i][j] = IntToFieldType(matrixInt[i][j]);
        }
    }
    bool TransmitArrray() {
        vector<vector<int>> matrixInt(rows, vector<int>(cols));
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                matrixInt[i][j] = FieldTypeToInt(matrix[i][j]);
            }
        }
        fiStat.Serialize(matrixInt);
        return true;
    }
    bool CheckField();
    bool DisplayMatrix();
    bool Harvest();
};
//class Field {
//public:
//    Field(int rows = 20, int cols = 20);
//    void Display() const;
//    void SetValue(int row, int col, FieldType value);
//    void Randomize();
//    FieldType GetValue(int row, int col) const;
//    int GetRows()const;
//    int GetCols()const;
//    void ExpandField(int additional_rows, int additional_cols);
//    bool BuyFields(int count);
//private:
//    int _rows;
//    int _cols;
//    mt19937 rng;
//    vector<vector<FieldType>> matrix;
//};
