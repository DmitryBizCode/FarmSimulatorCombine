#include "Combine.h"
// Гетери
std::string Combine::getID_Name() const {
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
void Combine::setDurability(double durability) {
    Durability = durability;
}

void Combine::setFuel(double fuel) {
    Fuel = fuel;
}

// Додаткові методи
void Combine::DisplayCharacteristics() const {
    std::cout << "ID_Name: " << ID_Name << std::endl;
    std::cout << "Price: " << Price << std::endl;
    std::cout << "Durability: " << Durability << std::endl;
    std::cout << "DurabilityData: " << DurabilityData << std::endl;
    std::cout << "Fuel: " << Fuel << std::endl;
    std::cout << "FuelCapacity: " << FuelCapacity << std::endl;
    std::cout << "FuelConsumption: " << FuelConsumption << std::endl;
}