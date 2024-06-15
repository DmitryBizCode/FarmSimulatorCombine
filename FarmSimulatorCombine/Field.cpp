#include "Field.h"
bool Field::ConsistOfField() {
    try {
        uniform_int_distribution<int> dist(0, 99);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j) {
                int rand_value = dist(rng);
                if (rand_value < 90)
                    matrix[i][j] = Wheat;
                else if (rand_value < 96)
                    matrix[i][j] = HalfWheat;
                else
                    matrix[i][j] = Bushes;
            }
        return true;
    }
    catch (const std::exception& e) {
        cerr << "Error ConsistOfField: " << e.what() << endl;
        return false;
    }
}

bool Field::DisplayMatrix() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            cout << FieldTypeToInt(matrix[i][j]) << " ";
        cout << endl;
    }
    cout << endl;
    Com.DisplayCharacteristics();
    return true;
}
bool Field::CheckField() {
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (matrix[i][j] != Empty)
                return false;
    return true;
}
bool Field::doingTask() {
    try
    {
        double fuel = Com.getFuel();
        double fuelConsumption = Com.getFuelConsumption();
        double durability = Com.getDurability();
        double durabilityData = Com.getDurabilityData();
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                if ((fuel >= (fuelConsumption * 2)) && ((durability - durabilityData * 3) > 0) && (matrix[i][j] != Empty))
                {
                    fuel -= (0.1 * fuelConsumption * (1 - (Com.getDurability() * 0.01)) * FieldTypeToInt(matrix[i][j]));
                    durability -= (durabilityData * 0.01 * FieldTypeToInt(matrix[i][j]));
                    coin += CoinFlex[matrix[i][j]];
                    matrix[i][j] = Empty;
                }

        UpdateFuelLevel((Com.getFuel() - fuel) * (-1), Com.getID_Name());
        UpdateDurability((Com.getDurability() - durability) * (-1), Com.getID_Name());

        Com.UpdateCharacteristics();

        UpdateAuditAll(coin);
        UpdateUserBallance(coin);
        if (SesonTime == Winter && CheckField())
        {
            SesonTime = Summer;
            UpdateUserYears();
        }
        else if (CheckField())
            SesonTime = Winter;
        return true;
    }
    catch (const std::exception& e)
    {
        cerr << "Error Field doingTask: " << e.what() << endl;
        return false;
    }
}
bool Field::Harvest() {
    try
    {
        if (!CheckField()) {
            doingTask();
            return true;
        }
        else
        {
            ConsistOfField();
            doingTask();
            return true;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error Field Harvest: " << e.what() << endl;
        return false;
    }
}




//Field::Field(int rows, int cols) : _rows(rows), _cols(cols), matrix(rows, vector<FieldType>(cols, Wheat))
//{
//    random_device rd;
//    rng.seed(rd());
//    Randomize();
//}
//
//
//void Field::Display() const
//{
//    for (const auto& row : matrix)
//    {
//        for (const auto& val : row)
//            cout << val << " ";
//        cout << endl;
//    }
//}
//
//void Field::SetValue(int row, int col, FieldType value)
//{
//    if (row >= 0 && row < _rows && col >= 0 && col < _cols)
//        matrix[row][col] = value;
//    else
//        throw std::out_of_range("Row or column out of bounds");
//
//}
//bool Field::BuyFields(int count)
//{
//    if (count == _rows)
//    {
//
//    }
//    return 0;
//}
//
//
//void Field::Randomize()
//{
//    uniform_int_distribution<int> dist(0, 99);
//
//    for (int i = 0; i < _rows; i++)
//        for (int j = 0; j < _cols; j++)
//        {
//            int rand_value = dist(rng);
//            if (rand_value < 90)
//                matrix[i][j] = Wheat;
//            else if (rand_value < 96)
//                matrix[i][j] = HalfWheat;
//            else
//                matrix[i][j] = Bushes;
//        }
//}
//
//FieldType Field::GetValue(int row, int col) const
//{
//    if (row >= 0 && row < _rows && col >= 0 && col < _cols)
//        return matrix[row][col];
//    else
//        throw out_of_range("Row or column out of bounds");
//}
//
//int Field::GetRows()const
//{
//    return _rows;
//}
//
//int Field::GetCols()const
//{
//    return _cols;
//}
//
//void Field::ExpandField(int additional_rows, int additional_cols)
//{
//    for (int i = 0; i < additional_rows; i++)
//    {
//        vector<FieldType> newRow(_cols, Wheat);
//        matrix.push_back(newRow);
//    }
//
//    _rows += additional_rows;
//
//    for (auto& row : matrix)
//        row.resize(_cols + additional_cols, Wheat);
//    _cols += additional_cols;
//}