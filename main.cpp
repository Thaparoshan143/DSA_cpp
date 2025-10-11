// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<tree/binary.cpp>

using namespace Utils;

int main()
{
    BNodePtr<int> root { GetNewBNode(100) };
    BNodePtr<int> node {};

    node = GetNewBNode<int>(10);
    root->left = node;
    node = GetNewBNode<int>(20);
    root->right = node;
    node = GetNewBNode<int>(50);
    root->right->right = node;


    Utils::LogMsg("Different Traversals", LogLevel::INFO);
    Utils::LogMsg("Pre-Order", LogLevel::MESSAGE);
    pre_order_traversal(root);
    std::cout << std::endl;

    Utils::LogMsg("In-Order", LogLevel::MESSAGE);
    in_order_traversal(root);
    std::cout << std::endl;

    Utils::LogMsg("Post-Order", LogLevel::MESSAGE);
    post_order_traversal(root);

    std::cout << std::endl;
    Seperator();

    return 0;
}