#include<includes/Types.hpp>

// Idea is select pivot element in array, then put other element left (smaller) and right (higher) in subarray, repeat this until single element/sorted
// Complexity: O(nlogn)


// this function is for partation, start, end are the index in the array..
template<typename T>
int quick_sort_helper(Vec<T>& vec, const int start, const int end, const bool order)
{
    // let's take the pivot to be always first element
    const T pivot { vec[start] };

    int i { start + 1 };
    T temp {};

    for (int j=start+1;j<=end;++j)
    {
        if (order ? vec[j] < pivot : vec[j] > pivot)
        {
            temp = vec[i];
            vec[i++] = vec[j];
            vec[j] = temp;
        }
    }

    temp = vec[i - 1];
    vec[i - 1] = pivot;
    vec[start] = temp;

    // returning index such that left contains the pivot
    return i;
}

// limitation, we can create wrapper to ensure that the passed vec size and end matches to reduce memory error (range based)
template<typename T>
void quick_sort(Vec<T>& vec, const int start, const int end, const bool order = ASCENDING)
{
    // base case
    if (start < end)
    {
        int part = quick_sort_helper(vec, start, end, order);
        quick_sort(vec, start, part - 1, order);
        quick_sort(vec, part, end, order);
    }
}
