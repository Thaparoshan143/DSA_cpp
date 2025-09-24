#include<includes/Types.hpp>
// The main idea is array, divide into two array (sorted & unsorted, more specifically, two portion) and start to add into sort array in order.
// Complexity: O(n^2)

template<typename T>
void insertion_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    auto vecSize { vec.size() };
    uint index { 0 };
    T currentVal {};

    for (int i=1;i<vecSize;++i)
    {
        index = i;
        currentVal = vec[i];

        for (int j=i-1;j>=0;--j)
        {
            if (order ? currentVal < vec[j] : currentVal > vec[j])
            {
                vec[j+1] = vec[j];
                index = j;
            }
            else
                break;
        }

        vec[index] = currentVal;
    }
}