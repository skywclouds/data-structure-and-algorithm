/**
 * Author:Henry Wang
 * Date:2020-2-17
*/

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

/**
 * 实现栈的类
*/
class node
{
private:
    /**
     * 记录值的变量
    */
    char value;
    /**
     * 指向下一元素地址的指针
    */
    node *next = NULL;
    /**
     * 指向栈顶元素的指针
    */
    node *end = this;
public:
    node(){}
    node(char value)
    {
        this->value = value;
    }
    char getValue()
    {
        return this->value;
    }
    node* getNext()
    {
        return this->next;
    }
    void setValue(char value)
    {
        this->value = value;
    }
    void setNext(node *next)
    {
        this->next = next;
    }
    node* getEnd()
    {
        return this->end;
    }
    void setEnd(node *end)
    {
        this->end = end;
    }
};
/**
 * 向栈中压入元素的方法
*/
void push(node *l,node *newNode)
{
    l->getEnd()->setNext(newNode);
    l->setEnd(newNode);
}
/**
 * 弹出栈顶元素的方法
*/
void pop_back(node *l)
{
    node *temp = l;
    if(l->getEnd()!=l)
    {
        while(temp->getNext()!=l->getEnd())
        {
            temp = temp->getNext();
        }
        delete temp->getNext();
        temp->setNext(NULL);
        l->setEnd(temp);
    }
}
/**
 * 判断当前字符串中现有字符是否为数字
*/
bool isNumber(char c)
{
    if('0'<=c&&c<='9')
    {
        return true;
    }else
    {
        return false;
    }
}
/**
 * 将正常算式转化为逆波兰表达式
*/
string transform(string expression)
{
    string inverse = "";//储存逆波兰表达式的字符串
    if(expression[0] == '-')//如果最前面是负号，则在最前面加一个0
    {
        expression = '0' + expression;
    }
    node *l = new node();//创建栈
    for(int i = 0;i < expression.size();)//开始利用栈从头到尾创建逆波兰表达式
    {
        if(isNumber(expression[i]))//识别数字并将其加到波兰表达式中
        {
            while (isNumber(expression[i])||expression[i]=='.')
            {
                inverse += expression[i];
                i++;
            }
            inverse += ' ';
        }else//字符串中当前项是运算符或括号的情况
        {
            if(l->getEnd()==l||l->getEnd()->getValue()=='(')//若空栈或栈顶左括号，则直接压入
            {
                node *temp = new node(expression[i]);
                push(l,temp);
            }else if(expression[i]=='*'||expression[i]=='/')//当前项为乘或除的情况
            {
                
                if(l->getEnd()->getValue()=='+'||l->getEnd()->getValue()=='-')
                {
                    //若栈顶为加或减，由于乘除优先于加减，所以直接压入
                    node *temp = new node(expression[i]);
                    push(l,temp);
                }else
                {
                    //若栈顶为乘除，由于从左到右的原则，先把栈顶元素弹出再压入
                    inverse += l->getEnd()->getValue();
                    inverse += ' ';
                    pop_back(l);
                    node *temp = new node(expression[i]);
                    push(l,temp);
                }
            }else if(expression[i]=='+'||expression[i]=='-')//当前项为加或减的情况
            {
                if(l->getEnd()->getValue()!='(')
                {
                    //由于加减优先级低于乘除和从左到右计算的原则，将栈顶元素弹出再压入
                    inverse += l->getEnd()->getValue();
                    inverse += ' ';
                    pop_back(l);
                    node *temp = new node(expression[i]);
                    push(l,temp);
                }else
                {
                    //若栈顶为左括号，则直接压入
                    node *temp = new node(expression[i]);
                    push(l,temp);
                }
            }else if(expression[i] == '(')//若当前项为左括号，则直接压入
            {
                node *temp = new node(expression[i]);
                push(l,temp);
            }else//当前项为右括号的情况
            {
                //逐个向前寻找左括号，并且出栈
                while(l->getEnd()->getValue()!='(')
                {
                    inverse += l->getEnd()->getValue();
                    inverse += ' ';
                    pop_back(l);
                }
                pop_back(l);
            }
            i++;
        }   
    }
    //执行完毕后将栈中剩余元素全部弹出
    while(l->getEnd()!=l)
    {
        inverse += l->getEnd()->getValue();
        inverse += ' ';
        pop_back(l);
    }
    return inverse;
}
/**
 * 计算逆波兰表达式
*/
double calculate(string inverse)
{
    double result;//储存结果的变量
    node *l = new node();//创建栈
    for(int i = 0;i < inverse.size()-1;i++)
    {
        if(isNumber(inverse[i])||inverse[i]=='.'||inverse[i]==' ')
        {
            //识别数字并压入栈
            node *temp = new node(inverse[i]);
            push(l,temp);
        }else//若遇到运算符，则将前两个数字出栈
        {
            pop_back(l);
            string str1 = "";//储存第一个数字的字符串
            string str2 = "";//储存第二个数字的字符串
            while(l->getEnd()->getValue()!=' ')//持续出栈，得到第一个数字
            {
                str1 += l->getEnd()->getValue();
                pop_back(l);
            }
            pop_back(l);
            while(l->getEnd()->getValue()!=' '&&l->getEnd()!=l)//持续出栈，得到第二个数字
            {
                str2 += l->getEnd()->getValue();
                pop_back(l);
            }
            pop_back(l);
            for(int j = 0;j < str1.size()/2;j++)//将字符串倒过来得到正确的数字
            {
                char tc = str1[j];
                str1[j] = str1[str1.size()-1-j];
                str1[str1.size()-1-j] = tc;
            }
            for(int j = 0;j < str2.size()/2;j++)//将字符串倒过来得到正确的数字
            {
                char tc = str2[j];
                str2[j] = str2[str2.size()-1-j];
                str2[str2.size()-1-j] = tc;
            }
            //将字符串转换成浮点型以计算
            double n1 = atof(&str1[0]);
            double n2 = atof(&str2[0]);
            double r;
            if(inverse[i] == '+')
            {
                r = n1+n2;
            }else if(inverse[i] == '-')
            {
                r = n2-n1;
            }else if(inverse[i] == '*')
            {
                r = n1*n2; 
            }else
            {
                r = n2/n1;
            } 
            stringstream ss;
            string st;
            ss << r;
            ss >> st;
            node *temp = new node(' ');//将计算结果压入栈，之后进行下一次计算
            push(l,temp);
            for(int j = 0;j < st.size();j++)
            {
                node *temp = new node(st[j]);
                push(l,temp);
            }
        }
    }
    //计算结束后，栈中显然只剩下一个数字，该数字即为计算结果
    string str = "";
    while(l->getEnd()->getValue()!=' ')
    {
        str += l->getEnd()->getValue();
        pop_back(l);
    }
    for(int i = 0;i < str.size()/2;i++)
    {
        char tt = str[i];
        str[i] = str[str.size()-1-i];
        str[str.size()-1-i] = tt;
    }
    stringstream ss;
    ss << str;
    ss >> result;
    return result;
}

int main ()
{
    cout << "welcome to wang's claculator,please input: "<<endl;
    string expression;
    cin >> expression;
    double result = calculate(transform(expression));
    cout <<"result is: "<< result <<endl;
    return 0;
}
