#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
O(NlogK)的算法：
建立最小二叉堆存放前K大的数，
遍历原数组，如果当前访问到的元素比堆顶元素大，就取出堆顶，并把当前元素加进堆里。
保持二叉堆总成员为K，最后取出堆顶元素即为第K大。
每次操作堆O(logK)，最多N次，固O(NlogK)。
为方便起见，使用STL里的priority_queue
*/
template <class T>
T findBigK(T a[], int size, int k)
{
    priority_queue<T, vector<T>, greater<T>> q;
    for (int i = 0; i < size; i++)
        if (q.size() < k)
            q.push(a[i]);
        else if (q.top() < a[i])
        {
            q.pop();
            q.push(a[i]);
        }
    return q.top();
}

int main()
{
    const int N = 11;
    int a[N] = {27, 33, 93, 45, 16, 87, 12, 34, 66, 11, 88};
    cout << findBigK(a, N, 5);
    getchar();
    return 0;
}