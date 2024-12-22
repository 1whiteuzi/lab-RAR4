#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    ifstream file("Data.rar", ios::binary);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        int size = file.tellg();
        file.seekg(0, ios::beg);

        vector <char> rData(size, 0);
        file.read(rData.data(), size);

    }

    return 0;
}