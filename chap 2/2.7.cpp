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
	node* getAddr(int i)const;
public:
	linkList();
	linkList(const linkList &a);
	void clear();
	int length()const
	{
		return currLength;
	};
	void insert(int i, const T &a);
	void push_back(const T &a);
	void remove(int i);
	int search(const T &a)const;
	T visit(int i)const;
	void traverse() const;
	~linkList()
	{
		clear();
		delete head;
		delete tail;
	}
	linkList& operator+(const linkList &a);
};

template<class T>
linkList<T>::linkList()
{
	currLength = 0;
	head = new node;
	head->next = tail = new node;
	tail->prev = head;
}

template<class T>
linkList<T>::linkList(const linkList &a)
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

template<class T>
void linkList<T>::clear()
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

template<class T>
typename linkList<T>::node* linkList<T>::getAddr(int i)const
{
	if (i == -1)return head;
	node *p = head->next;
	while (i--)p = p->next;
	return p;
}

template<class T>
void linkList<T>::insert(int i, const T &a)
{
	node *p = getAddr(i);
	node *tmp = new node(a, p, p->next);
	p->next->prev = tmp;
	p->next = tmp;
	currLength++;
}

template<class T>
void linkList<T>::push_back(const T &a)
{
	insert(currLength - 1, a);

}

template<class T>
void linkList<T>::remove(int i)
{
	node *p = getAddr(i);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	currLength--;
}

template<class T>
int linkList<T>::search(const T &a)const
{
	int num = 0;
	for (node *i = head->next; i != tail; i = i->next, num++)
	{
		if (i->data == a)return num;
	}
	return -1;
}

template<class T>
T linkList<T>::visit(int i)const
{
	node *p = getAddr(i);
	return p->data;
}

template<class T>
void linkList<T>::traverse()const
{
	for (node *i = head->next; i != tail; i = i->next)
	{
		cout << i->data << endl;
	}
}

template<class T>
linkList<T>& linkList<T>::operator+(const linkList &a)
{
	for (int i = 0; i<a.length(); i++)
	{
		push_back(a.visit(i));
	}
	return *this;
}

int main()
{
	linkList<int> a, b;

	for (int i = 0; i<10; i++)a.push_back(i);
	for (int i = 20; i<30; i++)b.push_back(i);
	a.remove(0);
	a.remove(0);
	cout<<"线性表A：\n";
	a.traverse();
	cout<<"\n线性表B：\n";
	b.traverse();
	linkList<int> c = a + b;
	cout<<"\n线性表C：\n";
	c.traverse();
	return 0;
}
