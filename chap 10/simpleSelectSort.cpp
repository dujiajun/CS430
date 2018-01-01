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

int main()
{
    int a[12] = {54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    simpleSelectSort<int>(a, 12);
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    return 0;
    return 0;
}