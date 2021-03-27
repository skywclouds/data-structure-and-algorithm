/**
Date: 2021-3-27
Author: Henry Wang
*/

#include <iostream>

using namespace std;

/**判断字符串是否匹配的函数
*/
bool isMatch(string s, string p);
/**判断字符串是否匹配的函数
*/
bool isMatch(string s, string p,int i,int j);
/**判断字符是否匹配的函数
*/
bool match(char a, char b);

int main()
{
    cout << "Hello World!" << endl;
    string str;
    cin >> str;
    string expression = "aaaa";
    cout << isMatch(str, expression) << endl;

}

bool isMatch(string s, string p)
{
    return isMatch(s,p,s.size()-1,p.size()-1);
}
bool isMatch(string s, string p, int i, int j)
{
    if (i < 0 && j < 0)
    {//若字符串和正则表达式均为空，则返回true
        return true;
    }
    else
    {
        if (i < 0 && p[j] == '*')
        {//若字符串为空，正则表达式最后为*，则跳过这个*和前面的字符
            return isMatch(s,p,i,j-2);
        }
        if (i < 0||j < 0)
        {//若有一个为空，且不是星号，则返回false
            return false;
        }
        if (p[j] != '*')
        {//如果都不是空，且不是星号
            if (match(s[i], p[j]))
            {
                return isMatch(s, p, i - 1,j - 1);
            }
            else
            {
                return false;
            }
        }
        else
        {//如果都不是空，且是星号
            if (match(s[i], p[j - 1]))
            {//星号前字符出现至少一次
                return isMatch(s, p, i - 1, j) || isMatch(s, p, i, j - 2);
                //||后面的式子是为了应对假1+次如a,aa*
            }
            else
            {//星号前字符出现0次
                return isMatch(s, p, i, j - 2);
            }
        }
    }
}
bool match(char a, char b)
{
    if (a == b || b == '.')
    {
        return true;
    }
    else
    {
        return false;
    }

}
