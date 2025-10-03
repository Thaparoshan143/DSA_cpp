// This file will include only the bare bone to test 

#define LOG_ENABLE_DEF
#include<utils/Log.cpp>
#include<utils/Generators.cpp>
#include<utils/Utils.cpp>
#include<stack_queue/queue.cpp>

using namespace Utils;

int main()
{
    CQueue<int> temp(4);

    for (int i=0;i<7;++i)
    {
        temp.Enqueue(i+1);
    }

    temp.PrintInfo();

    Seperator();
    for (int i=0;i<2;++i)
    {
        std::cout << "Dequeue: " << temp.Dequeue() << std::endl;
    }
    
    Seperator();
    Log("Queue Peek: ", temp.Peek());
    Log("Queue Peek (check again): ", temp.Peek());
    Log("Is Queue Empty: (1/YES || 0/NO)", temp.IsEmpty());
    
    Seperator("*");
    temp.PrintInfo();
    Seperator("*");

    // overflowing the Dequeue than available as test case (can it handle?)
    temp.Dequeue();
    temp.Dequeue();
    temp.Dequeue();

    Log("Overflow (outbound) Pop check: ", temp.Dequeue());
    Log("Overflow (outbound) Peek check: ", temp.Peek());
    Log("Queue After Empty, check Cap: ", temp.Capacity());
    Log("Queue After Empty, check Element count: ", temp.Size());
    Log("Queue After Empty, check IsEmpty: ", temp.IsEmpty());
    
    // Empty Queue info
    Seperator("#");
    temp.PrintInfo();
    Seperator("#");

    // Reusing Queue for check? LQueue is generally one time use only and CQueue is reusable..
    for (int i=0;i<3;++i)
    {
        temp.Enqueue(i+10);
    }
    
    temp.PrintInfo();

    return 0;
}