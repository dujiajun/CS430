#include<iostream>
using namespace std;

template<class T>
void simpleInsertSort(T a[],int size)
{
    T tmp;
    for(int j=1,k;j<size;j++)
    {
        tmp = a[j];
        for(k=j-1;tmp<a[k]&&k>=0;k--)a[k+1]=a[k];
        a[k+1]=tmp;
    }
}

int main()
{
    int a[12] = {54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    simpleInsertSort<int>(a, 12);
    for (int i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;
    getchar();
    return 0;
}