#include<includes/Types.hpp>


// essentially swap the two adjacent number until, last
// complexity : O(n^2)
// function takes the vector as reference, so original vector is directly modified;
template<typename T>
void bubble_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    auto vecSize { vec.size() };
    bool swapped { false };

    for(uint i=0;i<vecSize;++i)
    {
        swapped = false;

        for(uint j=1;j<(vecSize - i);++j)
        {
            if((order ? vec[j-1] > vec[j] : vec[j-1] < vec[j]))
            {
                T temp { vec[j-1] };
                vec[j-1] = vec[j];
                vec[j] = temp;
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

// this implementation doesn't have the modified flag instead, it iterates fully even if the vec is sorted
template<typename T>
void bubble_sort2(Vec<T>& vec, const bool order = ASCENDING)
{
    auto vecSize { vec.size() };

    for(uint i=0;i<vecSize;++i)
    {
        for(uint j=1;j<(vecSize - i);++j)
        {
            if((order ? vec[j-1] > vec[j] : vec[j-1] < vec[j]))
            {
                T temp { vec[j-1] };
                vec[j-1] = vec[j];
                vec[j] = temp;
            }
        }
    }
}