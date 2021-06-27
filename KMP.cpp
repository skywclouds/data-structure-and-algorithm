/*
Author: Henry Wang
Date: 2021-06-27
KMP算法
*/

#include <iostream>
#include <vector>

using namespace std;

/*KMP算法
*/
int KMP(string a, string b);

/*获取next数组的函数
*/
vector<int> getNext(string s);

int main()
{
    cout << KMP("abcdfabce","abce");   
}

int KMP(string a, string b)
{
    vector<int> next = getNext(b);
    for (int i = 0; i < a.length(); i++)
    
        for (int j = 0; j < b.length() && i + j < a.length(); j++)
        {
            if (a[i+j] != b[j])
            {
                i += (j - next[j] - 1);
                //跳过重复比较的步骤
                break;
            }
            if (j == b.length() - 1)
                return i;
        }    
    return -1;
}

vector<int> getNext(string s)
{
    vector<int> next;
    for (int i = 0; i < s.length(); i++)
        next.push_back(-1);//创建vector并且令全部值为-1
    int i = -1;//i是前缀初始值
    int j = 0;//j是后缀初始值
    while (j < next.size() - 1)
        if (i == -1)
        {
            //如果前缀跑到了-1,代表从0到i-1均
            //没有元素与第i个相等，所以移到第0个
            i++;
            j++;
            next[j] = i;
        }
        else if (s[i] == s[j])
        {
            //如果前缀和后缀相等，则若下一个
            //失配，移到前缀处即可
            i++;
            j++;
            next[j] = i;
        }
        else
            //如过不相等，即自己和自己失配，
            //所以移到失配时应该移到的地方
            i = next[i];
    return next;
}