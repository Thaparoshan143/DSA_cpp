// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<searching/linear.cpp>

using namespace Utils;

int main()
{
    Vec<uint> temp { GetNaturalNumUpto(15, ASCENDING) };
    // Vec<int> temp { GetRandomNum<int>(10, -100, 100) };
    uint ele { 13 };

    VecLog("Vector Numbers", temp);
    
    int eleIndex { linear_search(temp, ele, DESCENDING) };

    if (eleIndex != -1)
        Log("Element Index", eleIndex);
    else
        std::cout << "Element: " << ele << ", not found in array!!" << std::endl;

    return 0;
}