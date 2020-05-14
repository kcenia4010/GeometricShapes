#pragma once
#include"Objects.h"
#include"Square.h"
#include <iostream>
using namespace std;
template <class T>
class Cube : public  Objects
{
private:
	int side;
	T*** Array;
public:
	Cube();
	Cube(int a, T _mark);
	Cube(const Cube& cube);
	~Cube();

	int GetSide();
	T GetMark();
	void SetSide(int _side);

	float Area() override;
	ostream& print(ostream& os) override;

	bool operator ==(const Cube& other);
};

template<class T>
inline Cube<T>::Cube()
{
	side = 1;
	Array = new T * *[side];
	for (int i = 0; i < side; i++)
	{
		Array[i] = new T * [side];
		for (int j = 0; j < side; j++)
			Array[i][j] = new T[side];
	}
		Array[0][0][0] = '*';
}

template<class T>
inline Cube<T>::Cube(int a, T _mark)
{
	side = a;
	Array = new T * *[side];
	for (int i = 0; i < side; i++)
	{
		Array[i] = new T * [side];
		for (int j = 0; j < side; j++)
			Array[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				Array[i][j][l] = _mark;
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] Array[i][j];
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = cube.side;
	Array = new T * *[side];
	for (int i = 0; i < side; i++)
	{
		Array[i] = new T * [side];
		for (int j = 0; j < side; j++)
			Array[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				Array[i][j][l] = cube.Array[i][j][l];
}

template<class T>
inline Cube<T>::~Cube()
{
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] Array[i][j];
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		side = 0;
	}
}

template<class T>
inline int Cube<T>::GetSide()
{
	return side;
}

template<class T>
inline T Cube<T>::GetMark()
{
	return Array[0][0][0];
}

template<class T>
inline void Cube<T>::SetSide(int _side)
{
	T tmp = Array[0][0][0];
	if (Array != 0)
	{
		for (int i = 0; i < side; i++)
			for (int j = 0; j < side; j++)
				delete[] Array[i][j];
		for (int i = 0; i < side; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = _side;
	Array = new T * *[side];
	for (int i = 0; i < side; i++)
	{
		Array[i] = new T * [side];
		for (int j = 0; j < side; j++)
			Array[i][j] = new T[side];
	}
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			for (int l = 0; l < side; l++)
				Array[i][j][l] = tmp;
}

template<class T>
inline float Cube<T>::Area()
{
	return side*side*6;
}

template<class T>
inline ostream& Cube<T>::print(ostream& os)
{
	Square<T> tmp(side, Array[0][0][0]);
	tmp.print(os);
	return os;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& other)
{
	if (side == other.side && Array[0][0][0] == other.Array[0][0][0])
		return true;
	return false;
}
