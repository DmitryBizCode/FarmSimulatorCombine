// FarmSimulatorCombine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Combine.h"
#include "Field.h"
#include "FieldStaticArray.h"
#include "Market.h"

#include "SerializationDe.h"

int main()
{
    cout << "Hello World!\n";


    Market M;
    //cout<<M.BuyField(40);

    //cout<<M.SellCombine("JohnDeerPRO");
    cout << M.BuyCombine("JohnDeerPRO");

    SerializationDe S;
    M.BuyField(10);


    FieldStaticArray A;
    Combine C("JohnDeerPRO");
    Field F(C);
    C.FullRefueling();
    C.Repair(50);


    C.UpdateCharacteristics();
    C.DisplayCharacteristics();
    cout << endl << endl;
    F.Harvest();
    C.UpdateCharacteristics();
    C.DisplayCharacteristics();
    cout << endl << endl;
    F.Harvest();
    C.UpdateCharacteristics();
    C.DisplayCharacteristics();
    cout << endl << endl;
    cout << S.GetFieldRows();
    cout << endl << endl;
    cout << S.GetFieldColumns();
    M.BuyField(50);
    F.Harvest();
    C.UpdateCharacteristics();
    C.DisplayCharacteristics();
    cout << endl << endl;
    cout << S.GetFieldRows();
    cout << endl << endl;
    cout << S.GetFieldColumns();
    cout << endl << endl;

    //cout<<M.BuyField(40);

    //cout<<M.SellCombine("JohnDeerPRO");
    //cout<<M.BuyCombine("JohnDeerPRO");

    //SerializationDe S;

    ////S.AddCombine("JohnDeerPRO");

    //FieldStaticArray A;
    //Combine C ("JohnDeerPRO");
    //Field F(C);


    //C.UpdateCharacteristics();
    //C.DisplayCharacteristics();
    //cout << endl << endl;
    //F.Harvest();
    //C.UpdateCharacteristics();
    //C.DisplayCharacteristics();
    //cout << endl << endl;
    //F.Harvest();
    //C.UpdateCharacteristics();
    //C.DisplayCharacteristics();
    //cout << endl << endl;
    //F.Harvest();
    //C.UpdateCharacteristics();
    //C.DisplayCharacteristics();
    //cout << endl << endl;

    //C.DisplayCharacteristics();
    //C.Repair(10);
    //C.Refueling(10);
    //C.UpdateCharacteristics();
    //cout << endl << endl;
    //C.DisplayCharacteristics();
    //C.FullRefueling();
    //C.FullRepair();
    //C.UpdateCharacteristics();
    //cout << endl << endl;
    //C.DisplayCharacteristics();
    //C.Repair(10);
    //C.Refueling(10);
    //C.UpdateCharacteristics();
    //cout << endl << endl;
    //C.DisplayCharacteristics();







    /*cout << endl << endl;
    cout << "S.GetAuditAll()" << S.GetAuditAll() << endl;
    cout << "S.GetAuditSpend()" << S.GetAuditSpend() << endl;
    cout << "S.GetUserBallance()" << S.GetUserBallance() << endl;
    cout << endl << endl;
    F.Harvest();
    C.DisplayCharacteristics();
    cout << endl << endl;
    cout << "S.GetAuditAll()" << S.GetAuditAll() << endl;
    cout << "S.GetAuditSpend()" << S.GetAuditSpend() << endl;
    cout << "S.GetUserBallance()" << S.GetUserBallance() << endl;
    SerializationDe E;
    Combine Cw("JohnDeerPRO");
    cout << endl << endl;
    cout << "Cw.Zap(10)" << Cw.Refueling(10) << endl;
    cout << endl << endl;
    cout << "S.GetAuditAll()" << S.GetAuditAll() << endl;
    cout << "S.GetAuditSpend()" << S.GetAuditSpend() << endl;
    cout << "S.GetUserBallance()" << S.GetUserBallance() << endl;
    cout << endl << endl;
    map<string, double> s = E.GetCharacteristics("JohnDeerPRO");
    cout << "s[Fuel]" << s["Fuel"] << endl;
    cout << "s[Durability]" << s["Durability"] << endl;
    cout << "F.CheckField()" << F.CheckField();
    cout << endl << endl;
    cout << "C.CheckReality()" << C.CheckReality();
    cout << endl << endl;

    cout << " F.TransmitArrray()" << F.TransmitArrray();*/







    //S.UpdateFuelLevel(50, C.getID_Name());

    //cout<<S.SellCombine(C.getID_Name());

    //C.DisplayCharacteristics();
    //cout << endl;
    //C.setDurability(10);
    //C.DisplayCharacteristics();
    //cout << endl;
    //SerializationDe S;
    //Field F(C);
    //F.ConsistOfField();

    //F.DisplayMatrix();

    //for (auto& s : S.GetCharacteristics("JohnDeerPRO"))
    //{
    //    cout << s.first << s.second << endl;
    //}


    /*try {
        auto marketData = S.GetCharacteristicsMarket();
        auto id_names = get<0>(marketData);
        auto characteristics = get<1>(marketData);

        for (size_t i = 0; i < id_names.size(); ++i) {
            cout << "ID_Name: " << id_names[i] << endl;
            for (const auto& kv : characteristics[i]) {
                cout << kv.first << ": " << kv.second << endl;
            }
        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << endl;
    }*/


    //cout<<S.SellCombine("JohnDeer1");

    //for (auto& s : S.GetCharacteristics("JohnDeerPRO"))
    //{
    //    cout << s.first << s.second << endl;
    //}
    //
    ///*cout << S.UpdateDurability(-2.4, "JohnDeerPRO") << endl;
    //cout << S.UpdateFuelLevel(-5.1, "JohnDeerPRO") << endl;*/
    //map<string, double> s = S.GetCharacteristics("JohnDeerPRO");
    //cout << s["Fuel"] << endl;
    //cout << s["Durability"] << endl;

    /*
    S.SetFuelLevel(150, "JohnDeerPRO");
    map<string, double> sq = S.GetCharacteristics("JohnDeerPRO");
    cout << sq["Fuel"] << endl;*/


    /*
    cout << S.GetFieldColumns() << endl;
    cout << S.GetFieldRows() << endl;

    cout << S.UpdateField(40, 0) << endl;
    cout << S.GetFieldColumns()<<endl;
    cout << S.GetFieldRows() << endl;*/




    return 0;
}
