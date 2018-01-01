#include<iostream>
#include<stack>
#include<vector>
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
			if(t==NULL)return false;
			if(t->data==x)return true;
			if(t->data<x)return find(x,t->right);
			if(t->data>x)return find(x,t->left);
		}
		void insert(const T &x,Node * &t)
		{
			if(t==NULL)
			{
				t = new Node(x);
				return;
			}
			if(t->data==x)return;
			else if(t->data<x)insert(x,t->right);
			else if(t->data>x)insert(x,t->left);
		}
		void remove(const T &x,Node * &t)
		{
			if(t==NULL)return;
			if(t->data<x)remove(x,t->right);
			else if(t->data>x)remove(x,t->left);
			else if(t->data==x)
			{
				if(t->left!=NULL&&t->right!=NULL)
				{
					Node * tmp = t->right;
					while(tmp->left!=NULL)tmp=tmp->left;
					t->data = tmp->data;
					remove(tmp->data,t->right);
				}
				else
				{
					Node * tmp = t;
					t = (t->left!=NULL)?t->left:t->right;
					delete tmp;
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
		struct StNode
		{
			Node * node;
			int timesPop;
			StNode(Node * n = NULL):node(n),timesPop(0){}
		};
		void removeAllBelow(const T &x,Node * &t)
		{
			stack<StNode> s;
			vector<T> arr;
			StNode cur(t);
			s.push(cur);
			while(!s.empty())
			{
				cur = s.top();
				s.pop();
				++cur.timesPop;
				if(cur.timesPop==2)
				{
					if(cur.node->data<x)arr.push_back(cur.node->data);
					if(cur.node->right!=NULL)s.push(StNode(cur.node->right));
				}
				else
				{
					s.push(cur);
					if(cur.node->left!=NULL)s.push(StNode(cur.node->left));
				}
			}
			for(int i=0;i<arr.size();i++)
			{
				remove(arr[i]);
			}
		}
		void removeAllAbove(const T &x,Node * &t)
		{
			stack<StNode> s;
			vector<T> arr;
			StNode cur(t);
			s.push(cur);
			while(!s.empty())
			{
				cur = s.top();
				s.pop();
				++cur.timesPop;
				if(cur.timesPop==2)
				{
					if(cur.node->data>x)arr.push_back(cur.node->data);
					if(cur.node->right!=NULL)s.push(StNode(cur.node->right));
				}
				else
				{
					s.push(cur);
					if(cur.node->left!=NULL)s.push(StNode(cur.node->left));
				}
			}
			for(int i=0;i<arr.size();i++)
			{
				remove(arr[i]);
			}
		}
		void removeAllBetween(const T &a,const T &b,Node * &t)
		{
			stack<StNode> s;
			vector<T> arr;
			StNode cur(t);
			s.push(cur);
			while(!s.empty())
			{
				cur = s.top();
				s.pop();
				++cur.timesPop;
				if(cur.timesPop==2)
				{
					if(cur.node->data<=b&&cur.node->data>=a)arr.push_back(cur.node->data);
					if(cur.node->right!=NULL)s.push(StNode(cur.node->right));
				}
				else
				{
					s.push(cur);
					if(cur.node->left!=NULL)s.push(StNode(cur.node->left));
				}
			}
			for(int i=0;i<arr.size();i++)
			{
				remove(arr[i]);
			}
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
		void removeAllBelow(const T &x)
		{
			removeAllBelow(x,root);
		}
		void removeAllAbove(const T &x)
		{
			removeAllAbove(x,root);
		}
		void removeAllBetween(const T &a,const T &b)
		{
			removeAllBetween(a,b,root);
		}
};
int main()
{
	int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};
	BinarySearchTree<int> tree;

	for(int i=0; i<17; i++)tree.insert(a[i]);

	/*cout<<endl;
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
*/
	tree.removeAllBelow(5);
	tree.traverse();
	tree.removeAllAbove(50);
	tree.traverse();
	tree.removeAllBetween(20,30);
	tree.traverse();
	return 0;
}
