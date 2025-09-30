#include<includes/Types.hpp>


// pre decleration only..
template<typename T>
struct DNode;

// DNode Reference typedef
template<typename T>
using DNodeRef = DNode<T>&;
// DNode Pointer typedef
template<typename T>
using DNodePtr = DNode<T>*;
// DNode Pointer Reference typedef
template<typename T>
using DNodePtrRef = DNodePtr<T>&;
// Pointer to DNode Pointer typedef (also, doubly pointer)
template<typename T>
using DNodeDbPtr = DNodePtr<T>*;

// Currently the typedef are not used in class to avoid confusion, only helper function use typedef for now..
template<typename T>
struct DNode
{
    DNode() = default;
    DNode(const T& d, DNode *n = nullptr, DNode *p = nullptr): data(d), next(n), prev(p) { }
    // by default members are public
    T data {};
    DNode<T> *next {};
    DNode<T> *prev {};

    // some operator overloading for ease
    DNode<T>& operator+(DNode<T>& rhs)
    {
        DNode<T> *current = this;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = &rhs;
        rhs.prev = current;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DNode<T>& ln)
    {
        os << "Own (Address): " << &ln << " || Value: " << ln.data << " || Prev (Address): " << ln.prev << " || Next (Address): " << ln.next;
        return os;
    }

    DNode<T>* operator++() = delete;
    DNode<T>* operator++(int) = delete;
};
