#include"PriorityQueue.h"

void PriorityQueue::size_change(float size_factor)
{

    dedicated_size = size_t(dedicated_size * size_factor);

    Food* newQueue = new Food[dedicated_size];

    memcpy(newQueue, foodArray, count *sizeof(Food));

    delete[] foodArray;

    foodArray = newQueue;
}

void PriorityQueue::siftUp(size_t index)
{
    if (foodArray[getParent(index)] < foodArray[index] && index != 0)
    {
        std::swap(foodArray[index], foodArray[getParent(index)]);
        siftUp(getParent(index));
    }
}

void PriorityQueue::siftDown(size_t index)
{
    size_t left_child = getLeftChild(index);
    size_t index_search = index;
    size_t right_child = getRightChild(index);

    if (right_child < count && foodArray[index_search] < foodArray[right_child])
    {
        index_search = right_child;
    }

    if (left_child < count && foodArray[index_search] < foodArray[left_child])
    {
        index_search = left_child;
    }

    if (index_search != index)
    {
        std::swap(foodArray[index], foodArray[index_search]);
        siftDown(index_search);
    }
}

void PriorityQueue::push(Food food)
{
    if (!count)
    {
        foodArray = new Food[++dedicated_size];
        foodArray[count++] = food;

        return;
    }

    if (count == dedicated_size)
    {
        size_change(2);
    }
        
    foodArray[count++] = food;
    siftUp(count - 1);
}

Food PriorityQueue::pop()
{
    if (!count)
    {
        std::cout << "ERROR!!! Out of range!" << std::endl;
        return Food(-1, -1, -1);
    }

    std::swap(foodArray[0], foodArray[--count]);
    siftDown(0);

    return foodArray[0];
}