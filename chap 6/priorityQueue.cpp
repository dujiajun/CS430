#include <iostream>
using namespace std;
template <class T>
class priorityQueue
{
    T *array;
    int maxSize;
    int currentSize;
    void doubleSpace()
    {
        T *tmp = array;
        maxSize *= 2;
        array = new T[maxSize];
        for (int i = 0; i <= currentSize; i++)
            array[i] = array[i];
        delete[] tmp;
    }
    void buildHeap()
    {
        for (int i = currentSize / 2; i > 0; i--)
            percolateDown(i);
    }
    void percolateDown(int hole)
    {
        int child;
        T tmp = array[hole];
        for (; hole * 2 <= currentSize; hole = child)
        {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child])
                child++;
            if (array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }

  public:
    priorityQueue(const T *items, int size) : maxSize(size + 10), currentSize(size)
    {
        array = new T[size];
        for (int i = 0; i < size; i++)
            array[i + 1] = items[i];
        buildHeap();
    }
    ~priorityQueue()
    {
        delete[] array;
    }
    bool isEmpty()
    {
        return currentSize == 0;
    }
    void enQueue(const T &x)
    {
        if (currentSize == maxSize - 1)
            doubleSpace();
        int hole = ++currentSize;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = x;
    }
    T deQueue()
    {
        T minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }
    T getHead()
    {
        return array[1];
    }
};
int main()
{
    return 0;
}