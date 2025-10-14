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

    // search if the BNode exist by value in the node, upon success (i.e if found) returns BNode else nullptr
    // warning: read and write access is given, i.e can modifiy node props..
    BNodePtr<T> SearchBNodeBy(const T& val)
    {
        return recursiveSearch(m_root, val);
    }

    // for deleting, can use by node or by value (for now only by node..)
    bool DeleteBNode(BNodePtr<T> node)
    {
        if (m_root == nullptr)
            return false;
        else if (m_root == node || m_root->value == node->value)
        {
            recDelHelper(&m_root);
            return true;
        }

        // helper function
        return recursiveDelete(m_root, node);
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

    static bool recursiveDelete(BNodePtr<T> root, BNodePtr<T> node)
    {
        if (!root || (!root->left && !root->right))
            return false;

        if (root->left && root->left->value == node->value)
            return recDelHelper(&(root->left));
        else if (root->right && root->right->value == node->value)
            return recDelHelper(&(root->right));

        // if node value is greater than node value, visit only right branch
        if (root->value < node->value)
            return recursiveDelete(root->right, node);
        else
            return recursiveDelete(root->left, node);
    }

    // The node connection is the connection from parent to the node itself, i.e. either parent.left or parent.right of node
    static bool recDelHelper(BNodePtr<T>* nodeConn)
    {
        BNodePtr<T> node { *nodeConn };
        // if it is leaf node simply delete it..
        if (node->left == nullptr && node->right == nullptr)
        {
            FreeBNode(node);
            *nodeConn = nullptr;
            return true;
        }
        else if (node->left == nullptr)
        {
            BNodePtr<T> rightNode { node->right };
            FreeBNode(node);
            *nodeConn = rightNode;
            return true;
        }
        else
        {
            // here also, left node will be promoted (if exist) and right hanging branch will be joined later..
            BNodePtr<T> leftNode { node->left };
            BNodePtr<T> rightNode { node->right };
            FreeBNode(node);
            *nodeConn = leftNode;
            // now attach the right hanging branch..
            BNodePtr<T> rightMostNode { getRightmostBNode(leftNode) };
            rightMostNode->right = rightNode;
            return true;
        }
    }

    static BNodePtr<T> getLeftmostBNode(BNodePtr<T> root)
    {
        if (root->left == nullptr)
            return root;
        
        return getLeftmostBNode(root->left);
    }

    static BNodePtr<T> getRightmostBNode(BNodePtr<T> root)
    {
        if (root->right == nullptr)
            return root;
        
        return getRightmostBNode(root->right);
    }

    static BNodePtr<T> recursiveSearch(BNodePtr<T> root, const T& val)
    {
        if (root == nullptr)
            return nullptr;
        else if (root->value == val)
            return root;

        // compare value to choose left or right branch..
        if (root->value < val)
            return recursiveSearch(root->right, val);
        else
            return recursiveSearch(root->left, val);
    }
};