/*
Author: Henry Wang
Date: 2021-06-27
BF算法的字符串匹配
*/

#include <iostream>

using namespace std;

/*BF算法
*/
int BF(string a, string b);

int main()
{
    string a = "abc";
    string b = "bc";
    cout << BF(a, b) << endl;;
    
}

int BF(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
        //从主串的第一个字符开始往后找
        for (int j = 0; j < b.length() && i+j < a.length(); j++)
        {//从子串的第一个字符开始往后找
            if (a[i+j] != b[j])
                //若有一个不相同，则退出
                break;            
            if (j == b.length()-1)
                //若全相同，则返回主串当前的下表
                return i;
        }    
    return -1;
}