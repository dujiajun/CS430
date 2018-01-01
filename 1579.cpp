#include<iostream>
using namespace std;
int f[1001][1001];
char a[1001];
char b[1001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++)cin>>b[j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(a[i]==b[j])f[i][j]=f[i-1][j-1]+1; 
	else f[i][j]=max(f[i-1][j],f[i][j-1]); 
	cout<<f[n][m];
	return 0;
}
