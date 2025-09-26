// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<sorting/bubble.cpp>
// #include<sorting/selection.cpp>
// #include<sorting/insertion.cpp>
// #include<sorting/quick.cpp>
#include<sorting/counting.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { GetNaturalNumUpto(5, DESCENDING) };
    Vec<int> temp { GetRandomNum<int>(20, 10, 20) };

    VecLog("Previous Numbers", temp);
    
    counting_sort(temp, ASCENDING);

    VecLog("After Sort Numbers", temp);

    return 0;
}