#include<includes/Types.hpp>

namespace Utils
{
    template<typename T>
    inline void Swap(T& a, T&b)
    {
        T temp { a };
        a = b;
        b = temp;
    }

    // use only in case of unsorted..
    template<typename T>
    T GetVecMin(const Vec<T>& vec)
    {
        auto vecSize { vec.size() };
        T min { vec[0] };

        for (int i=1;i<vecSize;++i)
        {
            if(vec[i] < min)
                min = vec[i];
        }

        return min;
    }

    template<typename T>
    T GetVecMax(const Vec<T>& vec)
    {
        auto vecSize { vec.size() };
        T max { vec[0] };

        for (int i=1;i<vecSize;++i)
        {
            if(vec[i] > max)
                max = vec[i];
        }

        return max;
    }

    template<typename T>
    T GetVecMinIndex(const Vec<T>& vec)
    {
        auto vecSize { vec.size() };
        T minInd { 0 };

        for (int i=1;i<vecSize;++i)
        {
            if(vec[i] < vec[minInd])
                minInd = i;
        }

        return minInd;
    }

    template<typename T>
    T GetVecMaxIndex(const Vec<T>& vec)
    {
        auto vecSize { vec.size() };
        T maxInd { 0 };

        for (int i=1;i<vecSize;++i)
        {
            if(vec[i] > vec[maxInd])
                maxInd = i;
        }

        return maxInd;
    }
}