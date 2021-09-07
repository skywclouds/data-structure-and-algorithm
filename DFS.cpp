//深度优先搜索
//Author: Henry Wang
//Date: 2021-9-6
#include <iostream>

using namespace std;

int g[5][5];//储存图的数组
int b[5];//储存该图是否被访问过

void DFS(int n);

int main()
{
    g[0][1] = 1; g[1][0] = 1;
    g[1][2] = 1; g[2][1] = 1;
    g[1][4] = 1; g[4][1] = 1;
    g[2][3] = 1; g[3][2] = 1;
    DFS(0);
}

void DFS(int n)
{
    b[n] = 1;
    cout << (char)('A' + n);
    for (int i = 0; i < 5; i++)    
        if (g[n][i] && b[i] == 0)
        {
            b[i] = 1;
            DFS(i);
        }
                        
}
