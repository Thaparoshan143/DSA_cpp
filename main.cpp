// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<sorting/bubble.cpp>
// #include<sorting/selection.cpp>
// #include<sorting/insertion.cpp>
// #include<sorting/quick.cpp>
// #include<sorting/counting.cpp>
#include<sorting/radix.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { GetNaturalNumUpto(5, DESCENDING) };
    Vec<int> temp { GetRandomNum<int>(20, 10, 100) };

    VecLog("Previous Numbers", temp);
    
    radix_sort(temp, DESCENDING);

    VecLog("After Sort Numbers", temp);

    return 0;
}