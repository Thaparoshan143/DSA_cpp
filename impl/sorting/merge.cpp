#include<includes/Types.hpp>
#include<utils/Utils.cpp>

// basic idea is to divide and conquer
// we sub divide the array, (keep on subdividing) until its one/two, then sort it (for two), then recombine smaller sorted into one combined (also, in sorted form)
// Complexity: O(n.logn)
// Important Note: Actual implementation of merge sort seems to be little different than done here.
// Below implementation, use little different logic in end, but the idea remains same, to divide and sort in small subset, with in order join in merge

template<typename T>
void merge_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    auto vecSize { vec.size() };
    if (vecSize == 1)
        return;
    else if (vecSize == 2)
    {
        // basic sort logic
        if (order ? vec[0] < vec[1] : vec[0] > vec[1])
            return;

        T temp { vec[0] };
        vec[0] = vec[1];
        vec[1] = temp;

        return;
    }

    int half { int(vecSize / 2) };
    Vec<T> left(vec.begin(), vec.begin() + half);
    Vec<T> right(vec.begin() + half, vec.begin() + vecSize);

    merge_sort(left, order);
    merge_sort(right, order);

    int leftInd { 0 }, rightInd { 0 }, vecInd { 0 };
    while (vecInd < vecSize)
    {
        // little complex expression, can be shortend with nested 
        if (((order ? left[leftInd] < right[rightInd] : left[leftInd] > right[rightInd]) && leftInd < left.size()) || rightInd >= right.size())
        {
            vec[vecInd++] = left[leftInd++];
        }
        else
        {
            vec[vecInd++] = right[rightInd++];
        }
    }
}
