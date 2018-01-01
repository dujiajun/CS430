#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int bfind(const int *a,const int &size,const int &b)
{
	int l = 0,r=size-1;
	int mid;
	if(b<a[l])return size;
	if(b>a[r])return 0;
	while(l<r)
	{
		mid = (l+r)/2;
		if(b>a[mid-1]&&b<a[mid])return size-mid;
		if(b>a[mid]&&b<a[mid+1])return size-mid-1;
		if(a[mid]<b)l=mid+1;
		else r=mid;
	}
	return size-l-1;
}
int main()
{
	int n,t;
	cin>>n>>t;
	int *a,b;
	a = new int[n];
	for(int i=0; i<n; i++)scanf("%d",&a[i]);
	for(int i=0; i<t; i++)
	{
		scanf("%d",&b);
		printf("%d\n",bfind(a,n,b));
	}
	return 0;
}
