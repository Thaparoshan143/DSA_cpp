#include<includes/Types.hpp>

// The idea in this search is to divide and conquor
// Requirement: The array must be sorted for this to work, as it relies on that property
// Complexity: O(logn), here base of log is 2.

// Here, index of element in vec is returned if found, else -1
// #note: the vecOrd is argument used to deduce weather the passed vector is sorted in ASCENDING or DESCDEING order to assit search
template<typename T>
int binary_search(const Vec<T>& vec, const T& ele, const bool vecOrd = ASCENDING)
{
    int left { 0 }, right { int(vec.size()) - 1 };
    int mid { int(right / 2) }; // simply, right / 2 for first case (as, left = 0)

    // since, vecOrd is passed, incase the order is wrong we need some expression to bound max iteration to do
    // derivated from complexity of search (above..) with some threshold i.e 2 (1 for decimal value discarded, 1 for room tolerance)
    int maxIter { int(log2(right + 1)) + 2 };

    while (left != right && maxIter)
    {
        if (ele == vec[mid])
            return mid;
        else if (vecOrd ? ele < vec[mid] : ele > vec[mid])
            right = mid;
        else
            left = mid;

        mid = int((right + left) / 2);
        maxIter--;
    }

    // element not found in array.
    return -1;
}

