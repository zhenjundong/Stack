#pragma once
#include<iostream>
using namespace std;

class Coordinate
{
	friend ostream &operator<<(ostream &out, Coordinate &coor);//��Ԫ����
public:
	Coordinate(int x=0,int y=0);//Ĭ�Ϲ��캯��
	~Coordinate();
	void printCoordinate();
private:
	int m_iX;
	int m_iY;
};

