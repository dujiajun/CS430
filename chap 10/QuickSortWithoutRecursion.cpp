#include<iostream>
#include<stack>
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
void QuickSort(T a[],int size)
{
    stack<int> s;
    s.push(0);
    s.push(size-1);
    int low,high,mid;
    //cout<<low<<" "<<mid<<" "<<high<<endl;
    while(!s.empty())
    {
        high=s.top();
        s.pop();
        low=s.top();
        s.pop();
        //cout<<low<<" "<<mid<<" "<<high<<endl;
        mid = divide(a,low,high);
        
        if(low<mid-1)
        {
            s.push(low);
            s.push(mid-1);
        }
        if(mid+1<high)
        {
            s.push(mid+1);
            s.push(high);
        }
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