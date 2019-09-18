#include <iostream> 
#include <string> 
#include <cmath> 
#include <stack>
#include <stdio.h>
using namespace std;
//��������
char symbol[7] = {'+', '-', '*', '/', '(', ')', '#'};
//ջ��Ԫ�ص����ȼ�
int in[7] = {3, 3, 5, 5, 1, 6, 0};
//ջ��Ԫ�ص����ȼ�
int out[7] = {2, 2, 4, 4, 6, 1, 0};
int get(char c)
{
    switch(c)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case  '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '#':
        return 6;
    default:
        return 6;
    }
}
 
///�Ƚ�ջ�������c1��ջ�������c2�����ȼ�
char precede(char c1, char c2)
{
    int i1 = get(c1);
    int i2 = get(c2);
 
    if(in[i1] > out[i2])
    {
        return '>';
    }
    else if(in[i1] < out[i2])
    {
        return '<';
    }
    else
    {
        return '=';
    }
}
 
 
///����������ʽ��ֵ
int figure(int a, int theta, int b)
{
    switch(theta)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    default:
        return a / b;
    }
}
 
///������ʽ��ֵ
int EvaluateExpression(const char *exp)
{
    stack<int> data; //����ջ
    stack<int> oper; //����ջ
 
    oper.push(get('#'));
    int sum = 0;
    int flag = 1; //��ʾ������ 1,��ʾ�� 0,��ʾ��
    int a, theta, b;
 
    if(!('-' == *exp || '(' == *exp || isdigit(*exp)))
    {
        cout << "���ʽ����1" << endl;
        return -1;
    }
 
    if('-' == *exp)
    {
        flag = 0;
        exp++;//ָ����һ���ַ�
    }
 
    int index = oper.top();
    while(*exp || symbol[index] != '#')
    {
        if(isdigit(*exp))
        {
            sum = 0;
            if(flag)
            {
                while(isdigit(*exp))
                {
                    sum = sum * 10 + *exp - '0';
                    exp++;
                }
            }
            else
            {
                while(isdigit(*exp))
                {
                    sum = sum * 10 - *exp - '0';
                    exp++;
                }
            }
            data.push(sum);
            flag = 1;
        }
        else
        {
            switch(precede(symbol[oper.top()], *exp))
            {
            case '>' :
                b = data.top();
                data.pop();
                a = data.top();
                data.pop();
                theta = oper.top();
                oper.pop();
                data.push(figure(a, theta, b));
                break;
            case '<' :
                oper.push(get(*exp));
                if(*exp)
                {
                    exp++;
                }
                break;
            case '=' :
                oper.pop();
                if(*exp)
                {
                    exp++;
                }
                break;
            }
        }
        index = oper.top();
    }
    return data.top();
}
