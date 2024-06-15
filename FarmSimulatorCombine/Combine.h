#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include "AbstractCombine.h"
#include "SerializationDe.h"

using namespace std;

class Combine : private SerializationDe, public AbstractCombine {
private:
	const string ID_Name;
    const int Price;
    double Durability;
    const double DurabilityData;
    double Fuel;
    const double FuelCapacity;
    const double FuelConsumption;
public:
    Combine(const string& id_Name);
    Combine(const Combine& other);
    Combine()
        : ID_Name("Unknown"),
        Price(0),
        Durability(0),
        DurabilityData(0),
        Fuel(0),
        FuelCapacity(0),
        FuelConsumption(0) {}

    // Гетери
    string getID_Name() const override;
    double getDurability() const override;
    double getDurabilityData() const override;
    double getFuel() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getPrice() const override;

    bool CheckReality();

    bool Refueling(const int& fuel);
    bool FullRefueling();
    bool Repair(const int& fixedInt);
    bool FullRepair();

    void DisplayCharacteristics() override;

    bool UpdateCharacteristics();
};

