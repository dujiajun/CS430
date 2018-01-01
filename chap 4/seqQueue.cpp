#include <iostream>
using namespace std;
template <class T>
class seqQueue
{
    T *elem;
    int maxSize;
    int front, rear;
    void doubleSpace()
    {
        T *tmp = elem;
        elem = new T[2 * maxSize];

        for (int i = 1; i < maxSize; i++)
            elem[i] = tmp[(front + i) % maxSize];
        front = 0;
        rear = maxSize - 1;
        maxSize *= 2;
        delete[] tmp;
    }

  public:
    seqQueue(int size = 10)
    {
        elem = new T[size];
        maxSize = size;
        front = rear = 0;
    }
    ~seqQueue()
    {
        delete [] elem;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    void enQueue(const T &x)
    {
        if ((rear + 1) % maxSize == front)
            doubleSpace();
        rear = (rear + 1) % maxSize;
        elem[rear] = x;
    }
    T deQueue()
    {
        front = (front + 1) % maxSize;
        return elem[front];
    }
    T getHead()
    {
        return elem[(front + 1) % maxSize];
    }
};
int main()
{
    return 0;
}