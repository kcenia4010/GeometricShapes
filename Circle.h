#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <class T>
class Circle : public Objects
{
private:
	int radius;
	T** Array;
public:
	Circle();
	Circle(int rad, T _mark);
	Circle(const Circle& circle);
	~Circle();

	int GetRadius();
	T GetMark();
	void SetRadius(int _radius);

	float Area() override;
	ostream& print(ostream& os) override;


	bool operator ==(const Circle& other);
};

inline Circle<char>::Circle()
{
	radius = 2;
	Array = new char * [2*radius-1];
	for (int i = 0; i < 2*radius-1; i++)
		Array[i] = new char[2*radius];

	for (int i = 0; i < radius; i++)
		for (int j = radius-1-i; j < radius+i+1; j++)
			Array[i][j] = '*';

	for (int i = radius; i < 2*radius-1; i++)
		for (int j = 1+i-radius; j < 3 * radius - 1 - i; j++)
			Array[i][j] = '*';

}

template<class T>
inline Circle<T>::Circle(int rad, T _mark)
{
	radius = rad;
	Array = new T* [2 * radius - 1];
	for (int i = 0; i < 2 * radius - 1; i++)
		Array[i] = new T[2 * radius];

	for (int i = 0; i < radius; i++)
		for (int j = radius - 1 - i; j < radius + i + 1; j++)
			Array[i][j] = _mark;

	for (int i = radius; i < 2*radius - 1; i++)
		for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
			Array[i][j] = _mark;
}

template<class T>
inline Circle<T>::Circle(const Circle& circle)
{
	if (Array != 0)
	{
		for (int i = 0; i < 2 * radius - 1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	radius = circle.radius;
	Array = new T * [2 * radius - 1];
	for (int i = 0; i < 2 * radius - 1; i++)
		Array[i] = new T[2 * radius];

	for (int i = 0; i < radius; i++)
		for (int j = radius - 1 - i; j < radius + i + 1; j++)
			Array[i][j] = circle.Array[i][j];

	for (int i = radius; i < 2*radius - 1; i++)
		for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
			Array[i][j] = circle.Array[i][j];
}

template<class T>
inline Circle<T>::~Circle()
{
	if (Array != 0)
	{
		for (int i = 0; i < 2 * radius - 1; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		radius = 0;
	}
}

template<class T>
inline int Circle<T>::GetRadius()
{
	return radius;
}

template<class T>
inline T Circle<T>::GetMark()
{
	return Array[radius][radius];
}

template<class T>
inline void Circle<T>::SetRadius(int _radius)
{
	T tmp = this->GetMark();
	if (Array != 0)
	{
		for (int i = 0; i < 2 * radius - 1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	radius = _radius;
	Array = new T * [2 * radius - 1];
	for (int i = 0; i < 2 * radius - 1; i++)
		Array[i] = new T[2 * radius];

	for (int i = 0; i < radius; i++)
		for (int j = radius - 1 - i; j < radius + i + 1; j++)
			Array[i][j] = tmp;

	for (int i = radius; i < 2 * radius - 1; i++)
		for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
			Array[i][j] = tmp;
}

template<class T>
inline float Circle<T>::Area()
{
	return radius*radius*3.14;
}

template<class T>
inline ostream& Circle<T>::print(ostream& os)
{
	for (int i = 0; i < 2 * radius-1; i++)
	{
		for (int j = 0; j < 2 * radius; j++)
		{
			if ((i < radius && j >=(radius - 1 - i) && j < (radius + i + 1)) || (i >=  radius && i < (2 * radius - 1) && j >=(1 + i - radius) && j < (3 * radius - 1 - i)))
				os << Array[i][j];
			else os << " ";
		}
		os << endl;
	}
	return os;
}

template<class T>
inline bool Circle<T>::operator==(const Circle& other)
{
	if (radius == other.radius && Array[radius][radius] == other.Array[radius][radius])
		return true;
	return false;
}
