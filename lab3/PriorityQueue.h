#pragma once

#include<iostream>
#include"Food.h"

struct PriorityQueue
{
private:
    size_t count = 0;
    size_t dedicated_size = 0;
    Food* foodArray;

public:
    size_t getParent(size_t index) { return (index - 1) / 2;}

    size_t getLeftChild(size_t index) { return  index*2 + 1;}

    size_t getRightChild(size_t index) { return (index+1)*2;}

    size_t getSize() { return count; }

    bool isEmpty() { return count == 0; };

    Food top() { return foodArray[0];}

    void size_change(float size_factor);

    void siftUp(size_t index);

    void siftDown(size_t index);

    void push(Food food);

    Food pop();

    ~PriorityQueue() { delete[] foodArray; }
};
