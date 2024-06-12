#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
#include "AbstractCombine.h"
#include "SerializationDe.h"

using namespace std;

class Combine : protected SerializationDe, public AbstractCombine {
private:
	const string ID_Name;
    const int Price;
    double Durability;
    const double DurabilityData;
    double Fuel;
    const double FuelCapacity;
    const double FuelConsumption;
public:
    Combine(const string& id_Name) : ID_Name(id_Name),Durability(0),DurabilityData(0),Fuel(0),FuelCapacity(0),FuelConsumption(0), Price(0){
        map<string, double> ttl = GetCharacteristics(ID_Name);
        if (!ttl.empty()) {
            Durability = ttl["Durability"];
            const_cast<int&>(Price) = ttl["Price"];
            const_cast<double&>(DurabilityData) = ttl["DurabilityData"];
            Fuel = ttl["Fuel"];
            const_cast<double&>(FuelCapacity) = ttl["FuelCapacity"];
            const_cast<double&>(FuelConsumption) = ttl["FuelConsumption"];
        }
    }

    // Гетери
    std::string getID_Name() const override;
    double getDurability() const override;
    double getDurabilityData() const override;
    double getFuel() const override;
    double getFuelCapacity() const override;
    double getFuelConsumption() const override;
    double getPrice() const override;

    // Сетери
    void setDurability(double durability) override;
    void setFuel(double fuel) override;

    // Додаткові методи
    void DisplayCharacteristics() const override;
};

