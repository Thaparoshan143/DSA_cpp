#include<includes/Types.hpp>


// BNode (Binary Node) aggregate..
template<typename T>
struct BNode
{
    T value {};
    BNode *left {};
    BNode *right {};
};

template<typename T>
using BNodePtr = BNode<T>*;

template<typename T>
using BNodeRef = BNode<T>&;

template<typename T>
BNodePtr<T> GetNewBNode(const T& val)
{
    BNodePtr<T> temp = new BNode<T>;
    temp->value = val;
    return temp;
}

template<typename T>
void FreeBNode(BNodePtr<T>& node)
{
    // write any other freeing logic if there is.. here.. (maybe allocator..informing..)
    delete node;
    node = nullptr;
}

/* 
There are three traversal methods:
1. Pre-order
2. In-ordedr
3. Post-order

basic implementation is as:
*/

template<typename T>
void pre_order_traversal(const BNodePtr<T> root)
{
    if (root == nullptr)
        return;

    std::cout << root->value << ", ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

template<typename T>
void in_order_traversal(const BNodePtr<T> root)
{
    if (root == nullptr)
        return;
    
    in_order_traversal(root->left);
    std::cout << root->value << ", ";
    in_order_traversal(root->right);
}

template<typename T>
void post_order_traversal(const BNodePtr<T> root)
{
    if (root == nullptr)
        return;

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    std::cout << root->value << ", ";
}