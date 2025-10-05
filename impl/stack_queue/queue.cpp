#include<includes/Types.hpp>

// basic implementation of Queue (linear/circular, but fixed capacity)
// Operations
// 1. Enqueue
// 2. Dequeue
// 3. Peek
// 4. IsEmpty
// 5. Size

// linear (one time use only) Queue
template<class T>
class LQueue
{
    public:
    // default constructor is deleted so that capacity must be known before hand (fixed size so..)
    LQueue() = delete;
    LQueue(const uint cap): m_capacity(cap) {   alloc(this, cap);   }
    ~LQueue() {  delete m_data;  }

    void Enqueue(const T& d)
    {
        // total capacity is full so no enqueue operation..
        if (m_start + m_count == m_capacity)
            return;

        this->m_data[m_start + m_count++] = d; 
    }

    T Dequeue()
    {
        // no element to dequeue
        if (m_start == m_capacity || m_count == 0)
            return T(-1);

        m_count--;
        return this->m_data[m_start++];
    }

    T Peek()
    {
        // no element to peek
        if (m_start == m_capacity || m_count == 0)
            return T(-1);

        return this->m_data[m_start];
    }

    bool IsEmpty()
    {
        return m_count == 0;
    }

    uint Size()
    {
        return m_count;
    }

    uint Capacity()
    {
        return m_capacity - m_start;
    }

    void PrintInfo()
    {
        std::cout << "Queue Cap: " << Capacity() << " || Element Count: " << Size() << "\n";
        std::cout << "Data: ";
        for (int i=0;i<m_count;++i)
        {
            std::cout << this->m_data[i+m_start] << ", ";
        }
        std::cout << std::endl;
    }

    private:
    T *m_data {};
    uint m_capacity { 1 };
    uint m_count {};
    uint m_start {};

    // since only one allocation will be done so simple 
    static void alloc(LQueue *lq, const uint cap)
    {
        lq->m_data = new T[cap];
    }
};

// reusable (circular) queue 
template<class T>
class CQueue
{
    public:
    // default constructor is deleted so that capacity must be known before hand (fixed size so..)
    CQueue() = delete;
    CQueue(const uint cap): m_capacity(cap) {   alloc(this, cap);   }
    ~CQueue() { delete m_data;  }

    void Enqueue(const T& d)
    {
        // if queue is already full then overwritten in FIFO order
        this->m_data[m_start] = d;
        m_start = (m_start + 1) % m_capacity;

        if (m_count == m_capacity)
            return;

        m_count++;
    }

    T Dequeue()
    {
        // no element to dequeue
        if (m_count == 0)
            return T(-1);

        m_count--;
        uint prev = m_start;
        m_start = (m_start + 1) % m_capacity;
        return this->m_data[prev];
    }

    T Peek()
    {
        // no element to peek
        if (m_count == 0)
            return T(-1);

        return this->m_data[m_start];
    }

    bool IsEmpty()
    {
        return m_count == 0;
    }

    uint Size()
    {
        return m_count;
    }

    uint Capacity()
    {
        return m_capacity;
    }

    // only for the circular queue to know the current position (index) of head
    uint StartPos()
    {
        return m_start;
    }

    void PrintInfo()
    {
        std::cout << "Queue Cap: " << Capacity() << " || Element Count: " << Size() << "\n";
        std::cout << "Data: ";
        for (int i=0;i<m_count;++i)
        {
            // std::cout << "Index: " << (i + m_start) % m_capacity << std::endl;
            std::cout << this->m_data[(i + m_start + (m_capacity - m_count)) % m_capacity] << ", ";
        }
        std::cout << std::endl;
    }

    private:
    T *m_data {};
    uint m_capacity { 1 };
    uint m_count {};
    uint m_start {};

    // here simple allocation as well
    static void alloc(CQueue *cq, const uint cap)
    {
        cq->m_data = new T[cap];
    }
};