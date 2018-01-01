#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"linklist.h"
using namespace std;


linkList<string> lines;

void open(istream &in)
{
	if(!lines.isEmpty())
	{
		cout<<"Error:请先quit！"<<endl;
		return;
	}
	string line;
	while (getline(in, line))
	{
		lines.push_back(line);
	}
	cout<<"读入成功，文件共"<<lines.length()<<"行！\n";
}
void quit(ostream &out)
{
	for (int i = 0; i<lines.length(); i++)
	{
		out << lines.visit(i) << endl;
	}
	lines.clear();
	cout<<"已将文本写入文件并退出系统！\n";
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
	cout<<"已成功完成操作！\n";
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
	cout<<"已成功完成操作！\n";
}
int main()
{
	ifstream fin;
	ofstream fout;
	string cmd;
	string filename = "";
	cout<<"欢迎来到行编辑系统，该系统提供5条命令：\n"
			<<"  open [filename]：将指定文件读入系统；\n"
			<<"  quit：将正在编辑的文件写回文件，退出系统；\n"
			<<"  list [n1]-[n2]：显示第n1-n2行的内容；\n"
			<<"  del [col] [row] [n]：从第col行第row列开始删去n个字符；\n"
			<<"  ins [col] [row] [text]：在第col行第row列插入字符串text；\n"
			<<"请输入你的操作:\n";
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
