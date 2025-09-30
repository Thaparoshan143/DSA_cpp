// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<linked_list/linear.cpp>

using namespace Utils;

int main()
{
    // Vec<uint> temp { Utils::GetNaturalNumUpto(2) };
    Vec<uint> temp { Utils::GetRandomNum<uint>(5, 0, 100) };
    auto root { get_vec_LNodes(temp) };
    auto node1 { get_new_LNode<uint>(10) };
    auto node2 { get_new_LNode<uint>(100) };

    *root + *node2;
    insert_LNode_at(root, node1, 0);

    traverse_print(root);
    Utils::Seperator();
    auto maxNode { get_max_data_LNode(root) };
    auto minNode { get_min_data_LNode(root) };
    std::cout << "&&& MAX Node: " << *maxNode <<  " ... || ... Index: " << get_LNode_index(root, maxNode) <<  std::endl;
    std::cout << "&&& MIN Node: " << *minNode <<  " ... || ... Index: " << get_LNode_index(root, minNode) << std::endl;
    Utils::Seperator();
    std::cout << "Opeartion Success (0, NO || 1, YES): " << rearrange_LNode(root, 0, 3) << std::endl;
    traverse_print(root);
    
    sort_LNodes(root);

    Utils::Seperator();
    traverse_print(root);
    cleanup_LNodes(root);
    Utils::Seperator();

    return 0;
}