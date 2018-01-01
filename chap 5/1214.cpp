#include<iostream>
#include<queue>
using namespace std;
struct node
{
	node* l;
	node* r;
	int v;
};
void dfs(node *root,int type)
{
	if(type==1)cout<<root->v<<" ";
	if(root->l!=NULL)dfs(root->l,type);
	if(root->r!=NULL)dfs(root->r,type);
	if(type==2)cout<<root->v<<" ";
}
void bfs(node *root)
{
	queue<node*> hh;
	hh.push(root);
	while(!hh.empty())
	{
		node* tmp = hh.front();
		cout<<tmp->v<<" ";
		if(tmp->l!=NULL)hh.push(tmp->l);
		if(tmp->r!=NULL)hh.push(tmp->r); 
		hh.pop();
	}
}
int main()
{
	int n,*b;
	cin>>n;
	node *tree = new node [n+1];
	b = new int [n+1];
	for(int i=1,l,r; i<=n; i++)
	{
		cin>>l>>r>>tree[i].v;
		b[l]=1;
		b[r]=1;
		tree[i].l = (l==0)?NULL:&(tree[l]);
		tree[i].r = (r==0)?NULL:&(tree[r]);
	}
	node *root;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			root = tree+i;
			break;
		}
	}
	dfs(root,1);
	cout<<endl;
	dfs(root,2);
	cout<<endl;
	bfs(root);
	cout<<endl;

	delete [] tree;
	delete [] b;
 	return 0;
}
