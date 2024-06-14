#pragma once
#include <map>
#include <string>
using namespace std;
class AbstractCombine {
public:
    virtual ~AbstractCombine() = default;

    // ³������� ������ ��� ��� ����
    virtual string getID_Name() const = 0;
    virtual double getDurability() const = 0;
    virtual double getDurabilityData() const = 0;
    virtual double getFuel() const = 0;
    virtual double getFuelCapacity() const = 0;
    virtual double getFuelConsumption() const = 0;
    virtual double getPrice() const = 0;
    
    // ³��������� ����� ��� ����������� �������������
    virtual void DisplayCharacteristics() const = 0;
};
