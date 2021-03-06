// Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "MyStack.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;

/*
栈应用，数制转换
公式：N=（N/d）*d + N % d
*/
//int main()
//{
//	mystack<int> *p = new mystack<int>(30);//具体化一下，变成模板类
//	int n = 11;
//	int temp = 16;//二进制转换
//	int mod = 0;
//	while (n != 0)
//	{
//		mod = n % temp;
//		p->push(mod);
//		n = n / temp;
//	}
//	//新的问题！！！！！！！！！！16进制，出现a,b,c,d,,e,f
//	int elem = 0;
//	char num[] = "0123456789abcdef";
//	while (!p->stackempty())
//	{
//		for (int i = p->stacklength() - 1;i >= 0;i--)
//		{
//			p->pop(elem);
//			cout << num[elem] ;
//		}
//	}
//	//p->stacktraverse(false);
//
//	delete p;
//	p = null;
//}

/*
括号匹配!!!!!!!!!
[()],[([])],[()]]
*/
int main()
{
	MyStack<char> *p = new MyStack<char>(30);
	MyStack<char> *pneed = new MyStack<char>(30);
	char elem[] = "[()]]";
	char needelem = 0;
	for (int i = 0; i < strlen(elem); i++)
	{
		if (elem[i] != needelem)
		{
			p->push(elem[i]);
			switch (elem[i])
			{
			case '[':
				if (needelem != 0)
				{
					pneed->push(needelem);
				}
				needelem= ']';
				break;
			case '(':
				if (needelem != 0)
				{
					pneed->push(needelem);
				}
				needelem=')';
				break;
			default:
				cout << "不匹配" << endl;
				//system("pasue");
				return 0;
			}
		}
		else
		{
			char temp = 0;
			p->pop(temp);
			if (!pneed->pop(needelem))
			{
				needelem = 0;
			}
		}
	}
	if (p->stackEmpty())
	{
		cout << "匹配" << endl;
	}
	else
	{
		cout << "不匹配" << endl;
	}
	delete p;
	p = NULL;
	delete pneed;
	pneed = NULL;
}