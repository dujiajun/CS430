#include <iostream>
#include <queue>
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
    bool remove(int u, int v)
    {
        edgeNode *p = verList[u].head, *q;
        if (p == NULL)
            return false;
        if (p->end == v)
        {
            verList[u].head = p->next;
            delete p;
            --Edges;
            return true;
        }
        while (p->next != NULL && p->next->end != v)
            p = p->next;
        if (p->next == NULL)
            return false;
        q = p->next;
        p->next = q->next;
        delete q;
        --Edges;
        return true;
    }
    bool exist(int u, int v) const
    {
        edgeNode *p = verList[u].head;
        while (p != NULL && p->end != v)
            p = p->next;
        return p != NULL;
    }
    void dfs() const
    {
        bool *visited = new bool[Vers];
        for (int i = 0; i < Vers; i++)
            visited[i] = false;
        cout << "当前图的深度优先遍历序列为：" << endl;
        for (int i = 0; i < Vers; i++)
        {
            if (visited[i] == true)
                continue;
            dfs(i, visited);
            cout << endl;
        }
    }
    void bfs() const
    {
        bool *visited = new bool[Vers];
        int currentNode;
        queue<int> q;
        edgeNode *p;
        for (int i = 0; i < Vers; i++)
            visited[i] = false;

        cout << "当前图的广度优先遍历序列为：" << endl;

        for (int i = 0; i < Vers; i++)
        {
            if (visited[i] == true)
                continue;
            q.push(i);
            while (!q.empty())
            {
                currentNode = q.front();
                q.pop();
                if (visited[currentNode] == true)
                    continue;
                cout << verList[currentNode].ver << "\t";
                visited[currentNode] = true;
                p = verList[currentNode].head;
                while (p != NULL)
                {
                    if (visited[p->end] == false)
                        q.push(p->end);
                    p = p->next;
                }
            }
            cout << endl;
        }
    }
    void EulerCurcuit(TypeOfVers start)
    {
    }
    void topSort() const
    {
        queue<int> q;
        edgeNode *p;
        int current;
        int *inDegree = new int[Vers];
        for (int i = 0; i < Vers; i++)
            inDegree[i] = 0;
        for (int i = 0; i < Vers; i++)
            for (p = verList[i].head; p != NULL; p = p->next)
                ++inDegree[p->end];
        for (int i = 0; i < Vers; i++)
            if (inDegree[i] == 0)
                q.push(i);

        cout << "拓扑排序为：" << endl;
        while (!q.empty())
        {
            current = q.front();
            q.pop();
            cout << verList[current].ver << "\t";
            for (p = verList[current].head; p != NULL; p = p->next)
                if (--inDegree[p->end] == 0)
                    q.push(p->end);
        }
        cout<<endl;
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
    int numOfVers() const { return Vers; }
    int numOfEdge() const { return Edges; }

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

    struct EulerNode
    {
        int NodeNum;
        EulerNode *next;
        EulerNode(int ver)
        {
            NodeNum = ver;
            next = NULL;
        }
    };

    verNode *verList;
    void dfs(int start, bool visited[]) const
    {
        edgeNode *p = verList[start].head;
        cout << verList[start].ver << "\t";
        visited[start] = true;
        while (p != NULL)
        {
            if (visited[p->end] == false)
                dfs(p->end, visited);
            p = p->next;
        }
    }
    EulerNode *EulerCircuit(int start, EulerNode *&end)
    {
    }
    verNode *clone() const
    {
    }
};
int main()
{
    int n, d[] = {0, 1, 2, 3, 4, 5, 6, 7};
    adjListGraph<int, int> g(8, d);
    cin >> n;
    for (int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        g.insert(u, v, 1);
    }
    g.bfs();
    g.dfs();
    g.topSort();
    system("pause");
    return 0;
}
/*
9
1 3
1 2
3 7
3 5
2 5
5 6
5 4
5 6
6 4
*/
