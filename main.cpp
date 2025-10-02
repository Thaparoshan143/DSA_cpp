// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<stack_queue/stack.cpp>

using namespace Utils;

int main()
{
    Stack<int> temp {};

    for (int i=0;i<5;++i)
    {
        temp.Push(i+1);
    }

    temp.PrintInfo();

    Seperator();
    for (int i=0;i<2;++i)
    {
        std::cout << "Popped: " << temp.Pop() << std::endl;
    }
    
    Seperator();
    Log("Stack Peek: ", temp.Peek());
    Log("Stack Peek (check again): ", temp.Peek());
    Log("Is Stack Empty: (1/YES || 0/NO)", temp.IsEmpty());
    
    Seperator("*");
    temp.PrintInfo();
    Seperator("*");

    // overflowing the Pop than available as test case (can it handle?)
    temp.Pop();
    temp.Pop();
    temp.Pop();

    Log("Overflow (outbound) Pop check: ", temp.Pop());
    Log("Overflow (outbound) Peek check: ", temp.Peek());
    Log("Stack After Empty, check Cap: ", temp.Capacity());
    Log("Stack After Empty, check Element count: ", temp.Size());
    Log("Stack After Empty, check IsEmpty: ", temp.IsEmpty());
    
    // Empty Stack info
    Seperator("#");
    temp.PrintInfo();
    Seperator("#");
    // Reusing Stack for check
    for (int i=0;i<3;++i)
    {
        temp.Push(i+1);
    }
    
    temp.PrintInfo();

    return 0;
}