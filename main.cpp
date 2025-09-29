// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>

using namespace Utils;

int main()
{
    Vec<uint> temp { Utils::GetVecWithDupVal<uint>(2, 4) };

    VecLog("Vector Numbers", temp);

    std::cout << "Is sorted (DESC: 0/ASC: 1/UNSORT: -1): " << Utils::IsVecSorted(temp) << std::endl;

    return 0;
}