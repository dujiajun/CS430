#include <iostream>
#include <queue>
using namespace std;
typedef int TypeOfEdge; //为方便起见，边权值类型设为int

template <class TypeOfVers>
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
	void find(int start, TypeOfEdge M)
	{
		int *prev = new int[Vers];
		bool *visited = new bool[Vers];
		for (int i = 0; i < Vers; i++)
			visited[i] = false;
		visited[start] = 1;
		find(start, start, prev, M, visited);
		delete[] prev;
		delete[] visited;
	}

private:
	//start:最开始起点，now:当前节点，prev：存放前驱，M：剩余权值，visited：标记已访问
	void find(int start, int now, int *prev, TypeOfEdge M, bool *visited)
	{
		if (M == 0)
		{
			print(prev, now, start);
			cout << endl;
		}
		edgeNode *p = verList[now].head;
		while (p != NULL)
		{
			if (visited[p->end] == false && M - p->weight >= 0)
			{
				prev[p->end] = now;
				visited[p->end] = true;
				find(start, p->end, prev, M - p->weight, visited);
				visited[p->end] = false;
			}
			p = p->next;
		}
	}

	//输出到屏幕上
	void print(int *prev, int now, int start)
	{
		if (now == start)
			cout << now;
		else
		{
			print(prev, prev[now], start);
			cout << "->" << now;
		}

	}

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
int main()
{
	//输入文件在文末，数据参考教材361页图12-15
	int n, d[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	adjListGraph<int> g(8, d);
	cin >> n;
	for (int i = 0, u, v; i < n; i++)
	{
		cin >> u >> v;
		g.insert(u, v, 1);
	}
	g.find(1, 4);
	return 0;
}
/*
10
1 3
1 2
3 7
3 5
2 5
2 6
2 4
5 6
5 7
6 4
*/
