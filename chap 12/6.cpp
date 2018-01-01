#include <iostream>
#include <queue>
#include <fstream>
#include <string>
using namespace std;
template <class TypeOfVers, class TypeOfEdge>
class adjListGraph
{
  public:
	adjListGraph(int vSize, const TypeOfVers d[])
	{
		Vers = vSize;
		Edges = 0;
		verList = new verNode[vSize];
		for (int i = 0; i < Vers; i++)
			verList[i].ver = d[i];
	}
	bool insert(int u, int v, TypeOfEdge w)
	{
		verList[u].head = new edgeNode(v, w, verList[u].head);
		++Edges;
		return true;
	}
	struct QueueNode	//���������еĶ��нڵ�
	{
		int index;		//�����±�
		int level;		//����㿪ʼ������level-1���߲��ܷ��ʵ���ǰ�ڵ㣬����levelѧ�ڰ���
	};
	void topSort() const
	{
		queue<QueueNode> q;
		edgeNode *p;
		QueueNode current;
		int *inDegree = new int[Vers];
		for (int i = 0; i < Vers; i++)
			inDegree[i] = 0;
		for (int i = 0; i < Vers; i++)
			for (p = verList[i].head; p != NULL; p = p->next)
				++inDegree[p->end];
		for (int i = 0; i < Vers; i++)
			if (inDegree[i] == 0)
			{
				QueueNode node;
				node.index = i;
				node.level = 1;
				q.push(node);
			}

		while (!q.empty())
		{
			current = q.front();
			q.pop();
			cout << verList[current.index].ver << "\t" << current.level << endl;
			for (p = verList[current.index].head; p != NULL; p = p->next)
				if (--inDegree[p->end] == 0)
				{
					QueueNode node;
					node.index = p->end;
					node.level = current.level + 1;
					q.push(node);
				}
		}
	}
	~adjListGraph()
	{
		edgeNode *p;
		for (int i = 0; i < Vers; i++)
			while ((p = verList[i].head) != NULL)
			{
				verList[i].head = p->next;
				delete p;
			}
		delete[] verList;
	}

  private:
	int Vers, Edges;
	struct edgeNode
	{
		int end;
		TypeOfEdge weight;
		edgeNode *next;
		edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL)
		{
			end = e;
			weight = w;
			next = n;
		}
	};
	struct verNode
	{
		TypeOfVers ver;
		edgeNode *head;
		verNode(edgeNode *h = NULL)
		{
			head = h;
		}
	};
	verNode *verList;
};
template <class T>
int Find(T *arr, int size, const T &val)	//�򵥵Ĳ���
{
	for (int i = 0; i < size; i++)
		if (arr[i] == val)
			return i;
	return -1;
}
int main()
{
	ifstream fin("6.txt");	//�����ļ�
	int n, m;
	fin >> n;
	string *arr = new string[n];
	for (int i = 0; i < n; i++)
		fin >> arr[i];
	fin >> m;
	adjListGraph<string, int> g(n, arr);

	string u, v;
	for (int i = 0, iu, iv; i < m; i++)
	{
		fin >> u >> v;
		iu = Find(arr, n, u);	//����γ����ƣ���������
		iv = Find(arr, n, v);
		g.insert(iv, iu, 1); //�����ʽΪ���޿γ̣����Է��򽨱�
	}
	cout<<"�γ̰������£�\n�γ�\t\tѧ��\n";
	g.topSort();
	delete[] arr;

	return 0;
}
