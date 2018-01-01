#ifndef LONG_LONG_INT
#define LONG_LONG_INT
#include<cstring>
#include<iostream>
using namespace std;
class LongLongInt
{
		struct LinkNode
		{
			char value;
			LinkNode * next;
		};
		int nodeCount;
		LinkNode *head;

		void add(const LongLongInt &a);
		void selfDelete();
		static int int_num;

	public:
		LongLongInt(const char *num);
		LongLongInt();
		LongLongInt(const LongLongInt &a);
		~LongLongInt();
		void print();
		const LongLongInt operator+(const LongLongInt &a)const;
		friend ostream& operator<<(ostream &os,const LongLongInt &a);
		LongLongInt& operator=(const LongLongInt &a);
};
#endif
