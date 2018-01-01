#include <iostream>
using namespace std;
void todo()
{
	int n, m;
	cin >> n >> m;
	int *s2 = new int[n];
	int *tmp = new int[n];
	int top = -1, flag = 0;
	for (int i = 0; i < n; i++)
		cin >> s2[i];
	for (int i = 0, j = 0; i < n; i++)
	{
		tmp[++top] = i;
		/*{
			cout<<"i="<<i<<" TMP:";
			for(int k=0;k<=top;k++)cout<<tmp[k]<<" ";
			cout<<endl;
		}*/
		if (top > m)
		{
			cout << "NO" << endl;
			flag = 1;
			break;
		}
		while (tmp[top] == s2[j] && j < n)
		{
			top--;
			j++;
		}
	}
	if (!flag)
	{
		if (top != -1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	delete[] s2;
	delete[] tmp;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		todo();
	}
	return 0;
}
