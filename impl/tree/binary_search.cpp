// nodes and other few implementation are used from prev. impl
#include<tree/binary.cpp>

struct BSTreeConfig
{
    String name {};
    // do we require any height limit??
    // int heightLimit {};
    
    // is it required??
    // enum Order: uint8_t // previously ascending and descending defined so... small change in name..
    // {
    //     ASCEND = 0,
    //     DESCEND = 1
    // };

    // Order order {}; // ascending or descending, i.e left/right contains big/small value.. 
};

// basic implementation (or Wrapper) of Binary Search Tree
template<typename T>
class BSTree
{
    public:
    BSTree() = delete;
    BSTree(const BSTreeConfig& bctc): m_config(bctc) {  }

    bool AddBNode(BNodePtr<T> node)
    {
        if (m_root == nullptr)
        {
            m_root = node;
            return true;
        }
        // helper function
        return recursiveAdd(m_root, node);
    }

    const BNodePtr<T> GetRoot() const { return m_root;  }
    const BSTreeConfig& GetConfig() const { return m_config;    }

    private:
    BNodePtr<T> m_root {};
    BSTreeConfig m_config {};

    static bool recursiveAdd(BNodePtr<T> root, BNodePtr<T> node)
    {
        if (root->value > node->value)
        {
            if (root->left)
                return recursiveAdd(root->left, node);
            root->left = node;
            return true;
        }
        else if (root->value < node->value)
        {
            if (root->right)
                return recursiveAdd(root->right, node);
            root->right = node;
            return true;
        }
        // currently for equal case i.e root.value = node.value is not implemented.. either use else or >= in if..
        return false;
    }
};