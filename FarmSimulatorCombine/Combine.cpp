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

// Сетери
bool Combine::setDurability(const double& durability) {
    UpdateDurability(durability, this->ID_Name);
    Durability += durability;
    return true;
}

bool Combine::setFuel(const double& fuel) {
    UpdateFuelLevel(fuel, this->ID_Name);
    Fuel += fuel;
    return true;
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