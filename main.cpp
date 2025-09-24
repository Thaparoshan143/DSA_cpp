// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<sorting/bubble.cpp>
// #include<sorting/selection.cpp>
#include<sorting/insertion.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { GetNaturalNumUpto(5, DESCENDING) };
    Vec<int> temp { GetRandomNum<int>(5, -10, 10) };

    VecLog("Previous Numbers", temp);
    
    insertion_sort(temp, DESCENDING);

    VecLog("After Sort Numbers", temp);

    return 0;
}