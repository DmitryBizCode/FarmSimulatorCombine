#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <random>
//#include "Serialization.h"

enum FieldType
{
    Wheat = 0,
    HalfWheat = 1,
    Bushes = 2
};

using namespace std;
class Field {
public:
    Field(int rows = 20, int cols = 20);
    void Display() const;
    void SetValue(int row, int col, FieldType value);
    void Randomize();
    FieldType GetValue(int row, int col) const;
    int GetRows()const;
    int GetCols()const;
    void ExpandField(int additional_rows, int additional_cols);
    bool BuyFields(int count);
private:
    int _rows;
    int _cols;
    mt19937 rng;
    vector<vector<FieldType>> matrix;
};

#endif 

