#include <iostream>
using namespace std;
template <class T>
class seqQueue
{
    struct node
    {
        T data;
        node *next;
        node(const T &x, node *N = NULL)
        {
            data = x;
            next = N;
        }
        node() : next(NULL) {}
    };
    node *front, *rear;

  public:
    seqQueue()
    {
        front = rear = NULL;
    }
    ~seqQueue()
    {
        node *tmp;
        while (front != NULL)
        {
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enQueue(const T &x)
    {
        if (rear == NULL)
            front = rear = new node(x);
        else
        {
            rear->next = new node(x);
            rear = rear->next;
        }
    }
    T deQueue()
    {
        node *tmp = front;
        T value = front->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tmp;
        return value;
    }
    T getHead()
    {
        return front->data;
    }
};
int main()
{
    return 0;
}