#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <class T>
class Rectangle : public  Objects
{
private:
	int side1;
	int side2;
	T** Array;
public:
	Rectangle();
	Rectangle(int _side1, int _side2, T _mark);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();

	int GetSide1();
	int GetSide2();
	T GetMark();
	void SetSide(int _side1, int _side2);

	float Area() override;
	ostream& print(ostream& os) override;

	bool operator ==(const Rectangle& other);
};


inline Rectangle<char>::Rectangle()
{
	side1 = 1;
	side2 = 1;
	Array = new char* [1];
	Array[0] = new char[1];
	Array[0][0] = '*';
}

template<class T>
inline Rectangle<T>::Rectangle(int _side1, int _side2, T _mark)
{
	side1 = _side1;
	side2 = _side2;
	Array = new T * [side1];
	for (int i = 0; i < side1; i++)
		Array[i] = new T[side2];

	for (int i = 0; i < side1; i++)
		for (int j = 0; j < side2; j++)
			Array[i][j] = _mark;
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& rectangle)
{
	 if (Array != 0)
	 {
		 for (int i = 0; i < side1; i++)
			 delete[] Array[i];
		 delete[] Array;
	 }
	 side1 = rectangle.side1;
	 side2 = rectangle.side2;
	 Array = new T * [side1];
	 for (int i = 0; i < side1; i++)
		 Array[i] = new T[side2];

	 for (int i = 0; i < side1; i++)
		 for (int j = 0; j < side2; j++)
			 Array[i][j] = rectangle.Array[i][j];
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
	if (Array != 0)
	{
		for (int i = 0; i < side1; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		side1 = 0;
		side2 = 0;
	}
}

template<class T>
inline int Rectangle<T>::GetSide1()
{
	return side1;
}

template<class T>
inline int Rectangle<T>::GetSide2()
{
	return side2;
}

template<class T>
inline T Rectangle<T>::GetMark()
{
	return Array[0][0];
}

template<class T>
inline void Rectangle<T>::SetSide(int _side1, int _side2)
{
	T tmp = Array[0][0];
	if (Array != 0)
	{
		for (int i = 0; i < side1; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side1 = _side1;
	side2 = _side2;
	Array = new T * [side1];
	for (int i = 0; i < side1; i++)
		Array[i] = new T[side2];

	for (int i = 0; i < side1; i++)
		for (int j = 0; j < side2; j++)
			Array[i][j] = tmp;
}


template<class T>
inline float Rectangle<T>::Area()
{
	return side1*side2;
}

template<class T>
inline ostream& Rectangle<T>::print(ostream& os)
{
	for (int i = 0; i < side1; i++)
	{
		for (int j = 0; j < side2; j++)
			os << Array[i][j];
		os << endl;
	}
	return os;
}

template<class T>
inline bool Rectangle<T>::operator==(const Rectangle& other)
{
	if (side1 == other.side1 && side2 == other.side2 && Array[0][0] == other.Array[0][0])
		return true;
	return false;
}
