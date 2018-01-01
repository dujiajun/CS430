#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int m;
    int n;
	int type;
    node(int x,int y,int t=3):m(x),n(y),type(t){}
};
stack<node> s;
int A(int m,int n)
{
	//int **f = new int*[m+1];
	//for (int i = 0; i < m; i++)f[i] = new int[n+1];
	int f[1000][1000];
	memset(f, 0, sizeof(f));
	for (int i = 0; i < 1000; i++)
	for (int j = 0; j < 1000; j++)f[i][j] = -1;
    node st=node(m,n);
    s.push(st);
	while(!s.empty())
    {
        node tmp1 = s.top();
        if(f[tmp1.m][tmp1.n]!=-1)
        {
            s.pop();
            continue;
        }
        if(tmp1.m==0)
        {
            f[tmp1.m][tmp1.n]=tmp1.n+1;
			s.pop();
        }
        else if(tmp1.n==0)
        {
			if (f[tmp1.m - 1][1] == -1)
			{
				node tmp2(tmp1.m - 1, 1);
				s.push(tmp2);
			}
			else
			{
				f[tmp1.m][tmp1.n] = f[tmp1.m - 1][1];
				continue;
			}
        }
        else
        {
            if(f[tmp1.m][tmp1.n-1]==-1)
            {
                node tmp2(tmp1.m,tmp1.n-1);
                s.push(tmp2);
            }
            else
            {
				if (f[tmp1.m - 1][f[tmp1.m][tmp1.n - 1]] == -1)
				{
					node tmp2(tmp1.m - 1, f[tmp1.m][tmp1.n - 1]);
					s.push(tmp2);
				}
				else f[tmp1.m][tmp1.n] = f[tmp1.m - 1][f[tmp1.m][tmp1.n - 1]];
            }
        }
    }
    return f[m][n];
}

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<A(m,n)<<endl;
	return 0;
}
