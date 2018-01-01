#include<iostream>
using namespace std;
int qmul(int p,int k,int mod)
{
	int s = 1,tmp=p;
	while(k)
	{
		if(k%2)s = (s*(tmp%mod))%mod;
		tmp=(tmp*tmp)%mod;
		k/=2;
	}
	return s;
}
int main()
{
	int m,n,k,x;
	cin>>n>>m>>k>>x;//((m*10^k+x) mod n)
	cout<<(m*qmul(10,k,n)+x)%n;
	return 0;
}
