#include <iostream>
#include<string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <queue>

#include"Food.h"
#include"PriorityQueue.h"

using namespace std;

template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue);

bool testPriorityQueue();

int main()
{
    testPriorityQueue();

    return 0;
}


template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue)
{
    const int iters = 100000;
    clock_t timeStart = clock();
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            priorityQueue.push(Food());
        }
        priorityQueue.top();
        priorityQueue.pop();
    }
    clock_t timeEnd = clock();
    float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return time;
}

bool testPriorityQueue()
{
    srand(time(NULL));
    const int iters = 20000;
    PriorityQueue myPriorQueue;
    priority_queue<Food> stlPriorQueue;
    bool isDataEqual = true;
    for (int i = 0; i < iters; i++)
    {
        int insertDataAmount = rand() % 6 + 5;
        for (int j = 0; j < insertDataAmount; j++)
        {
            Food randData = Food();
            myPriorQueue.push(randData);
            stlPriorQueue.push(randData);
        }
        if (!(myPriorQueue.top() == stlPriorQueue.top()))
        {
            isDataEqual = false;
            cerr << "Comparing failed on iteration " << i << endl
                << endl;
            break;
        }
        int removeDataAmount = rand() % insertDataAmount;
        for (int j = 0; j < removeDataAmount; j++)
        {
            myPriorQueue.pop();
            stlPriorQueue.pop();
        }
    }
    int myQueueSize = myPriorQueue.getSize();
    int stlQueueSize = stlPriorQueue.size();
    float stlTime =
        testPriorityQueueSpeed<priority_queue<Food>>(priority_queue<Food>());
    float myTime = testPriorityQueueSpeed<PriorityQueue>(PriorityQueue());
    cout << "My PriorityQueue:" << endl;
    cout << "Time: " << myTime << ", count: " << myQueueSize << endl;
    cout << "STL priority_queue:" << endl;
    cout << "Time: " << stlTime << ", count: " << stlQueueSize << endl
        << endl;
    if (isDataEqual && myQueueSize == stlQueueSize)
    {
        cout << "The lab is completed" << endl
            << endl;
        return true;
    }
    cerr << ":(" << endl
        << endl;
    return false;
}