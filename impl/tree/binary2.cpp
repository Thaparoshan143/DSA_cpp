#include<includes/Types.hpp>

// this is just small modified BNode, i.e it contains one more field (parent)
// the main idea here is to make two way, i.e child to parent & parent to child traversal possible..
// It just contains the class decleration for now..

// Two way BNode (Binary Node) aggregate..
template<typename T>
struct BNode2
{
    T value {};
    BNode2 *parent {}; // addition from normal one..
    BNode2 *left {};
    BNode2 *right {};
};