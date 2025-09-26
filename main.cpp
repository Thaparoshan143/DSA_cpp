// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<sorting/bubble.cpp>
// #include<sorting/selection.cpp>
// #include<sorting/insertion.cpp>
#include<sorting/quick.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { GetNaturalNumUpto(5, DESCENDING) };
    Vec<int> temp { GetRandomNum<int>(10, -20, 20) };

    VecLog("Previous Numbers", temp);

    quick_sort(temp, 0, temp.size() - 1, DESCENDING);

    VecLog("After Sort Numbers", temp);

    return 0;
}