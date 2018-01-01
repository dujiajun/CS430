#include <iostream>
using namespace std;

template <class T>
void Merge(T src[], T dst[], int begin, int mid, int end)
{
    int i = begin, j = mid + 1, k = begin;
    while (i <= mid && j <= end)
    {
        if (src[i] < src[j])
            dst[k++] = src[i++];
        else
            dst[k++] = src[j++];
    }
    while (i <= mid)
        dst[k++] = src[i++];
    while (j <= end)
        dst[k++] = src[j++];
}

template <class T>
void MergeSort(T a[], int size)
{
    int step = 1;
    T *tmp = new T[size];
    while (step < size)
    {

        int i = 0;
        while (i <= size - 2 * step)
        {
            int begin = i, end = i + 2 * step - 1, mid = i + step - 1;
            Merge(a, tmp, begin, mid, end);
            i += 2 * step;
        }
        if (i < size - step + 1)
            Merge(a, tmp, i, i + step - 1, size - 1);
        else
            for (int j = i; j < size; j++)
                tmp[j] = a[j];
        for (int j = 0; j < size; j++)
            a[j] = tmp[j];
        step *= 2;
    }
    delete[] tmp;
}

int main()
{
     int a[12] = {54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    MergeSort<int>(a, 12);
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    return 0;
}