#include<cstring>
#include<iostream>
#include"longlongint.h"
using namespace std;
int main()
{
	LongLongInt a=LongLongInt("124"),b;
	b=a;
	cout<<"�����������a:";
	cin>>a;
	cout<<"�����������b:";
	cin>>b;
	LongLongInt c = a+b;
	cout<<"a+b=";
	cout<<c<<endl;
	return 0;
}
