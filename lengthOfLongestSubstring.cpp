/**
Date: 2021-3-23
Author: Henry Wang
*/

#include <iostream>
#include <unordered_set>

using namespace std;

/**最大无重复子串长度
*/
int lengthOfLongestSubstring(string s);

int main()
{
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;;
}

int lengthOfLongestSubstring(string s)
{
    int n = s.size();//n记录字符串长度；
    int right = 0;//记录右端点的变量
    int ans = 0;//记录最大值的变量
    unordered_set<char> occ;//储存当前子串的unorder_set
    for (int i = 0; i < n; i++)
    {//i为左端点，从0开始
        if (i != 0)
        {//左端点改变后，将原左端点对应元素删除
            occ.erase(s[i - 1]);
        }
        while (right  < n && !occ.count(s[right]))
        {//将右端点向右移，若没有重复则添加进去
            occ.insert(s[right]);
            right++;
        }
        //更新最大长度
        ans = max(ans, right - i);
    }
    return ans;
}
