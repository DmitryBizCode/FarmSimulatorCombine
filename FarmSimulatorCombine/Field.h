#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <random>
#include "SerializationDe.h"
#include "Combine.h"

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
using namespace std;
class Field : protected SerializationDe {
private:
    int rows;
    int cols;
    SesonTime SesonTime;
    double coin = 0;
    mt19937 rng;
    Combine& Com;
    vector<vector<FieldType>> matrix;
    map<FieldType, double> CoinFlex{
        { Wheat, 0.5},
        { HalfWheat, 0.2},
        { Bushes, 0.0},
        { Empty , 0.0}
    };
    float FieldTypeToInt(FieldType type) const {
        switch (type) {
            case Wheat: return 1;
            case HalfWheat: return 2;
            case Bushes: return 3;
            case Empty: return 0;
            default: return -5;
        }
    }
public:
    Field(Combine& Com) : Com(Com), rng(random_device{}()) {
        rows = GetFieldRows();
        cols = GetFieldColumns();
        SesonTime = Autumn;
        matrix.resize(rows, vector<FieldType>(cols, Empty));
    }
    bool CheckField();
    bool doingTask();

    bool DisplayMatrix();
    bool ConsistOfField();
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
