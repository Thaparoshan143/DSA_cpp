// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<hash/openhash.cpp>

using namespace Utils;

// temporary object..
struct ImageCont
{
    // only temporary usages
    ImageCont(const uint w=1): width(w) {   }

    // some meta information
    uint width {};
    uint height {};
    uint channels { 3 };
    uint size {};
    // maybe some buffers..
    uchar* buffer { nullptr };
};

int main()
{
    using KeyType = String;
    using ValueType = ImageCont;

    OpenHashTableProps<KeyType, HashDType> ohtp {};
    ohtp.tableSize = 1 << 5; // 32
    ohtp.hashFn = hash_func_ascii_mod;

    HashTable<KeyType, ValueType, HashDType> openHashTable(ohtp);

    Pair<KeyType, ValueType> e1 { "./asset/1.png", ImageCont(1) };
    Pair<KeyType, ValueType> e2 { "./asset/2.pnf", ImageCont(2) }; // trying to make key with same hash (like e1) for given hash function
    Pair<KeyType, ValueType> e3 { "./asset/3.jpg", ImageCont(3) };
    Pair<KeyType, ValueType> e4 { "./asset/4.pnd", ImageCont(4) }; // same hash (like e1) for collision

    openHashTable.Place(e1);
    openHashTable.Place(e2);
    openHashTable.Place(e3);
    openHashTable.Place(e4);

    auto kvEntry = openHashTable.Retrieve("./asset/4.pnd");
    if (kvEntry)
    {
        Utils::Seperator();
        Utils::Log("Key", kvEntry->first);
        Utils::Log("Value (width)", kvEntry->second.width);
        Utils::Seperator();
    }
    else
    {
        Utils::LogMsg("Unable to find the key entry", LogLevel::INFO);
    }

    kvEntry = openHashTable.Retrieve("./asset/1.png");
    if (kvEntry)
    {
        Utils::Seperator();
        Utils::Log("Key", kvEntry->first);
        Utils::Log("Value (width)", kvEntry->second.width);
        Utils::Seperator();
    }
    else
    {
        Utils::LogMsg("Unable to find the key entry", LogLevel::INFO);
    }

    kvEntry = openHashTable.Retrieve("./asset/6.png");
    if (kvEntry)
    {
        Utils::Seperator();
        Utils::Log("Key", kvEntry->first);
        Utils::Log("Value (width)", kvEntry->second.width);
        Utils::Seperator();
    }
    else
    {
        Utils::LogMsg("Unable to find the key entry", LogLevel::INFO);
    }

    Utils::Log("Total entry by hash (16)", openHashTable.GetEntryCountByHash(16));
    Utils::Log("Total entry by key (./asset/10.png)", openHashTable.GetEntryCountByKey("./asset/10.png"));
    
    openHashTable.ClearEntries();
    Utils::Seperator();
    Utils::Log("After clear entries Total entry by hash (16)", openHashTable.GetEntryCountByHash(16));
    
    
    return 0;
}