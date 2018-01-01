#include<iostream>
#include<string>
using namespace std;
string s;
int s1 = 0,s2[1000];
int main()
{
    cout<<"请输入Pascal代码，并按Crtl+Z结束输入"<<endl;
	while(cin>>s)
	{
		if(s=="begin")s1++;
		if(s=="end")s1--;
		if(s1<0)
		{
			cout<<"Error!";
			return 0;
		}
		if(s=="if")
		{
			if(s2[s2[0]]==2)--s2[0];
			s2[++s2[0]]=1;
		}
		if(s=="then")
		{
			if(s2[s2[0]]!=1)
			{
				cout<<"Error!";
				return 0;
			}
			s2[s2[0]]=2;
		}
		if(s=="else")
		{
			if(s2[s2[0]]!=2)
			{
				cout<<"Error!";
				return 0;
			}
			s2[0]--;
		}
	}
	if(s1!=0)
	{
		cout<<"Error!";
		return 0;
	}
	if(s2[s2[0]]==1)
	{
		cout<<"Error!";
		return 0;
	}
	cout<<"Match!";
	return 0;
}
