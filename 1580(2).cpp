#include <iostream>
using namespace std;
int stack[1000001];
int main()
{
	int n, top, temp;
	cin >> n;
	top = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&temp);
		/* 比栈顶元素大数就入栈 */
		if (temp > stack[top])
		{
			stack[++top] = temp;
		}
		else
		{
			int low = 1, high = top;
			int mid;
			/* 二分检索栈中比temp大的第一个数 */
			while(low <= high)
			{
				mid = (low + high) / 2;
				if (temp > stack[mid])
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			/* 用temp替换 */
			stack[low] = temp;
		}
	}

	/* 最长序列数就是栈的大小 */
	cout << top << endl;
	return 0;
}
