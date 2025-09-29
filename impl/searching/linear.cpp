#include<includes/Types.hpp>

// Iterate over the array and find the search element
// Array can be sorted or unsorted
// Complexity: O(n)

// returns the index of the element in array when found, if element is not present in array then -1 is returned
// here, searchOrd only determines weather to serach vec from first to last (ASCENDING) or last to first (DESCEDNING), so doesn't have relation with arr order
template<typename T>
int linear_search(const Vec<T>& vec, const T& ele, const bool searchOrd = ASCENDING)
{
    auto vecSize { vec.size() };

    // maybe can be improved ??
    if (searchOrd)
    {
        for (int i=0;i<vecSize;++i)
        {
            if (vec[i] == ele)
                return i;
        }
    }
    else
    {
        for (int i=vecSize-1;i>=0;--i)
        {
            if (vec[i] == ele)
                return i;
        }
    }

    // failed to find the element
    return -1;
}