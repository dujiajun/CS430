#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
O(N+KlogN)的算法：
将原无序数组放进最大堆，第K次取出堆顶元素即为第K大元素。
建堆O(N)，每次取堆顶O(K)，共K次，所以一共O(N+logK)
为方便起见，使用STL里的priority_queue
*/
template <class T>
T findBigK(T a[], int size, int k)
{
    priority_queue<T, vector<T>, less<T>> q;
    for (int i = 0; i < size; i++)
        q.push(a[i]);
    for (int i = 0; i < k - 1; i++)
        q.pop();
    return q.top();
}

int main()
{
    const int N = 14;
    int a[N] = {54, 54, 54, 27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    cout<<findBigK(a,N,5);
    getchar();
    return 0;
}