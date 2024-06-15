#pragma once
#include "SerializationDe.h"
using namespace std;
class Market: private SerializationDe
{
public:
	bool SellCombine(const string& name_Id);
	bool BuyCombine(const string& name_Id);
	bool BuyField(const int& addField);
};

