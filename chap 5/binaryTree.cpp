#include<iostream>
#include<queue>
using namespace std;

template<class Type>
class BinaryTree
{
	private:
		struct Node
		{
			Node *left,*right;
			Type data;
			Node():left(NULL),right(NULL) {}
			Node(const Type &item,Node *L=NULL,Node *R=NULL):data(item),left(L),right(R) {}
			~Node() {}
		};
		Node *root;
	public:
		BinaryTree():root(NULL) {}
		BinaryTree(const Type &value)
		{
			root = new Node(value);
		}
		BinaryTree(const Type *p)
		{
			root = p;
		}
		~BinaryTree()
		{
			clear();
		}

		Type getRoot()const
		{
			return root->data;
		}
		Type getLeft()const
		{
			return (root->left==NULL)?root->left->data:NULL;
		}
		Type getRight()const
		{
			return (root->right==NULL)?root->right->data:NULL;
		}
		void makeTree(const Type &x,BinaryTree &lt,BinaryTree &rt)
		{
			root = new Node(x,lt.root,rt.root);
			lt.root=NULL;
			rt.root=NULL;
		}
		void delLeft()
		{
			BinaryTree tmp = root->left;
			root->left=NULL;
			tmp.clear();
		}
		void delRight()
		{
			BinaryTree tmp = root->right;
			root->right = NULL;
			tmp.clear();
		}
		bool isEmpty()const
		{
			return root==NULL;
		}
		void clear()
		{
			if(root!=NULL)clear(root);
			root=NULL;
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
			if(root!=NULL)
			{
				cout<<"\n前序遍历：";
				dfs(root,1);
			}
		}
		void midOrder()const
		{
			if(root!=NULL)
			{
				cout<<"\n中序遍历：";
				dfs(root,2);
			}
		}
		void postOrder()const
		{
			if(root!=NULL)
			{
				cout<<"\n后序遍历：";
				dfs(root,3);
			}
		}
		void levelTraverse()const
		{
			if(root==NULL)return;
			cout<<"\n层次遍历：";
			queue<Node*> hh;
			hh.push(root);
			while(!hh.empty())
			{
				Node* tmp = hh.front();
				cout<<tmp->data<<" ";
				if(tmp->left!=NULL)hh.push(tmp->left);
				if(tmp->right!=NULL)hh.push(tmp->right);
				hh.pop();
			}
		}
		bool isComplete()const
		{
			if(root==NULL)false;

			queue<Node*> hh;
			hh.push(root);
			while(!hh.empty())
			{
				Node* tmp = hh.front();
				hh.pop();
				if(tmp==NULL)break;
				hh.push(tmp->left);
				hh.push(tmp->right);
			}
			while(!hh.empty())
			{
				Node* tmp = hh.front();
				hh.pop();
				if(tmp!=NULL)return false;
			}
			return true;
		}
		void createTree(Type flag)
		{
			queue<Node *> q;
			Node *tmp;
			Type x,l,r;

			cout<<"输入根节点：";
			cin>>x;
			root = new Node(x);
			q.push(root);
			while(!q.empty())
			{
				tmp = q.front();
				q.pop();
				cout<<"输入"<<tmp->data<<"的两个儿子("<<flag<<"表示空节点)：";
				cin>>l>>r;
				if(l!=flag)q.push(tmp->left=new Node(l));
				if(r!=flag)q.push(tmp->right=new Node(r));
			}
		}

	private:
		int height(Node *t)const
		{
			if(t==NULL)return 0;
			return 1+max(height(t->left),height(t->right));
		}
		void clear(Node *t)
		{
			if(t->left!=NULL)clear(t->left);
			if(t->right!=NULL)clear(t->right);
			delete t;
		}
		int size(Node *t)const
		{
			if(t==NULL)return 0;
			return 1+size(t->left)+size(t->right);
		}
		void dfs(Node *t,int type)const
		{
			if(t!=NULL)
			{
				if(type==1)cout<<t->data<<" ";
				dfs(t->left,type);
				if(type==2)cout<<t->data<<" ";
				dfs(t->right,type);
				if(type==3)cout<<t->data<<" ";
			}
		}
};

int main()
{
	BinaryTree<char>tree,tree1('M'),tree2;
	tree.createTree('@');
	cout<<"高度为："<<tree.height()<<endl;
	cout<<"规模为："<<tree.size()<<endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.levelTraverse();
	cout<<"\n"<<(tree.isComplete()?"是完全二叉树":"不是完全二叉树")<<endl;

	tree2.makeTree('Y',tree,tree1);
	cout<<endl;
	cout<<"高度为："<<tree2.height()<<endl;
	cout<<"规模为："<<tree2.size()<<endl;
	tree2.preOrder();
	tree2.midOrder();
	tree2.postOrder();
	tree2.levelTraverse();
	cout<<"\n"<<(tree2.isComplete()?"是完全二叉树":"不是完全二叉树")<<endl;
	return 0;
}
/*
输入如下（不含本行）： 
A
BC
EF
G@
@@
@@
@@
@@
*/
