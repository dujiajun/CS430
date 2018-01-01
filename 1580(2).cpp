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
		/* ��ջ��Ԫ�ش�������ջ */
		if (temp > stack[top])
		{
			stack[++top] = temp;
		}
		else
		{
			int low = 1, high = top;
			int mid;
			/* ���ּ���ջ�б�temp��ĵ�һ���� */
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
			/* ��temp�滻 */
			stack[low] = temp;
		}
	}

	/* �����������ջ�Ĵ�С */
	cout << top << endl;
	return 0;
}
