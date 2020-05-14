#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <class T>
class Line: public  Objects
{
private:
    int length;
	T* Array;
public:
	Line();
	Line(int len, T _mark);
	Line(const Line& line);
	~Line();

	int GetLen();
	T GetMark();
	void SetLen(int len);


	float Area() override;
	ostream& print(ostream& os) override;

	bool operator ==(const Line& other);
};

template<class T>
inline Line<T>::Line()
{
	length = 10;
	Array = new char [length];
	for (int i = 0; i < length; i++)
		Array[i] = "*";
}

template<class T>
inline Line<T>::Line(int len, T _mark)
{
	length = len;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = _mark;
}

template<class T>
inline Line<T>::Line(const Line& line)
{
	if (Array != 0)
		delete[] Array;
	length = line.length;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = line.Array[i];
}

template<class T>
inline Line<T>::~Line()
{
	if (Array != 0)
	{
		delete[] Array;
		Array = 0;
		length = 0;
	}
}

template<class T>
inline int Line<T>::GetLen()
{
	return length;
}

template<class T>
inline T Line<T>::GetMark()
{
	return Array[0];
}

template<class T>
inline void Line<T>::SetLen(int len)
{
	T tmp = Array[0];
	if (Array != 0)
		delete[] Array;
	length = len;
	Array = new T[length];
	for (int i = 0; i < length; i++)
		Array[i] = tmp;
}


template<class T>
inline float Line<T>::Area()
{
	return 0;
}

template<class T>
inline ostream& Line<T>::print(ostream& os)
{
	for (int i = 0; i < length; i++)
		os << Array[i];
	os << endl;
	return os;
}

template<class T>
inline bool Line<T>::operator==(const Line& other)
{
	if (length == other.length && Array[0] == other.Array[0])
		return true;
	return false;
}
