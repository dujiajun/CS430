#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

template<class Type>
class BinaryTree
{
	private:
		struct Node
		{
			Type data;
			Node(){}
			Node(const Type &item):data(item) {}
			~Node() {}
		}; 
		Node *nodes;
		bool *hasData;
		int capacity;
		const int root;
	public:
		BinaryTree(int c=50):capacity(c),root(1)
		{
			nodes = new Node[capacity];
			hasData = new bool[capacity];
			memset(hasData,0,sizeof(bool)*capacity);
		}
		BinaryTree(const Type &value):root(1)
		{
			nodes = new Node[capacity];
			hasData = new bool[capacity];
			memset(hasData,0,sizeof(bool)*capacity);
			nodes[root]=value;
			hasData[root]=1;
		}
		~BinaryTree()
		{
			delete [] nodes;
			delete [] hasData;
		}
		Type getRoot()const
		{
			return nodes[root];
		}
		bool isEmpty()const
		{
			return checkNode(root)==false;
		}
		int size()const
		{
			return size(root);
		}
		int height()const
		{
			return height(root);
		}
		void preOrder()const
		{
			if(checkNode(root))
			{
				cout<<"\n前序遍历：";
				dfs(root,1);
			}
		}
		void midOrder()const
		{
			if(checkNode(root))
			{
				cout<<"\n中序遍历：";
				dfs(root,2);
			}
		}
		void postOrder()const
		{
			if(checkNode(root))
			{
				cout<<"\n后序遍历：";
				dfs(root,3);
			}
		}
		void levelTraverse()const
		{
			if(!checkNode(root))return;
			cout<<"\n层次遍历：";
			queue<int> hh;
			hh.push(root);
			while(!hh.empty())
			{
				int tmp = hh.front();
				cout<<nodes[tmp].data<<" ";
				if(checkNode(tmp*2))hh.push(tmp*2);
				if(checkNode(tmp*2+1))hh.push(tmp*2+1);
				hh.pop();
			}
		}
		bool isComplete()const
		{
			if(!checkNode(root))return false;

			queue<int> hh;
			hh.push(root);
			while(!hh.empty())
			{
				int tmp = hh.front();
				hh.pop();
				if(!checkNode(tmp))break;
				hh.push(tmp*2);
				hh.push(tmp*2+1);
			}
			while(!hh.empty())
			{
				int tmp = hh.front();
				hh.pop();
				if(checkNode(tmp))return false;
			}
			return true;
		}
		void createTree(Type flag)
		{
			queue<int> q;
			int tmp;
			Type x,l,r;

			cout<<"输入根节点：";
			cin>>x;
			nodes[root] = x;
			q.push(root);
			while(!q.empty())
			{
				tmp = q.front();
				q.pop();
				cout<<"输入"<<nodes[tmp].data<<"的两个儿子("<<flag<<"表示空节点)：";
				hasData[tmp]=true;
				cin>>l>>r;
				if(l!=flag)
				{
					nodes[tmp*2]=l;
					hasData[tmp*2]=true;
					q.push(tmp*2);
				}
				if(r!=flag)
				{
					nodes[tmp*2+1]=r;
					hasData[tmp*2+1]=true;
					q.push(tmp*2+1);
				}
			}
		}
	/*void traverse()
	{
		for(int i=0;i<)
	}*/
	private:
		int height(int t)const
		{
			if(!checkNode(t))return 0;
			return 1+max(height(t*2),height(t*2+1));
		}
		int size(int t)const
		{
			if(!checkNode(t))return 0;
			return 1+size(t*2)+size(t*2+1);
		}
		void dfs(int t,int type)const
		{
			if(checkNode(t))
			{
				if(type==1)cout<<nodes[t].data<<" ";
				dfs(t*2,type);
				if(type==2)cout<<nodes[t].data<<" ";
				dfs(t*2+1,type);
				if(type==3)cout<<nodes[t].data<<" ";
			}
		}
		bool checkNode(int t)const
		{
			return t<capacity&&hasData[t];
		}
};

int main()
{
	BinaryTree<char>tree;
	tree.createTree('@');
	cout<<"高度为："<<tree.height()<<endl;
	cout<<"规模为："<<tree.size()<<endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.levelTraverse();
	cout<<"\n"<<(tree.isComplete()?"是完全二叉树":"不是完全二叉树")<<endl;
	return 0;
}
/*
输入如下（不含本行）： 
A
BC
EF
@G
@@
@@
@@
@@
*/
