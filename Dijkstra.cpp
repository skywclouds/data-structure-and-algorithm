/*
狄克斯特拉算法
Author:Henry Wang
Date: 2021-9-9
*/

#include <iostream>

using namespace std;

int g[6][6];//储存图的数组
int s[6];//储存是否成功的数组
int dis[6];//储存距离的数组

/*斯克斯特拉算法*/
void Dijkstra();
/*判断斯克斯特拉算法是否可以结束*/
int end();

int main()
{
    //初始化图
    g[0][1] = 1;
    g[0][2] = 12;
    g[1][2] = 9;
    g[1][3] = 3;
    g[2][4] = 5;
    g[3][2] = 4;
    g[2][4] = 5;
    g[3][4] = 13;
    g[3][5] = 15;
    g[4][5] = 4;
    //初始化“找到”数组
    s[1] = 1;
    //初始化“距离数组”
    for (int i = 1; i < 6; i++)   
        dis[i] = INT_MAX;
    //运行狄克斯特拉算法
    Dijkstra();
    //输出结果
    for (int i = 0; i < 6; i++)
        cout << dis[i] << " ";
    cout << endl;
    
}
int end()
{
    int e = 1;
    for (int i = 0; i < 6; i++)
        e = e * s[i];//如果每一个点都求完了，就可以结束
    return e;
}
void Dijkstra()
{
    int index = 0;//最小值的下标
    int minnum = INT_MAX;//最小值
    int n = 0;//进行遍历的节点
    while (!end())
    {
        for (int i = 0; i < 6; i++)
        {
            //从当前节点出发，找到到下一个节点的最小值和最小下表并更新数组
            if (g[n][i] != 0 && g[n][i] + dis[n] < dis[i])
            {
                dis[i] = g[n][i] + dis[n];
                if (minnum > g[n][i] + dis[n])
                {
                    index = i;
                    minnum = g[n][i] + dis[n];
                }
            }
        }
        s[index] = 1;
        n = index;//更新下一次开始遍历的节点
        index = 0;
        minnum = INT_MAX;
    }
    
}
