// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<tree/binary_search.cpp>

using namespace Utils;

// this is just temporary class implementation to illustrate the working with BST
// at minimum the BST usage based class must have <> == & << operator overloaded (i.e less, greater and printing..)
class ComplexNum
{
    public:
    ComplexNum() = default;
    ComplexNum(double r, double i): m_real(r), m_img(i) {   }

    bool operator<(const ComplexNum& rhs)
    {
        // for now comparing the magnitude only..
        return this->GetMagnitude() < rhs.GetMagnitude();
    }

    bool operator>(const ComplexNum& rhs)
    {
        // for now comparing the magnitude only..
        return this->GetMagnitude() > rhs.GetMagnitude();
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNum& cn)
    {
        // os << "Real part: " << cn.m_real << " || Imaginary Part: " << cn.m_img;
        os << cn.m_real << "+" << cn.m_img << "j(" << cn.GetMagnitude() << ")";
        return os;
    }

    bool operator==(const ComplexNum& rhs)
    {
        return (this->m_real == rhs.m_real && this->m_img == rhs.m_img);
    }

    double GetMagnitude() const {   return getMag(*this);   }

    private:
    double m_real {}, m_img {};

    static double getMag(const ComplexNum& num)
    {
        return sqrt(pow(num.m_real, 2) + pow(num.m_img, 2));
    }
};

int main()
{
    BSTreeConfig bstConfig {};
    bstConfig.name = "First BSTree";

    BSTree<ComplexNum> bsTree(bstConfig);
    Vec<ComplexNum> cmpNums = {
        ComplexNum(1, 1),
        ComplexNum(1, 0),
        ComplexNum(0, 3),
        // ComplexNum(1, 2),
        // ComplexNum(2, 2),
        ComplexNum(2, 5),
    };

    BNodePtr<ComplexNum> node {};
    // currently not checking for error or such.. i.e return value of add node (true or false..)
    for (const auto& item: cmpNums)
    {
        node = GetNewBNode<ComplexNum>(item);
        bsTree.AddBNode(node);
    }
    

    Utils::Seperator();
    LogMsg("In-order traversal (before delete)", LogLevel::MESSAGE);
    in_order_traversal(bsTree.GetRoot());
    std::cout << std::endl;
    Utils::Seperator();

    auto searchNode = bsTree.SearchBNodeBy(ComplexNum(0, 3));
    if (searchNode)
        std::cout << "Found the node with value: " << searchNode->value << " || at add: " << searchNode << " || node left add: " << searchNode->left << " || node right add: " << searchNode->right << std::endl;
    else
        Utils::LogMsg("Unable to find for given search value in tree", LogLevel::ERROR);

    // trying to delete node (exisiting, root,) and also other non-existing to see its behaviour..
    // warning: this is temporary usages.. the new allocated block are not freed here..
    bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(0, 3)));
    bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(1, 2)));
    // bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(1, 1)));
    bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(1, 0)));
    bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(2, 2)));
    // bsTree.DeleteBNode(GetNewBNode<ComplexNum>(ComplexNum(2, 5)));

    LogMsg("In-order traversal (after delete)", LogLevel::MESSAGE);
    in_order_traversal(bsTree.GetRoot());
    std::cout << std::endl;
    Utils::Seperator();

    return 0;
}