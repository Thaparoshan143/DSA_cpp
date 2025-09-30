#include<includes/Types.hpp>

// pre decleration only..
template<typename T>
struct LNode;

// LNode Reference typedef
template<typename T>
using LNodeRef = LNode<T>&;
// LNode Pointer typedef
template<typename T>
using LNodePtr = LNode<T>*;
// LNode Pointer Reference typedef
template<typename T>
using LNodePtrRef = LNodePtr<T>&;
// Pointer to LNode Pointer typedef (also, doubly pointer)
template<typename T>
using LNodeDbPtr = LNodePtr<T>*;

// Currently the typedef are not used in class to avoid confusion, only helper function use typedef for now..
template<typename T>
struct LNode
{
    LNode() = default;
    LNode(const T& d, LNode *n = nullptr): data(d), next(n) { }
    // by default members are public
    T data {};
    LNode<T> *next {};

    // some operator overloading for ease
    LNode<T>& operator+(LNode<T>& rhs)
    {
        // rhs.next = this->next;
        LNode<T> *current = this;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = &rhs;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const LNode<T>& ln)
    {
        os << "Own (Address): " << &ln << " || Value: " << ln.data << " || Next (Address): " << ln.next;
        return os;
    }

    LNode<T>* operator++() = delete;
    LNode<T>* operator++(int) = delete;
};


template<typename T>
LNodePtr<T> get_new_LNode(const T& d)
{
    return new LNode<T>(d);
}

template<typename T>
void traverse_print(const LNodePtr<T> root)
{
    // this can be redudant, as local copy root is already made, but in future if double pointer passed might be useful
    LNodePtr<T> current { root };
    while (current != nullptr)
    {
        std::cout << *current << std::endl;
        current = current->next;
    }
}

template<typename T>
bool insert_LNode_at(LNodePtrRef<T> root, LNodePtr<T> node, int index)
{
    // incase modify the root directly (or, insert at root)
    if (index == 0)
    {
        node->next = root;
        root = node;
        return true;
    }

    LNodePtr<T> current { root };

    // insertion will take place at given index, offseting it to +1 position
    --index;
    while (current->next != nullptr && index)
    {
        current = current->next;
        index--;
    }

    // given index out of bound for insert so failed, this could be optional, if any out bound index can be considered to link end attachement. ??
    if (index)
        return false;

    LNodePtr<T> tNext { current->next };
    current->next = node;
    node->next = tNext;

    return true;
}

template<typename T>
bool delete_LNode_at(LNodePtrRef<T> root, int index)
{
    // if root is unavailable
    if (root == nullptr)
    {
        return false;
    }

    // if only root exist and want to delete it..
    if (root->next == nullptr && index == 0)
    {
        delete root;
        root = nullptr;
        return true;
    }

    // if first, delete the root
    if (index == 0)
    {
        LNodePtr<T> prev = root;
        root = prev->next;
        delete prev;
        return true;
    }

    LNodePtr<T> current { root };
    
    --index;
    while (current->next != nullptr && index)
    {
        current = current->next;
        index--;
    }

    // no element exist.. at given index so failed to delete..
    if (index)
        return false;

    LNodePtr<T> tNext { current->next };
    current->next = tNext->next;
    delete tNext;

    return true;
}

// Major difference in delete and detach is that, node is removed (not free) from main link (root) and returned (detached node).
template<typename T>
LNodePtr<T> detach_LNode_at(LNodePtrRef<T> root, int index)
{
    // if root is unavailable
    if (root == nullptr)
    {
        return nullptr;
    }

    // if only root exist and want to detach it..
    if (root->next == nullptr && index == 0)
    {
        LNodePtr<T> prev { root };
        root = nullptr;
        return prev;
    }

    // if root, then detach..
    if (index == 0)
    {
        LNodePtr<T> prev = root;
        root = prev->next;
        return prev;
    }

    LNodePtr<T> current { root };
    --index;
    while (current->next != nullptr && index)
    {
        current = current->next;
        index--;
    }

    // no element exist.. at given index so failed to detach..
    if (index)
        return nullptr;

    LNodePtr<T> tNext { current->next };
    current->next = tNext->next;
    return tNext;
}


// make nodes from vector elements.
template<typename T>
LNodePtr<T> get_vec_LNodes(const Vec<T>& vec)
{
    if (vec.size() == 0)
        return nullptr;
    LNodePtr<T> root {}, node {}, prev {};

    root = get_new_LNode(vec[0]);
    prev = root;

    for (int i=1;i<vec.size();++i)
    {
        node = get_new_LNode(vec[i]);
        prev->next = node;
        prev = node;
    }

    return root;
}

// make vector from the nodes.. #node: the original nodes are not deleted here, if intended to delete the nodes use another helper function
template<typename T>
Vec<T> get_LNodes_vec(const LNodePtr<T> root)
{
    Vec<T> temp {};

    LNodePtr<T> current { root };

    while (current != nullptr)
    {
        temp.push_back(current->data);
        current = current->next;
    }

    return temp;
}

// Get Linear Linked List size.. (total count of nodes)
template<typename T>
int get_LNodes_count(LNodePtr<T> root)
{
    int size { 0 };

    while (root != nullptr)
    {
        size++;
        root = root->next;
    }

    return size;
}

// returns the index of node
template<typename T>
int get_LNode_index(LNodePtr<T> root, LNodePtr<T> node)
{
    int nodeInd { 0 };

    while (root != nullptr)
    {
        if (root == node)
            return nodeInd;
        root = root->next;

        nodeInd++;
    }

    return -1;
}

// This helper function can be used for cleanup, i.e free the allocated resources from new
template<typename T>
bool cleanup_LNodes(LNodePtrRef<T> root)
{
    LNodePtr<T> prev {}, current { root };

    while (current != nullptr)
    {
        prev = current;
        current = current->next;
        delete prev;
    }

    // ensure that dangling pointer don't cause scene
    root = nullptr;

    return true;
}

template<typename T>
LNodePtr<T> get_LNode_at(LNodePtr<T> root, int index)
{
    LNodePtr<T> current { root };

    while (current != nullptr && index)
    {
        current = current->next;
        index--;
    }

    if (index)
        return nullptr;

    return current;
}

// returns the node if value in node matches to argument.. (first is returned..)
template<typename T>
LNodePtr<T> get_LNode_by(LNodePtr<T> root, T& d)
{
    LNodePtr<T> current { root };

    while (current != nullptr)
    {
        if (current->data == d)
            return current;
        current = current->next;
    }

    return nullptr;
}

template<typename T>
bool rearrange_LNode(LNodePtrRef<T> root, int oldInd, int newInd)
{
    LNodePtr<T> oldNode { detach_LNode_at(root, oldInd) };

    // no node for old ind found..
    if (!oldNode)
        return false;

    bool insSuccess {};

    insSuccess = insert_LNode_at(root, oldNode, newInd);

    // if detached node is sucessfully attached in new index..
    if (insSuccess)
        return true;

    // upon failure, reattached to the oldInd (i.e. old position of detachment) #Warning: if this also fails it means, the node is dropped from main link..
    insert_LNode_at(root, oldNode, oldInd);
    
    return false;
}

// max data node returned
template<typename T>
LNodePtr<T> get_max_data_LNode(LNodePtr<T> root)
{
    LNodePtr<T> current { root };
    LNodePtr<T> maxNode { root };

    while (current != nullptr)
    {
        if (current->data > maxNode->data)
            maxNode = current;

        current = current->next;
    }

    return maxNode;
}

// min data node returned
template<typename T>
LNodePtr<T> get_min_data_LNode(LNodePtr<T> root)
{
    LNodePtr<T> current { root };
    LNodePtr<T> minNode { root };

    while (current != nullptr)
    {
        if (current->data < minNode->data)
            minNode = current;

        current = current->next;
    }

    return minNode;
}

// left to be done...
template<typename T>
void sort_LNodes(LNodePtrRef<T> root, const bool order = ASCENDING)
{
    LNodePtr<T> current { root };
    LNodePtr<T> item {};
    int itemInd {}, activeInd { 0 };
    root = nullptr; // starting with the clear link

    while (current->next != nullptr)
    {
        item = order ? get_min_data_LNode(current) : get_max_data_LNode(current);
        
        // here, not checking if itemInd is -1 as, the max is retieved from main link.. so sured..
        itemInd = get_LNode_index(current, item);
        
        detach_LNode_at(current, itemInd);
        insert_LNode_at(root, item, activeInd++);

    }
    insert_LNode_at(root, current, activeInd);
}