#pragma once
#include"Circle.h"
#include"triangle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Line.h"
#include"Point.h"
#include"Cube.h"
#include"Objects.h"

class Container
{
private: 
	Objects** Array;
	int size;
public:
	Container();
	~Container();

	template <class A>
	void Add(A& elem);
	template <class A>
	void Delete(A& elem);
	template <class A>
	void Out(A& elem);

	Objects* operator[](const int i);
	friend ostream& operator<<(ostream& out, Container& other);
};


Container::Container()
{
	size = 0;
	Array = 0;
}


Container::~Container()
{
	delete[] Array;
}

Objects* Container::operator[](const int i)
{
	return Array[i];
}


template<class A>
void Container::Add(A& elem)
{
	Objects** tmp = new Objects * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Objects * [size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	Array[size - 1] = &elem;
	delete[]tmp;
}

template<class A>
void Container::Delete(A& elem)
{
	Objects** tmp = new Objects * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (Array[i] == &elem)
		{
			k = 1;
		}
		else
		{
			tmp[j] = Array[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] Array;
	Array = new Objects * [size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		Array[i] = tmp[i];
	delete tmp;
}

template<class A>
void Container::Out(A& elem)
{
	cout << elem;
}

ostream& operator<<(ostream& out, Container& other)
{
	for (int i = 0; i < other.size; i++)
	{
		out << *(other[i]) << endl;
	}
	return out;
}

