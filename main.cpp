// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<hash/table.cpp>

using namespace Utils;

template<typename T>
struct Transform
{
    struct Point3D {    T x {}, y {}, z {}; };

    Point3D position {}, rotation {}, scale {};
};

// temporary object to store in hash table.. hash is done by its id, .. (can also be from name)
struct Object
{
    uint id {};
    String name { "Default" };
    Transform<float> transform {};

    // simple hash overload with id based..
    // int operator%(uint rhs) const
    // {
    //     return this->id % rhs;
    // }

    // another hash overload fn (taking name and adding all the char ASCII value then finally modulo)
    int operator%(uint rhs) const
    {
        // logic to create the object hash from its identity
        uint64_t totalChar {};
        for (const auto& item : name)
        {
            totalChar += static_cast<uint64_t>(item);
        }
        return totalChar % rhs;
    }
};

void print_obj(const Object& o)
{
    Utils::Seperator();
    std::cout << "# Object Info:" << std::endl;
    std::cout << "Id: " << o.id << "\nName: " << o.name << std::endl;
    std::cout << "Position: " << o.transform.position.x << ", " << o.transform.position.y << ", " << o.transform.position.z << "\n";
    std::cout << "Rotation: " << o.transform.rotation.x << ", " << o.transform.rotation.y << ", " << o.transform.rotation.z << "\n";
    std::cout << "Scale: " << o.transform.scale.x << ", " << o.transform.scale.y << ", " << o.transform.scale.z << "\n";
    Utils::Seperator();
}

int main()
{
    HashTableProps<Object> htp {};
    htp.tableSize = TWO_POW(5);
    htp.hashFn = hash_func_mod;
    HashTable<Object> ht(htp);

    Object obj1 {}, obj2 {};
    obj2.id = 150;
    obj2.name = "Second";
    obj2.transform.scale.z = 5;
    print_obj(obj1);
    print_obj(obj2);

    auto obj1Hash = ht.Place(obj1);
    auto obj2Hash = ht.Place(obj2);

    std::cout << "Object 1 Hash: " << obj1Hash << std::endl;
    std::cout << "Object 2 Hash: " << obj2Hash << std::endl;

    auto objret = ht.Retrieve(obj1Hash);
    if (objret)
        print_obj(*objret);

    objret = ht.Retrieve(obj2Hash);
    if (objret)
        print_obj(*objret);

    ht.Remove(obj1Hash);

    objret = ht.Retrieve(obj1Hash);
    if (objret)
        print_obj(*objret);
    
    return 0;
}