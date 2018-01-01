#include <iostream>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main()
{
    char c;
    int current = 0;         //方向
    int status = 0;          //画笔状态
    int floor[20][20] = {0}; //画布
    int x = 0, y = 0;        //当前坐标
    floor[x][y] = 1;
    while (1)
    {
        c = cin.get();
        switch (c)
        {
        case '1':
            status = 0;
            break;
        case '2':
            status = 1;
            break;
        case '3':
            current = (current + 1) % 4;
            break;
        case '4':
            current = (current - 1) % 4;
            break;
        case '5':
            int n;
            cin.get();
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                x = x + dx[current];
                y = y + dy[current];
                if (status == 1)
                    floor[x][y] = 1;
            }
            break;
        case '6':
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                    if (floor[i][j])
                        cout << '*';
                    else
                        cout << ' ';
                cout << endl;
            }
            break;
        case '9':
            return 0;
            break;
        }
    }
    return 0;
}