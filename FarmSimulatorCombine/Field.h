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

using namespace std;
class Field : protected SerializationDe {
private:
    int rows;
    int cols;
    bool years = false;
    mt19937 rng;
    //Combine Com;
    vector<vector<FieldType>> matrix;
public:
    /*Field(Combine& Com) : Com(Com), rng(random_device{}()) {
        rows = GetFieldRows();
        cols = GetFieldColumns();
    }*/
    //bool ConsistOfField();
    //bool Harvest();
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
