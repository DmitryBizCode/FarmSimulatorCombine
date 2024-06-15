// FarmSimulatorCombine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Combine.h"
#include "Field.h"
#include "FieldStaticArray.h"

#include "SerializationDe.h"

int main()
{
    cout << "Hello World!\n";
    SerializationDe S;

    //S.AddCombine("JohnDeerPRO");

    FieldStaticArray A;
    Combine C ("JohnDeerPRO");
    Field F(C);

    C.DisplayCharacteristics();
    cout << endl << endl;
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

    cout << " F.TransmitArrray()" << F.TransmitArrray();







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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
