#pragma once
#include<iostream>
using namespace std;

class Coordinate
{
	friend ostream &operator<<(ostream &out, Coordinate &coor);//友元函数
public:
	Coordinate(int x=0,int y=0);//默认构造函数
	~Coordinate();
	void printCoordinate();
private:
	int m_iX;
	int m_iY;
};

