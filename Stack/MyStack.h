#pragma once
#include<iostream>

using namespace std;
template<typename T>//��ģ��

class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();//ջ�п�
	bool stackFull();//ջ����
	void clearStack();//���
	int stackLength();//ջ�ĳ���
	bool push(T elem);//��ջ
	bool pop(T &elem);//��ջ
	void stackTraverse(bool t);//����
private:
	int m_iSize;//ջ����
	int m_iTop;//ջ����ջ��Ԫ�ص�����
	T *m_pBuffer;//ջ�ռ�ָ��

};

template<typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[m_iSize];//��Coordinate��Ҫ��Ĭ�Ϲ��캯��
	m_iTop = 0;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[]m_pBuffer;
	//m_pBuffer = NULL;
}

template<typename T>
bool MyStack<T>::stackEmpty()//ջ�п�
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
bool MyStack<T>::stackFull()//ջ����
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
void MyStack<T>::clearStack()//���
{
	//m_iSize = 0;
	m_iTop = 0;
}

template<typename T>
int MyStack<T>::stackLength()//ջ�ĳ���
{
	return m_iTop;
}

template<typename T>
bool MyStack<T>::push(T elem)//��ջ
{
	//������
	if (stackFull() == true)
	{
		return false;
	}
	else
	{
		m_pBuffer[m_iTop] = elem;//Coordinate�����ݳ�Ա�򵥣����Կ���ֱ�ӿ���
		m_iTop++;
		return true;
	}
}

template<typename T>
bool MyStack<T>::pop(T &elem)//��ջ
{
	//���п�
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
void MyStack<T>::stackTraverse(bool t)//����
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

