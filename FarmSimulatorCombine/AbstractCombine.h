#pragma once
#include <map>
#include <string>

class AbstractCombine {
public:
    virtual ~AbstractCombine() = default;

    // Віртуальні гетери для всіх полів
    virtual std::string getID_Name() const = 0;
    virtual double getDurability() const = 0;
    virtual double getDurabilityData() const = 0;
    virtual double getFuel() const = 0;
    virtual double getFuelCapacity() const = 0;
    virtual double getFuelConsumption() const = 0;
    virtual double getPrice() const = 0;

    // Віртуальні сетери для змінюваних полів
    virtual void setDurability(double durability) = 0;
    virtual void setFuel(double fuel) = 0;
    
    // Віртуальний метод для відображення характеристик
    virtual void DisplayCharacteristics() const = 0;
};
