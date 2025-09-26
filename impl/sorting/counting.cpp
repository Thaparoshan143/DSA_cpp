#include<includes/Types.hpp>
#include<utils/Utils.cpp>

// #Warning: This algorithm doesn't work for every number case!!
// idea is to use new array (index) to record which element exist how many times in array
// good for the elements that are closed, integral and non-negative (can be tackled, but prefered positive)
// This works best for the case where min-max of array along with other elements are very close but higher in count
// eg: 0, 2, 1, 4, 2, 3, 1, 2, 4,
// Here range: 0-4, count/size: 9
// so as long as rangehigh - rangelow < count, it is good else, excess memory usage
// to overcome negative number we can use offset based index, eg: map -num to 0..

// Complexity: O(n + k)

// if other are overloaded with [] operater, maybe can be used..
template<typename T = uint>
void counting_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    T min { Utils::GetVecMin(vec) };
    T max { Utils::GetVecMax(vec) };

    // #note: might as well use assert for negative and condition (range) to ensure not operating on random array

    Vec<int> count(max-min+1); // make count array for range low-high

    // populate count array
    for (const auto& item : vec)
    {
        count[item - min]++;
    }

    auto countSize { count.size() };
    int eleSize {}, index { 0 };

    // populate the original array now..
    if (order)
    {
        for (int i=0;i<countSize;++i)
        {
            if (count[i] == 0)
                continue;
            
            eleSize = count[i];
            while (eleSize > 0)
            {
                vec[index++] = i + min;
                eleSize--;
            }
        }
    }
    else
    {
        for (int i=countSize-1;i>=0;--i)
        {
            eleSize = count[i];
            if (count[i] == 0)
                continue;
    
            while (eleSize > 0)
            {
                vec[index++] = i + min;
                eleSize--;
            }
        }
    }
}