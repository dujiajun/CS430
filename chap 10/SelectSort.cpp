#include <iostream>
using namespace std;

template <class T>
void simpleSelectSort(T a[], int size)
{
    int i, j, k;
    T tmp;
    for (i = 0; i < size - 1; i++)
    {
        k = i;
        for (j = i + 1; j < size; j++)
            if (a[k] > a[j])
                k = j;
        tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}

template <class T>
void percolateDown(T a[], int hole, int size)
{
    int child;
    T tmp = a[hole];
    for (; hole * 2 + 1 < size; hole = child)
    {
        child = hole * 2 + 1;
        if (child != size - 1 && a[child + 1] > a[child])
            child++;
        if (a[child] > tmp)
            a[hole] = a[child];
        else
            break;
    }
    a[hole] = tmp;
}

template <class T>
void heapSort(T a[], int size)
{
    int i;
    T tmp;
    //创建初始的堆
    for (i = size / 2; i >= 0; i--)
        percolateDown(a, i, size);
    //执行n-1次堆排序
    for (i = size - 1; i > 0; i--)
    {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp; //delete a[0]
        percolateDown(a, 0, i);
    }
}

int main()
{
    int a[12] = {54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    heapSort<int>(a, 12);
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    return 0;
}