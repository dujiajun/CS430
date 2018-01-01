#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T>
class linkList
{
	private:
		struct node
		{
			T data;
			node *prev, *next;
			node(const T &a, node *p = NULL, node*n = NULL)
			{
				data = a;
				next = n;
				prev = p;
			}
			node() :next(NULL), prev(NULL) {}
			~node() {};
		};
		node *head, *tail;
		int currLength;
		node* getAddr(int i)const
		{
			if (i == -1)return head;
			node *p = head->next;
			while (i--)p = p->next;
			return p;
		}
	public:
		static const int NOT_FOUND = -1;
		linkList()
		{
			currLength = 0;
			head = new node;
			head->next = tail = new node;
			tail->prev = head;
		}
		linkList(const linkList &a)
		{
			currLength = 0;
			head = new node;
			head->next = tail = new node;
			tail->prev = head;
			for (node *i = a.head->next; i != a.tail; i = i->next)
			{
				push_back(i->data);
			}
		}
		void clear()
		{
			node *tmp;
			head->next = tail;
			tail->prev = head;
			for (node *i = head->next; i != tail; i = tmp)
			{
				tmp = i->next;
				delete i;
			}
			currLength = 0;
		}
		int length()const
		{
			return currLength;
		};
		void insert(int i, const T &a)
		{
			node *p = getAddr(i);
			node *tmp = new node(a, p, p->next);
			p->next->prev = tmp;
			p->next = tmp;
			currLength++;
		}
		void push_back(const T &a)
		{
			insert(currLength - 1, a);
		}
		void remove(int i)
		{
			node *p = getAddr(i);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			currLength--;
		}
		int search(const T &a)const
		{
			int num = 0;
			for (node *i = head->next; i != tail; i = i->next, num++)
			{
				if (i->data == a)return num;
			}
			return -1;
		}
		T visit(int i)const
		{
			node *p = getAddr(i);
			return p->data;
		}
		void traverse() const
		{
			for (node *i = head->next; i != tail; i = i->next)
			{
				cout << i->data << endl;
			}
		}
		~linkList()
		{
			clear();
			delete head;
			delete tail;
		}
		linkList& operator+(const linkList &a)
		{
			for (int i = 0; i<a.length(); i++)
			{
				push_back(a.visit(i));
			}
			return *this;
		}
		linkList& operator=(const linkList &a)
		{
			currLength = 0;
			head = new node;
			head->next = tail = new node;
			tail->prev = head;
			for (node *i = a.head->next; i != a.tail; i = i->next)
			{
				push_back(i->data);
			}
		}
};

template<class T>
class Set
{
		linkList<T> arr;
	public:
		Set() {}
		Set(const Set &a):arr(a.arr)
		{
			//arr = a.arr;
		}
		~Set() {}
		insert(T &a)
		{
			if(arr.search(a)==-1)
			{
				arr.push_back(a);
			}
		}
		Set operator+(Set &a)
		{
			Set tmp = *this;
			for(int i = 0; i<a.arr.length(); i++)
			{
				T data = a.arr.visit(i);
				if(arr.search(data)==-1)
				{
					tmp.arr.push_back(data);
				}
			}
			return tmp;
		}
		Set operator*(Set &a)
		{
			Set tmp;
			for(int i = 0; i<a.arr.length(); i++)
			{
				T data = a.arr.visit(i);
				if(arr.search(data)!=-1)
				{
					tmp.arr.push_back(data);
				}
			}
			return tmp;
		}
		Set operator-(Set &a)
		{
			Set tmp;
			for(int i = 0; i<arr.length(); i++)
			{
				T data = arr.visit(i);
				if(a.arr.search(data)==-1)
				{
					tmp.arr.push_back(data);
				}
			}
			return tmp;
		}
		void traverse()
		{
			for(int i = 0; i<arr.length(); i++)
			{
				cout<<arr.visit(i)<<" ";
			}
			cout<<endl;
		}
		bool find(T a)
		{
			int addr = arr.search(a);
			if(addr!=-1)
			{
				if(addr==0)return true;
				
				T tmp1 = arr.visit(0);
				T tmp2 = arr.visit(addr);
				arr.remove(0);
				arr.insert(-1,tmp2);
				arr.remove(addr);
				arr.insert(addr,tmp1);
				return true;
			}
			return false;
		}
};
int main()
{
	Set<int> set1;
	for(int i=1; i<=10; i++)set1.insert(i);

	set1.find(6);
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
