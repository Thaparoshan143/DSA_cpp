// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<searching/linear.cpp>
#include<searching/binary.cpp>

using namespace Utils;

int main()
{
    Vec<uint> temp { GetNaturalNumUpto(110, DESCENDING) };
    // Vec<int> temp { GetRandomNum<int>(10, -100, 100) };
    uint ele { 25 };

    VecLog("Vector Numbers", temp);
    
    int eleIndex { binary_search(temp, ele, DESCENDING) };

    if (eleIndex != -1)
        Log("Element Index", eleIndex);
    else
        std::cout << "Element: " << ele << ", not found in array!!" << std::endl;

    return 0;
}