#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
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

linkList<string> lines;

void open(istream &in)
{
	if(!lines.isEmpty())
	{
		cout<<"Error:����quit��"<<endl;
		return;
	}
	string line;
	while (getline(in, line))
	{
		lines.push_back(line);
	}
	cout<<"����ɹ����ļ���"<<lines.length()<<"�У�\n"; 
}
void quit(ostream &out)
{
	for (int i = 0; i<lines.length(); i++)
	{
		out << lines.visit(i) << endl;
	}
	lines.clear();
	cout<<"�ѽ��ı�д���ļ����˳�ϵͳ��\n"; 
}
void getlist(int n1, int n2)
{
	if(n1-1<0||n2>lines.length())
	{
		cout<<"Error!"<<endl;
		return;
	}
	for (int i = n1 - 1; i <= n2 - 1; i++)
	{
		cout << lines.visit(i) << endl;
	}
}
void del(int col, int row, int num)
{
	if (col > lines.length() || col <= 0)
	{
		cout << "Error!" << endl;
		return;
	}
	string *tmp = &lines.visit(col - 1);
	if (row > tmp->length() || row <= 0)
	{
		cout << "Error!" << endl;
		return;
	}
	tmp->erase(row - 1, num);
	cout<<"�ѳɹ���ɲ�����\n"; 
}
void ins(int col, int row, string text)
{
	if (col > lines.length() || col <= 0)
	{
		cout << "Error!" << endl;
		return;
	}
	string *tmp = &lines.visit(col - 1);
	if (row > tmp->length() || row <= 0)
	{
		cout << "Error!" << endl;
		return;
	}
	tmp->insert(row - 1, text);
	cout<<"�ѳɹ���ɲ�����\n"; 
}
int main()
{
	ifstream fin;
	ofstream fout;
	string cmd;
	string filename = "";
	cout<<"��ӭ�����б༭ϵͳ����ϵͳ�ṩ5�����\n"
			<<"  open [filename]����ָ���ļ�����ϵͳ��\n"
			<<"  quit�������ڱ༭���ļ�д���ļ����˳�ϵͳ��\n"
			<<"  list [n1]-[n2]����ʾ��n1-n2�е����ݣ�\n"
			<<"  del [col] [row] [n]���ӵ�col�е�row�п�ʼɾȥn���ַ���\n"
			<<"  ins [col] [row] [text]���ڵ�col�е�row�в����ַ���text��\n"
			<<"��������Ĳ���:\n";
	while (1)
	{
		cin >> cmd;
		if (cmd == "open")
		{
			cin >> filename;
			fin.open(filename.c_str());
			open(fin);
		}
		else if (cmd == "quit")
		{
			if (filename != "")
			{
				fout.open(filename.c_str());
				quit(fout);
				break;
			}
		}
		else if (cmd == "list")
		{
			int n1, n2;
			cin >> n1;
			cin.get();
			cin >> n2;
			getlist(n1, n2);
		}
		else if (cmd == "del")
		{
			int col, row, num;
			cin >> col >> row >> num;
			del(col, row, num);
		}
		else if (cmd == "ins")
		{
			int col, row;
			string text;
			cin >> col >> row;
			cin.get();
			getline(cin, text);
			ins(col, row, text);
		}
		else
		{
			cout << "Error!" << endl;
			continue;
		}
	}
	return 0;
}
