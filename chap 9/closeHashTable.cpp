#include <iostream>
using namespace std;

template <class T>
class closeHashTable
{
  private:
	enum STATE
	{
		EMPTY,
		ACTIVE,
		DELETED
	};
	struct node
	{
		T data;
		STATE state;
		node() { state = EMPTY; }
	};
	node *array;
	int size;

	int (*key)(const T &x);
	static int defaultKey(const int &k)
	{
		return k;
	}

  public:
	closeHashTable(int length = 101, int (*f)(const T &x) = defaultKey)
	{
		size = length;
		array = new node[size];
		key = f;
	}
	~closeHashTable()
	{
		delete[] array;
	}
	bool find(const T &x) const
	{
		int initPos, pos;
		initPos = pos = key(x) % size;
		do
		{
			if (array[pos].state == EMPTY)
				return false;
			if (array[pos].state == ACTIVE && array[pos].data == x)
				return true;
			pos = (pos + 1) % size;
		} while (pos != initPos);
		return false;
	}
	bool insert(const T &x)
	{
		int initPos, pos;
		initPos = pos = key(x) % size;
		do
		{
			if (array[pos].state != ACTIVE)
			{
				array[pos].data = x;
				array[pos].state = ACTIVE;
				return true;
			}
			if (array[pos].state == ACTIVE && array[pos].data == x)
				return true;
			pos = (pos + 1) % size;
		} while (pos != initPos);
		return false;
	}
	bool remove(const T &x)
	{
		int initPos, pos;
		initPos = pos = key(x) % size;
		do
		{
			if (array[pos].state == EMPTY)
				return false;
			if (array[pos].state == ACTIVE && array[pos].data == x)
			{
				array[pos].state = DELETED;
				return true;
			}
			pos = (pos + 1) % size;
		} while (pos != initPos);
		return false;
	}

	void rehash()
	{
		node *tmp = array;
		array = new node[size];
		for (int i = 0; i < size; i++)
			if (tmp[i].state == ACTIVE)
				insert(tmp[i].data);
		delete[] tmp;
	}
};

int main()
{
	closeHashTable<int> ht(100);
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
