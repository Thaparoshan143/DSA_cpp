#include<includes/Types.hpp>


// The main idea is that we iterate over array and keep index track (greater/smaller) and swap after each iteration..
// complexity: O(n^2)

template<typename T>
void selection_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    auto vecSize { vec.size() };
    uint index { 0 };

    for (int i=0;i<vecSize;++i)
    {
        index = i;
        for(int j=i+1;j<vecSize;++j)
        {
            if(order ? vec[index] > vec[j] : vec[index] < vec[j])
            {
                index = j;
            }
        }
        
        // we can also remove this if (excessive overhead/condition) and swap (even if it means i = index)
        if(index != i)
        {
            T temp { vec[i] };
            vec[i] = vec[index];
            vec[index] = temp;
        }
    }
}