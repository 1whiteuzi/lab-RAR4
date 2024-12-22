#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

#pragma pack(push, 1)

struct VolumeHeadeer {
    uint16_t header_crc;
    uint8_t header_type;
    uint16_t header_flags;
    uint16_t header_size;
};

struct FileHeader {
    uint32_t PackSize;
    uint32_t UnpSize;
    uint8_t HostOS;
    uint32_t FileCRC;
    uint32_t FileTime;
    uint8_t UnpVer;
    uint8_t Method;
    uint16_t NameSize;
    uint32_t FileAttr;
};

#pragma pack(pop)

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