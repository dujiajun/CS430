#include <iostream>
using namespace std;

template <class T>
class openHashTable
{
	struct node
	{
		T data;
		node *next;
		node(const T &x)
		{
			data = x;
			next = NULL;
		}
		node() { next = NULL; }
	};

	node **array;
	int size;

	int (*key)(const T &x);
	static int defaultKey(const int &k)
	{
		return k;
	}

  public:
	openHashTable(int length = 101, int (*f)(const T &x) = defaultKey)
	{
		size = length;
		array = new node *[size];
		key = f;
		for (int i = 0; i < size; i++)
			array[i] = new node;
	}
	~openHashTable()
	{
		node *p, *q;
		for (int i = 0; i < size; i++)
		{
			p = array[i];
			do
			{
				q = p->next;
				delete p;
				p = q;
			} while (p != NULL);
		}
		delete[] array;
	}
	bool find(const T &x) const
	{
		int pos;
		node *p;
		pos = key(x) % size;
		p = array[pos]->next;
		while (p != NULL && p->data != x)
			p = p->next;
		return p != NULL;
	}
	bool insert(const T &x)
	{
		int pos;
		node *p;
		pos = key(x) % size;
		p = array[pos]->next;
		while (p != NULL && p->data != x)
			p = p->next;
		if (p == NULL)
		{
			p = new node(x);
			p->next = array[pos]->next;
			array[pos]->next = p;
			return true;
		}
		return false;
	}
	bool remove(const T &x)
	{
		int pos;
		node *p, *q;
		pos = key(x) % size;
		p = array[pos];
		while (p->next != NULL && p->next->data != x)
			p = p->next;
		if (p->next == NULL)
			return false;
		q = p->next;
		p->next = q->next;
		delete q;
		return false;
	}
};

int main()
{
	openHashTable<int> ht(100);
	for (int i = 0; i < 20; i++)
		ht.insert(i);
	for (int i = 15; i < 25; i++)
		cout << ht.find(i) << endl;
	cout << "---------------\n";
	for (int i = 17; i < 20; i++)
		ht.remove(i);
	for (int i = 15; i < 25; i++)
		cout << ht.find(i) << endl;
	return 0;
}
