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

    template<typename T>
    inline bool CondSwap(T& a, T& b, const CompareCallback<T>& compare)
    {
        if (compare(a, b))
            Swap(a, b);
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

    // take the original vector and return new vector (sub vector) from given index to end
    template<typename T>
    inline Vec<T> GetSubVec(const Vec<T>& vec, const int start, const int end)
    {
        return Vec<T>(vec.begin() + start, vec.begin() + end);
    }

    // will return ASCENDING (1) or DESCENDING (0) if are in sorted order, else -1 if unsorted
    template<typename T>
    inline int IsVecSorted(const Vec<T>& vec)
    {
        auto vecSize { vec.size() };
        int activeInd { 0 };

        // if few elements are same, skip them..
        while (activeInd < vecSize)
        {
            if (vec[activeInd] != vec[activeInd + 1])
                break;

            activeInd++;
        }

        if (++activeInd == vecSize)
            return ASCENDING; // case when all the vector value are same.. random choice of ASCENDING

        // ascending test...
        if (vec[activeInd] < vec[activeInd + 1])
        {
            while (++activeInd < vecSize)
            {
                if (vec[activeInd - 1] > vec[activeInd])
                    return -1;
            }
            return ASCENDING;
        }
        else
        {
            while (++activeInd < vecSize)
            {
                if (vec[activeInd - 1] < vec[activeInd])
                    return -1;
            }

            return DESCENDING;
        }

        // vec is unsorted..
        return -1;
    }
}