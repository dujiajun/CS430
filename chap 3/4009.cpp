#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len = s1.length();
	string ans;
	for(int i=2;i<=len;i++)
	{
		if(len%i)continue;
		int n = len/i;
		ans="";
		for(int j=0;j<len;j++)
		{
			ans+=s1[n*(j%i)+j/i];
		}
		if(ans==s2)
		{
			cout<<n;
			return 0;
		}
	} 
	cout<<"No Solution";
	return 0;
}
