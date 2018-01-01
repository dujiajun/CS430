#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node* lson;
	Node* rbro;
	bool isRoot;
	Node():isRoot(true) {}
};
void dfs(Node *t,int type)				//先序遍历和后序遍历 
{
	if(t!=NULL)
	{
		if(type==1)cout<<t->data<<" ";
		dfs(t->lson,type);
		
		dfs(t->rbro,type);
		if(type==2)cout<<t->data<<" ";
		
	}
}
void bfs(Node *t)						//层次遍历
{
	queue<Node*> hh;
	hh.push(t);
	while(!hh.empty())
	{
		Node* tmp = hh.front();
		cout<<tmp->data<<" ";
		if(tmp->lson!=NULL)hh.push(tmp->lson);
		Node *p=tmp->rbro;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			if(p->lson!=NULL)hh.push(p->lson);
			p=p->rbro;
		} 
		hh.pop();
	}
}
int main()
{
	//输入格式参考OJ 1214 
	int n;
	cin>>n;
	Node *tree = new Node[n+1];
	for(int i=1,l,r; i<=n; i++)
	{
		cin>>l>>r>>tree[i].data;
		tree[i].lson = (l!=0)?&(tree[l]):NULL;
		tree[i].rbro = (r!=0)?&(tree[r]):NULL;
		tree[l].isRoot=false;
		tree[r].isRoot=false;
	}
	Node *root;
	for(int i=1; i<=n; i++)
	if(tree[i].isRoot)
	{
		root=&tree[i];
		break;
	}
	cout<<"前序遍历：" ; 
	dfs(root,1);
	cout<<"\n后序遍历：";
	dfs(root,2);
	cout<<"\n层次遍历：";
	bfs(root);
	delete [] tree;
	return 0;
}
/*
第一行含有一个正整数N，代表树中结点总数。
第二行到第N+1行，每行包含三个整数。
其中第i行的三个整数Pi，Qi，Vi，代表结点i的左孩子为Pi，右兄弟为Qi，结点i自身的权值为Vi。
若Pi=0，则表明结点i没有左孩子。
同样的，若Qi=0，则表明结点i没有右兄弟。

9
2 0 1
5 3 2
0 4 3
7 0 4
0 6 5
0 0 6
0 8 7
0 9 8
0 0 9
*/
