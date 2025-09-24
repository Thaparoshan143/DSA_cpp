// This file will include only the bare bone to test 

#include<utils/Log.cpp>
#include<utils/Generators.cpp>
// #include<sorting/bubble.cpp>
#include<sorting/selection.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { GetNaturalNumUpto(5, DESCENDING) };
    Vec<int> temp { GetRandomNum<int>(5, -10, 10) };

    VecLog("Previous Numbers", temp);
    
    selection_sort(temp, ASCENDING);

    VecLog("After Sort Numbers", temp);

    return 0;
}