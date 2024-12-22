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

void HeadersOut(vector <char> data)
{
    VolumeHeadeer* vm_header = reinterpret_cast <VolumeHeadeer*> (&data[7]);
    int displace = 7 + int(vm_header -> header_size);

    while (int(data[displace+2]) == 116)
    {
        VolumeHeadeer* vf_header = reinterpret_cast <VolumeHeadeer*> (&data[displace]);
        FileHeader* v_header = reinterpret_cast <FileHeader*> (&data[displace+7]);

        for (int i = 0; i < (int(v_header -> NameSize)); i++)
        {
            cout << char(data[displace + 32 + i]);
        }
        cout << endl << endl;

        displace += int(vf_header -> header_size) + int(v_header -> PackSize);
    }
}

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

        HeadersOut(rData);
    }

    return 0;
}