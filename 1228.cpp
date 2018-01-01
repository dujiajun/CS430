#include <iostream>
using namespace std;

const int MAX_N = 401;
long long a[MAX_N][MAX_N], sum[MAX_N][MAX_N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];

    long long f[MAX_N] = {0};
    long long sumf = 0, sumg = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if ((sum[j][k] - sum[i - 1][k] - sum[j][k - 1] + sum[i - 1][k - 1]) % 2)
                    f[k] = (k - 1 - f[k - 1]) + 1;
                else
                    f[k] = f[k - 1];
            }
            for (int k = 1; k <= n; k++)
            {
                sumf += f[k];
                sumg += k - f[k];
            }
        }
    cout << sumf << " " << sumg << endl;
    return 0;
}