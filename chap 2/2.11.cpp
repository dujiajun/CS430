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
	public:
		LongLongInt(const char *num);
		LongLongInt();
		LongLongInt(const LongLongInt &a);
		~LongLongInt();
		void print();
		const LongLongInt operator+(const LongLongInt &a)const;
		friend ostream& operator<<(ostream &os,const LongLongInt &a);
		friend istream& operator>>(istream &is,LongLongInt &a);
		LongLongInt& operator=(const LongLongInt &a);
};

LongLongInt::LongLongInt(const char*num)
{
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
	nodeCount=0;
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
istream& operator>>(istream &is,LongLongInt &a)
{
	string s;
	is>>s;
	a=LongLongInt(s.c_str());
	return is;
}
LongLongInt& LongLongInt::operator=(const LongLongInt &a)
{
	if(this==&a)return *this;
	selfDelete();
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
	return *this;
}

int main()
{
	LongLongInt a=LongLongInt("124"),b;
	b=a;
	cout<<"请输入大整数a:";
	cin>>a;
	cout<<"请输入大整数b:";
	cin>>b;
	LongLongInt c = a+b;
	cout<<"a+b=";
	cout<<c<<endl;
	return 0;
}

