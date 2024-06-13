#include "JsonAccess.h"
bool JsonAccess::Save() {
    ofstream file(filename);
    try {
        if (file.is_open()) {
            file << data.dump(4);
            file.close();
            return true;
        }
        else {
            cerr << "Cant open a file to rewrite" << endl;
            return false;
        }
    }
    catch (const std::exception& e) {
        cerr << "Error to ofstream file save: " << e.what() << endl;
        return false;
    }
}
json JsonAccess::Load() {
    try
    {
        ifstream file(filename);
        json data;
        if (file.is_open()) {
            file >> data;
            this->data = data;
            file.close();
        }
        else {
            cerr << "Cant open a file" << std::endl;
        }
        return data;
    }
    catch (const std::exception& e)
    {
        cerr << "Error to load a file" << e.what() << endl;
    }
}
