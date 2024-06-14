#pragma once
#include "SerializationDe.h"
using namespace std;
class Market: private SerializationDe
{
private:

public:
	bool SellCombine(const string& name_Id) {

		auto character = GetCharacteristics(name_Id);
		auto sum = (character["Price"] * character["Durability"]) + character["Fuel"] - 5;
		GetUserBallance();
		SerializationDe::SellCombine(name_Id);
	}
	bool BuyCombine() {
		return true;
	}
};

