#include "LongLongInt.h"
int LongLongInt::int_num=0;
LongLongInt::LongLongInt(const char*num)
{
	//cout<<"一般构造函数"<<num<<endl;
	int_num++;
	//cout<<"Now num="<<int_num<<endl;

	nodeCount=0;
	head=NULL;
	LinkNode *rear=NULL;
	LinkNode *p=NULL;

	int length=strlen(num);
	for(int i=length-1; i>=0; i--)
	{
		p=new LinkNode;
		p->value=num[i];
		p->next=NULL;
		nodeCount++;

		if(head==NULL)head=p;
		else rear->next=p;

		rear=p;
	}

}
void LongLongInt::print()
{
	cout<<*this;
}
LongLongInt::LongLongInt(const LongLongInt &a)
{
	//cout<<"复制构造函数"<<a<<endl;
	int_num++;
	//cout<<"Now num="<<int_num<<endl;

	nodeCount=0;
	head=NULL;
	LinkNode *rear=NULL,*p,*tmp;
	p=a.head;
	while(p!=NULL)
	{
		tmp=new LinkNode;
		tmp->value=p->value;
		tmp->next=NULL;
		nodeCount++;
		if(head==NULL)head=tmp;
		else rear->next=tmp;
		rear=tmp;
		p=p->next;
	}
}
LongLongInt::LongLongInt()
{
	//cout<<"默认构造函数"<<endl;
	nodeCount=0;
	int_num++;
	//cout<<"Now num="<<int_num<<endl;
	head=new LinkNode;
	head->next=NULL;
}
void LongLongInt::selfDelete()
{
	LinkNode *a=head,*b;
	while(a->next!=NULL)
	{
		b=a->next;
		delete a;
		a=b;
	}
}
LongLongInt::~LongLongInt()
{
	int_num--;
	//cout<<"Now num="<<int_num<<endl;
	selfDelete();
}
void LongLongInt::add(const LongLongInt &a)
{
	int more=0,sum=0,a1,b1,newCount=0;
	LinkNode *newhead=NULL,*rear=NULL,*p,*pa=head,*pb=a.head;
	while(1)
	{
		if(pa==NULL&&pb==NULL)break;
		if(pa==NULL)a1=0;
		else a1=pa->value-'0';
		if(pb==NULL)b1=0;
		else b1=pb->value-'0';

		sum=a1+b1+more;
		more=(sum>=10)?1:0;
		if(sum>=10)sum=sum-10;
		p=new LinkNode;
		p->value='0'+sum;
		p->next=NULL;
		newCount++;
		if(newhead==NULL)newhead=p;
		else rear->next=p;
		rear=p;

		if(pa!=NULL)pa=pa->next;
		if(pb!=NULL)pb=pb->next;
	}
	if(more==1)
	{
		p=new LinkNode;
		p->value='1';
		p->next=NULL;
		newCount++;
		if(newhead==NULL)newhead=p;
		else rear->next=p;
		rear=p;
	}
	selfDelete();
	head=newhead;
	nodeCount=newCount;
}
const LongLongInt LongLongInt::operator+(const LongLongInt &a)const
{
	LongLongInt tmp=*this;
	tmp.add(a);
	return tmp;
}
ostream& operator<<(ostream &os,const LongLongInt &a)
{
	int len=a.nodeCount,i=0;
	char *s=new char[len+1];
	LongLongInt::LinkNode *p=a.head;
	while(p!=NULL)
	{
		s[len-i-1]=p->value;
		i++;
		p=p->next;
	}
	s[len]='\0';
	os<<s;
	delete s; 
	return os;
}
LongLongInt& LongLongInt::operator=(const LongLongInt &a)
{
	if(this==&a)return *this;
	selfDelete();
	*this=LongLongInt(a);
	return *this;
}
