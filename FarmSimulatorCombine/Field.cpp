#include "Field.h"


//bool Field::ConsistOfField() {
//    try
//    {
//		uniform_int_distribution<int> dist(0, 99);
//		for (size_t i = 0; i < rows; i++)
//			for (size_t j = 0; j < cols; j++)
//			{
//				int rand_value = dist(rng);
//				if (rand_value < 90)
//					matrix[i][j] = Wheat;
//				else if (rand_value < 96)
//					matrix[i][j] = HalfWheat;
//				else
//					matrix[i][j] = Bushes;
//			}
//		return true;
//    }
//    catch (const std::exception& e)
//    {
//        cerr << "Error ConsistOfField: " << e.what() << endl;
//        return false;
//    }
//}
//bool Field::Harvest() {
//
//}





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