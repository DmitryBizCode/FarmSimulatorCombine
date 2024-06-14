#pragma once
#include "SerializationDe.h"
using namespace std;
class Market: private SerializationDe
{
private:
public:
	bool SellCombine(const string& name_Id) {
		GetCharacteristics(name_Id);
		SerializationDe::SellCombine(name_Id);
	}
};

