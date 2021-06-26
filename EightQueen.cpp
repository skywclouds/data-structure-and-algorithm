/*
Author: Henry Wang
Date: 2021-6-25
EightQueen
*/

#include <iostream>

using namespace std;

int cnt = 0;//记录八皇后方案个数

/*计算八皇后方案个数的函数
*/
void EightQueen(int row,int n,int (*chess)[8]);
/*判断当前位置是否可以放置皇后
*/
int isDanger(int row, int n, int(*chess)[8]);

int main()
{
    int chess[8][8];//创建一个空棋盘
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            chess[i][j] = 0;
    EightQueen(0, 8, chess);
    cout << "一共有" << cnt << "种情况" << endl;

}

void EightQueen(int row, int n, int(*chess)[8])
{
    int c[8][8];//创建一个新棋盘记录该大情况下的小情况
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            c[i][j] = chess[i][j];
    if (row == 8)   
        cnt++;//遍历完毕则加一种情况    
    else    
        for (int i = 0; i < n; i++)
        {
            if (!isDanger(row, i, chess))
            {//若在该大情况下可以放置，则放置
                for (int j = 0; j < 8; j++)                
                    c[row][j] = 0;//将上一个小情况做出的更改归零                
                c[row][i] = 1;
                EightQueen(row + 1, n, c);
            }
        }    
}
int isDanger(int row, int n, int(*chess)[8])
{
    //横着
    for (int i = 0; i < 8; i++)    
        if (chess[row][i] == 1 && i != n)        
            return 1;//若这一行有皇后，则不能放置                             
    //竖着
    for (int i = 0; i < 8; i++)    
        if (chess[i][n] == 1 && i != row)        
            return 1;//若这一列有皇后，则不能放置                   
    //左上
    int i = row - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (chess[i][j] == 1)        
            return 1;//左上有皇后，则不能放置                     
        i--;j--;
    }
    //右下
    i = row + 1;
    j = n + 1;
    while (i < 8 && j < 8)
    {
        if (chess[i][j] == 1)        
            return 1;//右下有皇后，则不能放置                           
        i++;j++;
    }
    //右上
    i = row - 1;
    j = n + 1;
    while (i >= 0 && j < 8)
    {
        if (chess[i][j] == 1)         
            return 1;//右上有皇后，则不能放置                           
        i--;j++;
    }
    //左下
    i = row + 1;
    j = n - 1;
    while (i < 8 && j >= 0)
    {
        if (chess[i][j] == 1)        
            return 1;//左下有皇后，则不能放置                            
        i++;j--;
    }
    return 0;
}
