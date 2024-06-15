#pragma once
#include "SerializationDe.h"
using namespace std;
class Market: private SerializationDe
{
private:

public:
	bool SellCombine(const string& name_Id) {
		try
		{
			bool flag = false;
			for (const auto& a : GetCharacteristicsArrayName())
				if (name_Id == a)
					flag = true;
			if (flag)
			{
				auto character = GetCharacteristics(name_Id);
				auto sum = (character["Price"] * character["Durability"] * 0.01) + (character["Fuel"] * 2 - 10);
				SerializationDe::SellCombine(name_Id);
				UpdateUserBallance(sum);
				UpdateAuditAll(sum);
				return true;
			}
			else
				return false;			
		}
		catch (const std::exception& e)
		{
			cerr << "Error SellCombine : " << e.what() << endl;
			return false;
		}		
	}
	bool BuyCombine(const string& name_Id) {
		try
		{
			auto character = GetCharacteristics(name_Id);
			if (GetUserBallance() >= character["Price"])
			{
				for (const auto& a : GetCharacteristicsArrayName())				
					if (name_Id == a)					
						return false;
				SerializationDe::AddCombine(name_Id);
				UpdateUserBallance(character["Price"]  * (- 1));
				UpdateAuditSpend(character["Price"]);
				return true;
			}
			return false;
		}
		catch (const std::exception& e)
		{
			cerr << "Error SellCombine : " << e.what() << endl;
			return false;
		}
	}
	bool BuyField(const int& addField) {
		try
		{
			if (GetUserBallance() >= (addField * 20))
			{
				if (addField % GetFieldRows() == 0)
				{
					int metr = addField / GetFieldRows();
					SetSizeFieldColumns(GetFieldColumns() + metr);
					UpdateUserBallance(addField * 20 * (-1));
					UpdateAuditSpend(addField * 20);
					return true;
				}
				else if (addField % GetFieldColumns() == 0)
				{
					int metr = addField / GetFieldColumns();
					SetSizeFieldRows(GetFieldRows() + metr);
					UpdateUserBallance(addField * 20 * (-1));
					UpdateAuditSpend(addField * 20);
					return true;
				}
				return false;
			}
			return false;
		}
		catch (const std::exception& e)
		{
			cerr << "Error SellCombine : " << e.what() << endl;
			return false;
		}
	}
};

