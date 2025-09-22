#include<includes/Types.hpp>


namespace Utils
{
    Vec<uint> GetNaturalNumUpto(const uint n, const bool order = ASCENDING)
    {
        Vec<uint> temp {};
        
        for(uint i=1;i<=n;++i)
        {
            temp.push_back(order ? i : (n-i+1));
        }

        return temp;
    }

    // currently might not generate that well, pseudo random..
    template<typename T = float>
    Vec<T> GetRandomNum(const uint count, const T start = 0.0, const T end = 1.0)
    {
        srand(time(0));
        Vec<T> temp {};

        for(uint i=0;i<count;++i)
        {
            double num = double(rand()) / RAND_MAX;
            num = start + num * (end - start);
            temp.push_back(T(num));
        }

        return temp;
    }
}