#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
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
			node()
			{
				state = EMPTY;
			}
		};
		node *array;
		int size;

		int (*key)(const T &x);
		static int defaultKey(const int &k)
		{
			return k;
		}
		int activeCount;
	public:
		closeHashTable(int length = 101, int (*f)(const T &x) = defaultKey)
		{
			size = length;
			array = new node[size];
			key = f;
			activeCount = 0;
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
			}
			while (pos != initPos);
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
					activeCount ++;
					return true;
				}
				if (array[pos].state == ACTIVE && array[pos].data == x)
					return true;
				pos = (pos + 1) % size;
			}
			while (pos != initPos);
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
					activeCount --;
					return true;
				}
				pos = (pos + 1) % size;
			}
			while (pos != initPos);
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

		int getCurrentCount()
		{
			return activeCount;
		}
};

const int MAX_N = 100;
class Element
{

	public:

		int column;
		int row;
		int value;

		Element(int c=0,int r=0,int v=0):column(c),row(r),value(v) {}

		bool operator==(const Element &x)
		{
			return (column==x.column)&&(row==x.row)&&(value==x.value);
		}

};

int myhash(const Element &x)			//将二维矩阵的下标展开为一维形式
{
	return x.column * MAX_N + x.row;
}

int main()
{
	int t = 10;
	srand(time(NULL));

	while(t--)		//测试10次
	{
		closeHashTable<Element> ht(1001,myhash);


		for(int i=0; i<MAX_N; i++)
			for(int j=0; j<MAX_N; j++)
			{
				int r = rand() % 100;
				if(r==0)			//1%概率生成非0元素
				{
					int v = rand() % 1000 + 1;
					ht.insert(Element(i,j,v));
				}
			}
		cout<<"非0元素占比："<<ht.getCurrentCount()/100.0<<"%\n";
	}

	getchar();
	return 0;
}
