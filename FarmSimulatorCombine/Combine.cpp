#include "Combine.h"

Combine::Combine(const std::string& id_Name): ID_Name(id_Name), Price(0),Durability(0),DurabilityData(0),Fuel(0), FuelCapacity(0),  FuelConsumption(0) {
    std::map<std::string, double> ttl = GetCharacteristics(ID_Name);
    if (!ttl.empty()) {
        Durability = ttl["Durability"];
        const_cast<int&>(Price) = ttl["Price"];
        const_cast<double&>(DurabilityData) = ttl["DurabilityData"];
        Fuel = ttl["Fuel"];
        const_cast<double&>(FuelCapacity) = ttl["FuelCapacity"];
        const_cast<double&>(FuelConsumption) = ttl["FuelConsumption"];
    }
}

Combine::Combine(const Combine& other)
    : ID_Name(other.ID_Name),
    Price(other.Price),
    Durability(other.Durability),
    DurabilityData(other.DurabilityData),
    Fuel(other.Fuel),
    FuelCapacity(other.FuelCapacity),
    FuelConsumption(other.FuelConsumption) {}

// Гетери
string Combine::getID_Name() const {
    return ID_Name;
}

double Combine::getDurability() const {
    return Durability;
}

double Combine::getDurabilityData() const {
    return DurabilityData;
}

double Combine::getFuel() const {
    return Fuel;
}

double Combine::getFuelCapacity() const {
    return FuelCapacity;
}

double Combine::getFuelConsumption() const {
    return FuelConsumption;
}

double Combine::getPrice() const {
    return Price;
}

bool Combine::CheckReality() {
    auto a = GetCharacteristics(ID_Name);
    if (a.size() == 0)
        return false;
    else
        return true;
}

bool Combine::Refueling(const int& fuel) {
    try
    {
        auto userBallance = GetUserBallance();
        if (userBallance >= (5.0 * fuel))
        {
            if (FuelCapacity >= (Fuel + fuel))
            {
                UpdateFuelLevel(fuel, ID_Name);
                UpdateUserBallance(fuel * (-5.0));
                UpdateAuditSpend(fuel * 5.0);
                return true;
            }
            else
            {
                auto newFuel = (FuelCapacity - Fuel - 0.1);
                UpdateFuelLevel(newFuel, ID_Name);
                UpdateUserBallance(newFuel * (-5.0));
                UpdateAuditSpend(newFuel * 5.0);
                return true;
            }
        }
        else
        {
            double Fuel5 = userBallance / 5.0;
            UpdateFuelLevel(Fuel5, ID_Name);
            UpdateUserBallance(userBallance * (-1.0));
            UpdateAuditSpend(userBallance);
            return true;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error Refueling: " << e.what() << endl;
        return false;
    }
}

bool Combine::FullRefueling() {
    try
    {
        auto userBallance = GetUserBallance();
        double capacityOfFuel = FuelCapacity - Fuel;
        if (userBallance >= (capacityOfFuel * 5.0))
        {
            UpdateFuelLevel(capacityOfFuel, ID_Name);
            UpdateUserBallance(capacityOfFuel * (-5.0));
            UpdateAuditSpend(capacityOfFuel * 5.0);
            return true;
        }
        else
        {
            cerr << "Insufficient funds" << endl;
            return false;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error FullRefueling: " << e.what() << endl;
        return false;
    }
}

bool Combine::Repair(const int& fixedInt) {
    try
    {
        auto userBallance = GetUserBallance();
        if (userBallance >= (10.0 * fixedInt))
        {
            if (100 >= (Durability + fixedInt))
            {
                UpdateDurability(fixedInt, ID_Name);
                UpdateUserBallance(fixedInt * (-10.0));
                UpdateAuditSpend(fixedInt * 10.0);
                return true;
            }
            else
            {
                auto newFixedDouble = (100.0 - Durability - 0.1);
                UpdateDurability(newFixedDouble, ID_Name);
                UpdateUserBallance(newFixedDouble * (-10.0));
                UpdateAuditSpend(newFixedDouble * 10.0);
                return true;
            }
        }
        else
        {
            double newFixedDouble10 = userBallance / 10.0;
            UpdateDurability(newFixedDouble10, ID_Name);
            UpdateUserBallance(userBallance * (-1.0));
            UpdateAuditSpend(userBallance);
            return true;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error Repair: " << e.what() << endl;
        return false;
    }
}

bool Combine::FullRepair() {
    try
    {
        auto userBallance = GetUserBallance();
        double capacityOfDurability = 100.0 - Durability;
        if (userBallance >= (capacityOfDurability * 10.0))
        {
            UpdateDurability(capacityOfDurability, ID_Name);
            UpdateUserBallance(capacityOfDurability * (-10.0));
            UpdateAuditSpend(capacityOfDurability * 10.0);
            return true;
        }
        else
        {
            cerr << "Insufficient funds" << endl;
            return false;
        }
    }
    catch (const std::exception& e)
    {
        cerr << "Error FullRepair: " << e.what() << endl;
        return false;
    }
}

bool Combine::UpdateCharacteristics() {
    std::map<std::string, double> ttl = GetCharacteristics(ID_Name);
    if (!ttl.empty()) {
        Durability = ttl["Durability"];
        Fuel = ttl["Fuel"];
        return true;
    }
    return false;
}

void Combine::DisplayCharacteristics() const {
    std::cout << "ID_Name: " << ID_Name << std::endl;
    std::cout << "Price: " << Price << std::endl;
    std::cout << "Durability: " << Durability << std::endl;
    std::cout << "DurabilityData: " << DurabilityData << std::endl;
    std::cout << "Fuel: " << Fuel << std::endl;
    std::cout << "FuelCapacity: " << FuelCapacity << std::endl;
    std::cout << "FuelConsumption: " << FuelConsumption << std::endl;
}