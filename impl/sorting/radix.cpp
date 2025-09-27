#include<includes/Types.hpp>
#include<utils/Utils.cpp>

// main idea is using the radix/base of number system to sort.
// Complexity: O(nk)

// This mask and shift won't work for decimal as bit representation vary differently, so another method is below..
#define OCTATE_RADIX_MASK 0x07 // i.e 7
#define OCTATE_RADIX_SHIFT 3
#define HEX_RADIX_MASK 0x0f // i.e 15
#define HEX_RADIX_SHIFT 4
#define BINARY_RADIX_MASK 0b01 // i.e 1
#define BINARY_RADIX_SHIFT 1

#define ACTIVE_RADIX_MASK OCTATE_RADIX_MASK
#define ACTIVE_RADIX_SHIFT OCTATE_RADIX_SHIFT

#define DECIMAL_RADIX 10

template<typename T>
void radix_sortb(Vec<T>& vec, const bool order = ASCENDING)
{
    Vec<Vec<T>> temp {};
    T max { Utils::GetVecMax(vec) };
    int mask { ACTIVE_RADIX_MASK };
    int place { 1 };

    while((mask >> ACTIVE_RADIX_SHIFT) < max)
    {
        temp.clear();
        temp.resize(mask + 1);
        for (const auto& item : vec)
        {
            int digit { ((item & mask) >> ((place - 1) * ACTIVE_RADIX_SHIFT)) };
            if (order)
                temp[digit].push_back(item);
            else
                temp[digit].insert(temp[digit].begin(), item);
        }
    
        auto index { order ? 0 : vec.size()-1 };
        for (int i=0;i<temp.size();++i)
        {
            for (int j=0;j<temp[i].size();++j)
            {
                vec[order ? index++ : index--] = temp[i][j];
            }
        }
        mask <<= ACTIVE_RADIX_SHIFT; // shorthanded for bitshift
        place++;
    }
}

// specifically for the decimal based 
template<typename T>
void radix_sort(Vec<T>& vec, const bool order = ASCENDING)
{
    Vec<Vec<T>> temp {};
    int decimal { DECIMAL_RADIX };
    int place { 1 };

    while(true)
    {
        temp.clear();
        temp.resize(decimal + 1);
        for (const auto& item : vec)
        {
            int digit { int(item / place) % decimal };
            if (order)
                temp[digit].push_back(item);
            else
                temp[digit].insert(temp[digit].begin(), item);
        }

        // all the array now came to the zero index (i.e no more divisible)
        if (temp[0].size() == vec.size())
            break;
    
        auto index { order ? 0 : vec.size()-1 };
        for (int i=0;i<temp.size();++i)
        {
            for (int j=0;j<temp[i].size();++j)
            {
                vec[order ? index++ : index--] = temp[i][j];
            }
        }

        place *= decimal;
    }
}