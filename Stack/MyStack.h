#pragma once
#include<iostream>

using namespace std;
template<typename T>//类模板

class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();//栈判空
	bool stackFull();//栈判满
	void clearStack();//清空
	int stackLength();//栈的长度
	bool push(T elem);//入栈
	bool pop(T &elem);//出栈
	void stackTraverse(bool t);//遍历
private:
	int m_iSize;//栈容量
	int m_iTop;//栈顶，栈中元素的数量
	T *m_pBuffer;//栈空间指针

};

template<typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[m_iSize];//类Coordinate需要是默认构造函数
	m_iTop = 0;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[]m_pBuffer;
	//m_pBuffer = NULL;
}

template<typename T>
bool MyStack<T>::stackEmpty()//栈判空
{
	if (m_iTop == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool MyStack<T>::stackFull()//栈判满
{
	if (m_iTop == m_iSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void MyStack<T>::clearStack()//清空
{
	//m_iSize = 0;
	m_iTop = 0;
}

template<typename T>
int MyStack<T>::stackLength()//栈的长度
{
	return m_iTop;
}

template<typename T>
bool MyStack<T>::push(T elem)//入栈
{
	//先判满
	if (stackFull() == true)
	{
		return false;
	}
	else
	{
		m_pBuffer[m_iTop] = elem;//Coordinate的数据成员简单，所以可以直接拷贝
		m_iTop++;
		return true;
	}
}

template<typename T>
bool MyStack<T>::pop(T &elem)//出栈
{
	//先判空
	if (stackEmpty() == true)
	{
		return false;
	}
	else
	{
		m_iTop--;//!!!!!!!!!!!!!!!
		elem = m_pBuffer[m_iTop];
		return true;
	}
}

template<typename T>
void MyStack<T>::stackTraverse(bool t)//遍历
{
	if (t)
	{
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		for (int i = m_iTop-1; i >=0; i--)
		{
			cout << m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
		}
	}

}

