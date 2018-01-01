#include <iostream>
using namespace std;

template <class T>
void merge(T a[], int left, int mid, int right)
{
    T *tmp = new T[right - left + 1];
    int i = left, j = mid, k = 0;
    while (i < mid && j <= right)
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];

    while (i < mid)
        tmp[k++] = a[i++];
    while (j <= right)
        tmp[k++] = a[j++];

    for (int i = 0, k = left; k <= right;)
        a[k++] = tmp[i++];
    delete[] tmp;
}

template <class T>
void MergeSort(T a[], int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right)
        return;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    merge(a, left, mid + 1, right);
}

template <class T>
void MergeSort(T a[], int size)
{
    MergeSort(a, 0, size - 1);
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