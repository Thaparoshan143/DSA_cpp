// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<tree/binary_search.cpp>

using namespace Utils;

// this is just temporary class implementation to illustrate the working with BST
// at minimum the BST usage based class must have <> & << operator overloaded (i.e less, greater and printing..)
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
        ComplexNum(1, 2),
        ComplexNum(2, 2)
    };

    BNodePtr<ComplexNum> node {};
    // currently not checking for error or such.. i.e return value of add node (true or false..)
    for (const auto& item: cmpNums)
    {
        node = GetNewBNode<ComplexNum>(item);
        bsTree.AddBNode(node);
    }
    
    Utils::Seperator();
    LogMsg("Pre-order traversal", LogLevel::MESSAGE);
    pre_order_traversal(bsTree.GetRoot());
    std::cout << std::endl;
    
    Utils::Seperator();
    LogMsg("In-order traversal", LogLevel::MESSAGE);
    in_order_traversal(bsTree.GetRoot());
    std::cout << std::endl;
    
    Utils::Seperator();
    LogMsg("Post-order traversal", LogLevel::MESSAGE);
    post_order_traversal(bsTree.GetRoot());
    std::cout << std::endl;
    Utils::Seperator();

    return 0;
}