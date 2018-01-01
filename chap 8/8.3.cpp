#include<iostream>
#include<stack>
using namespace std;

template<class T>
class BinarySearchTree
{
	private:
		struct Node
		{
			T data;
			Node* left;
			Node* right;
			Node(const T &x,Node *l=NULL,Node *r=NULL):data(x),left(l),right(r) {}
		};
		Node * root;
		bool find(const T &x,Node * t)const
		{
			stack<Node*> s;
			if(t!=NULL)s.push(t);
			while(!s.empty())
			{
				Node * tmp = s.top();
				s.pop();
				if(tmp->data==x)return true;
				if(tmp->data<x&&tmp->right!=NULL)s.push(tmp->right);
				if(tmp->data>x&&tmp->left!=NULL)s.push(tmp->left);
			}
			return false;
		}
		void insert(const T &x,Node * &t)
		{
			stack<Node**> s;
			s.push(&t);
			while(!s.empty())
			{
				if(*s.top()==NULL)
				{
					*s.top() = new Node(x);
					return;
				}
				Node ** tmp = s.top();
				s.pop();
				if((*tmp)->data==x)return;
				if((*tmp)->data<x)s.push(&((*tmp)->right));
				if((*tmp)->data>x)s.push(&((*tmp)->left));
			}
		}
		void remove(const T &x,Node * &t)
		{
			stack<Node**> s;
			if(t!=NULL)s.push(&t);
			while(!s.empty())
			{
				Node ** tmp = s.top();
				s.pop();
				if((*tmp)->data<x)s.push(&((*tmp)->right));
				if((*tmp)->data>x)s.push(&((*tmp)->left));
				if((*tmp)->data==x)
				{
					if((*tmp)->left!=NULL&&(*tmp)->right!=NULL)
					{
						Node * tmp2 = (*tmp)->right;
						while(tmp2->left!=NULL)tmp2=tmp2->left;
						t->data = tmp2->data;
						remove(tmp2->data,(*tmp)->right);
					}
					else
					{
						Node * tmp2 = *tmp;
						*tmp = ((*tmp)->left!=NULL)?(*tmp)->left:(*tmp)->right;
						delete tmp2;
					}
				}
			}
		}
		void clear(Node * &t)
		{
			if(t==NULL)return;
			clear(t->left);
			clear(t->right);
			delete t;
		}
		void dfs(Node * &t)
		{
			if(t==NULL)return;
			cout<<t->data<<" ";
			dfs(t->left);
			dfs(t->right);
		}
	public:
		void traverse()
		{
			dfs(root);
			cout<<endl;
		}
		BinarySearchTree(Node * t = NULL)
		{
			root = t;
		}
		~BinarySearchTree()
		{
			clear(root);
		}
		bool find(const T &x)const
		{
			return find(x,root);
		}
		void insert(const T &x)
		{
			insert(x,root);
		}
		void remove(const T &x)
		{
			remove(x,root);
		}
};
int main()
{
	int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
	BinarySearchTree<int> tree;

	for(int i=0; i<17; i++)tree.insert(a[i]);
	tree.traverse();
	cout<<endl;
	cout<<"find 2 is "<<(tree.find(2)?"true":"false")<<endl;
	tree.remove(2);
	cout<<"after delete 2, find 2 is "<<(tree.find(2)?"true":"false")<<endl;

	cout<<"find 3 is "<<(tree.find(3)?"true":"false")<<endl;
	tree.remove(3);
	cout<<"after delete 3, find 3 is "<<(tree.find(3)?"true":"false")<<endl;

	cout<<"find 21 is "<<(tree.find(21)?"true":"false")<<endl;
	tree.remove(21);
	cout<<"after delete 21, find 21 is "<<(tree.find(21)?"true":"false")<<endl;

	cout<<"find 1 is "<<(tree.find(1)?"true":"false")<<endl;
	cout<<"find 22 is "<<(tree.find(22)?"true":"false")<<endl;
	cout<<"find 56 is "<<(tree.find(56)?"true":"false")<<endl;

	return 0;
}
