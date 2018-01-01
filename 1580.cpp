#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
int s[1000001];
int main()
{
	int n, a, top = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if (s[top] < a)
			s[++top] = a;
		else
		{
			int l = 1, r = top, mid = 0;
			while (l <= r)
			{
				mid = (l + r) / 2;
				if (s[mid] < a)
					l = mid + 1;
				else
					r = mid - 1;
			}
			if (mid)
				s[l] = a;
		}
	}
	cout << top << endl;
	return 0;
}
