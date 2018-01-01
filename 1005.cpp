#include <iostream>
using namespace std;
int a[20][9][9], cnt[10];
void check(int n)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cnt[j] = 0;
		for (int j = 0; j < 9; j++)
			cnt[a[n][i][j]]++;
		for (int j = 1; j <= 9; j++)
		{
			if (cnt[j] != 1)
			{
				cout << "Wrong" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cnt[j] = 0;
		for (int j = 0; j < 9; j++)
			cnt[a[n][j][i]]++;
		for (int j = 1; j <= 9; j++)
		{
			if (cnt[j] != 1)
			{
				cout << "Wrong" << endl;
				return;
			}
		}
	}
	for (int p = 0; p < 3; p++)
		for (int q = 0; q < 3; q++)
		{
			for (int j = 1; j <= 9; j++)
				cnt[j] = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					cnt[a[n][p * 3 + i][q * 3 + j]]++;
			for (int j = 1; j <= 9; j++)
			{
				if (cnt[j] != 1)
				{
					cout << "Wrong" << endl;
					return;
				}
			}
		}
	cout << "Right" << endl;
}
int main()
{
	int n;
	cin >> n;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> a[k][i][j];
	for (int i = 0; i < n; i++)
		check(i);
	return 0;
}
