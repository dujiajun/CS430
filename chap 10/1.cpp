#include <iostream>
using namespace std;

template <class T>
int divide(T a[], int low, int high)
{
    T k = a[low];
    do
    {
        while (low < high && a[high] >= k)
            high--;
        if (low < high)
        {
            a[low] = a[high];
            ++low;
        }
        while (low < high && a[low] <= k)
            low++;
        if (low < high)
        {
            a[high] = a[low];
            --high;
        }
    } while (low != high);
    a[low] = k;
    return low;
}

template <class T>
void QuickSort(T a[], int low, int high)
{
    if (low >= high)
        return;
    int mid = divide(a, low, high);
    QuickSort(a, low, mid - 1);
    QuickSort(a, mid + 1, high);
}

template <class T>
void QuickSort(T a[], int size)
{
    QuickSort(a, 0, size - 1);
}

template <class T>
int removeDuplication(T a[], int size)
{
    QuickSort(a, size);
    T *tmp = new T[size];
    tmp[0] = a[0];
    int k = 0;
    for (int i = 1; i < size; i++)
        if (a[i] != a[i - 1])
            tmp[++k] = a[i];
    for (int i = 0; i < k; i++)
        a[i] = tmp[i];
    delete[] tmp;
    return k + 1;
}

int main()
{
    const int N = 14;
    int a[N] = {54, 54, 54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    int newSize = removeDuplication<int>(a, N);
    for (int i = 0; i < newSize; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    return 0;
}