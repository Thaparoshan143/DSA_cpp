#include<includes/Types.hpp>

// basic implementation of Stack
// Permitted Operations/Methods
// 1. Push
// 2. Pop
// 3. Peek
// 4. IsEmpty
// 5. Size

template<typename T>
class Stack
{
    public:
    Stack() {   }
    Stack(const uint cap): m_capacity(cap) {    } // early allocation is not done, can be configed via alloc function at initialization if required.. (eg: alloc(this, cap) or checkState())

    void Push(const T& d)
    {
        checkState();
        this->m_data[m_count++] = d;
    }

    T Pop()
    {
        // currently log is not included for no element Pop operation, maybe through error?
        if (IsEmpty())
            return T(-1);
        checkState();
        return this->m_data[--m_count];
    }

    T Peek()
    {
        // currently log is not included for no element Peek operation as well
        if (IsEmpty())
            return T(-1);
        return this->m_data[m_count-1];
    }

    bool IsEmpty()
    {
        return this->m_count == 0;
    }

    uint Size()
    {
        return this->m_count;
    }

    uint Capacity()
    {
        return this->m_capacity;
    }

    void PrintInfo()
    {
        std::cout << "Stack Cap: " << this->m_capacity << " || Element Count: " << this->m_count << "\n";
        std::cout << "Data: ";
        for (int i=this->m_count-1;i>=0;--i)
        {
            std::cout << this->m_data[i] << ", ";
        }
        std::cout << std::endl;
    }

    private:
    T *m_data {};
    uint m_capacity { 1 }; 
    uint m_count {};

    static void alloc(Stack *old, uint newCap)
    {
        T *prev = old->m_data;
        old->m_data = new T[newCap];

        if (prev != nullptr)
        {
            // memcpy not working for manual run for now..
            for (int i=0;i<old->m_count;++i)
            {
                old->m_data[i] = prev[i];
            }
            delete prev;
        }

        old->m_capacity = newCap;
    }


    void checkState()
    {
        // Capacity are adjusted in the power of 2 for ease i.e bitshift.. with initial starting as 2..
        // grow or create the new space
        if (this->m_count == this->m_capacity || this->m_data == nullptr)
        {
            alloc(this, (this->m_capacity << 1));
        }
        // incase the shrink is required
        else if (this->m_count < (this->m_capacity >> 1))
        {
            alloc(this, (this->m_capacity >> 1));
        }
    }
};