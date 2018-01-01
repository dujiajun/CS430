#include<iostream>
using namespace std;

template<class T>
int divide(T a[],int low, int high)
{
    T k = a[low];
    do{
        while(low<high&&a[high]>=k)high--;
        if(low<high)
        {
            a[low] = a[high];
            ++low;
        }
        while(low<high&&a[low]<=k)low++;
        if(low<high)
        {
            a[high] = a[low];
            --high;
        }
    }while(low!=high);
    a[low] = k;
    return low;
}

template<class T>
void QuickSort(T a[],int low, int high)
{
    if(low>=high)return;
    int mid = divide(a,low,high);
    QuickSort(a,low,mid-1);
    QuickSort(a,mid+1,high);
}

template<class T>
void QuickSort(T a[],int size)
{
    QuickSort(a,0,size-1);
}

template<class T>
void BubbleSort(T a[],int size)
{
    bool flag;
    for(int i=1;i<size;i++)
    {
        flag = false;
        for(int j=0;j<size-i;j++)
        if(a[j+1]<a[j])
        {
            T tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            flag = 1;
        }
        if(!flag)break;
    }
}

int main()
{
    int a[12]={54,27,33,93,45,16,87,12,34,66,11,88};
    QuickSort<int>(a,12);
    for(int i=0;i<12;i++)cout<<a[i]<<" ";
    cout<<endl;
    getchar();
    return 0;
}