#include<includes/Types.hpp>


// pre decleration only..
template<typename T>
struct CNode;

// CNode Reference typedef
template<typename T>
using CNodeRef = CNode<T>&;
// CNode Pointer typedef
template<typename T>
using CNodePtr = CNode<T>*;
// CNode Pointer Reference typedef
template<typename T>
using CNodePtrRef = CNodePtr<T>&;
// Pointer to CNode Pointer typedef (also, doubly pointer)
template<typename T>
using CNodeDbPtr = CNodePtr<T>*;

// Currently the typedef are not used in class to avoid confusion, only helper function use typedef for now..
template<typename T>
struct CNode
{
    CNode() = default;
    CNode(const T& d, CNode *n = this): data(d), next(n) { }
    // by default members are public
    T data {};
    CNode<T> *next {};

    // some operator overloading for ease
    CNode<T>& operator+(CNode<T>& rhs)
    {
        CNode<T> *root = this;
        CNode<T> *current = this->next;

        while (current->next != root)
        {
            current = current->next;
        }

        current->next = &rhs;
        rhs.next = root;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const CNode<T>& ln)
    {
        os << "Own (Address): " << &ln << " || Value: " << ln.data << " || Next (Address): " << ln.next;
        return os;
    }

    CNode<T>* operator++() = delete;
    CNode<T>* operator++(int) = delete;
};
