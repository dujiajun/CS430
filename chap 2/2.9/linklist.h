#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<iostream>
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
		void remove(int i)
		{
			node *p = getAddr(i);
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			currLength--;
		}
		void push_back(const T &a)
		{
			insert(currLength - 1, a);
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
		T& visit(int i)const
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
		bool isEmpty()
		{
			return currLength==0;
		}
		~linkList()
		{
			clear();
			delete head;
			delete tail;
		}

};

#endif // LINKLIST_H_INCLUDED
