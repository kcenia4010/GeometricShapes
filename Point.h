#pragma once
#include"Objects.h"
#include <iostream>
using namespace std;
template <class T>
class Point : public  Objects
{
private:
	T mark;
public:
	Point();
	Point(T _mark);
	Point(const Point& point);

	T Get();

	float Area() override;
	ostream& print(ostream& os) override;

	bool operator ==(const Point& other);

};

template<class T>
inline Point<T>::Point()
{
	mark = '.';
}

template<class T>
inline Point<T>::Point(T _mark)
{
	mark = _mark;
}

template<class T>
inline Point<T>::Point(const Point& point)
{
	mark = point.mark;
}

template<class T>
inline T Point<T>::Get()
{
	return mark;
}



template<class T>
inline float Point<T>::Area()
{
	return 0;
}

template<class T>
inline ostream& Point<T>::print(ostream& os)
{
	os << this->Get();
	return os;
}

template<class T>
inline bool Point<T>::operator==(const Point& other)
{
	if (mark==other.mark)
		return true;
	return false;
}
