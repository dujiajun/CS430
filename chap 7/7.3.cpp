#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<class T>
class Set
{
		vector<T> arr;
	public:
		Set() {}
		Set(const Set &a)
		{
			arr = a.arr;
		}
		~Set() {}
		insert(T &a)
		{
			if(find(arr.begin(),arr.end(),a)==arr.end())
			{
				arr.push_back(a);
			}
		}
		Set operator+(Set &a)
		{
			Set tmp = *this;
			for(typename vector<T>::iterator i = a.arr.begin(); i<a.arr.end(); i++)
			{
				if(find(tmp.arr.begin(),tmp.arr.end(),*i)==tmp.arr.end())
				{
					tmp.arr.push_back(*i);
				}
			}
			return tmp;
		}
		Set operator*(Set &a)
		{
			Set tmp;
			for(typename vector<T>::iterator i = a.arr.begin(); i<a.arr.end(); i++)
			{
				if(find(this->arr.begin(),this->arr.end(),*i)!=this->arr.end())
				{
					tmp.arr.push_back(*i);
				}
			}
			return tmp;
		}
		Set operator-(Set &a)
		{
			Set tmp;
			for(typename vector<T>::iterator i = this->arr.begin(); i<this->arr.end(); i++)
			{
				if(find(a.arr.begin(),a.arr.end(),*i)==a.arr.end())
				{
					tmp.arr.push_back(*i);
				}
			}
			return tmp;
		}
		void traverse()
		{
			for(typename vector<T>::iterator i = this->arr.begin(); i<this->arr.end(); i++)
			{
				cout<<*i<<" ";
			}
			cout<<endl;
		}
};
int main()
{
	Set<int> set1;
	for(int i=1; i<=10; i++)set1.insert(i);
	//for(int i=1; i<=10; i++)set1.insert(i);
	set1.traverse();
	Set<int> set2;
	for(int i=5; i<=15; i++)set2.insert(i);
	Set<int> set3 = set1+set2;
	Set<int> set4 = set1*set2;
	Set<int> set5 = set1-set2;
	set3.traverse();
	set4.traverse();
	set5.traverse();
	return 0;
}
