#include<iostream>
#include"linklist.h"
using namespace std;
int main()
{
	linkList<int> a, b;

	for (int i = 0; i<10; i++)a.push_back(i);
	for (int i = 20; i<30; i++)b.push_back(i);
	cout<<"线性表A：\n";
	a.traverse();
	cout<<"\n线性表B：\n";
	b.traverse();
	linkList<int> c = a + b;
	cout<<"\n线性表C：\n";
	c.traverse();
	return 0;
}
