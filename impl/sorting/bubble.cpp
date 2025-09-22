#include<includes/Types.hpp>


// essentially swap the two adjacent number until, last
// complexity : O(n^2)
// function takes the vector as reference, so original vector is directly modified;
template<typename T>
void bubble_sort(Vec<T>& vec, const bool order = ASCENDING)
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