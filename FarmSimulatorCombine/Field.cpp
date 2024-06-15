#include "Field.h"
bool Field::ConsistOfField() {
    try {
        uniform_int_distribution<int> dist(0, 99);
        rows = GetFieldRows();
        cols = GetFieldColumns();
        vector<vector<FieldType>> ttl;
        ttl.resize(rows, vector<FieldType>(cols, Empty));
        matrix = ttl;
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
bool Field::ResetField() {
    vector<vector<int>> matrixInt = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    UpdateField(4, 1);
    UpdateField(3, 0);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            matrixInt[i][j] = FieldTypeToInt(matrix[i][j]);
    fiStat.Serialize(matrixInt);
    return true;
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
bool Field::TransmitArrray() {
    vector<vector<int>> matrixInt(rows, vector<int>(cols));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            matrixInt[i][j] = FieldTypeToInt(matrix[i][j]);
    fiStat.Serialize(matrixInt);
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
                    fuel -= (0.003 + 0.1 * fuelConsumption * (1 - (Com.getDurability() * 0.01)) * FieldTypeToInt(matrix[i][j]));
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
