#include <iostream>
#include "Container.h"
#include"Circle.h"
#include"triangle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Line.h"
#include"Point.h"
#include"Cube.h"
#include"Objects.h"
using namespace std;

int main()
{
	Container Cont;
	Point<char> point;
	Line<char> line(10,'*');
	Square<int> square(3, 1);
	Rectangle<int> rectangle(3, 6, 0);
	Triangle<char> triangle(4, '*');
	Circle<char> circle(3,'+');
	Cube<char> cube(3, '*');

	Cont.Add(point);
	Cont.Add(line);
	Cont.Add(square);
	Cont.Add(rectangle);
	Cont.Add(triangle);
	Cont.Add(circle);
	Cont.Add(cube);


	cout << "point:" << endl;
	Cont.Out(point);
	cout << endl;
	cout << "line:" << endl;
	Cont.Out(line);
	cout << endl;
	cout << "square:" << endl;
	Cont.Out(square);
	cout << endl;
	cout << "rectangle:" << endl;
	Cont.Out(rectangle);
	cout << endl;
	cout << "triangle:" << endl;
	Cont.Out(triangle);
	cout << endl;
	cout << "circle:" << endl;
	Cont.Out(circle);
	cout << endl;
	cout << "cube projection:" << endl;
	Cont.Out(cube);

	if (square.Area() > cube.Area())
		Cont.Delete(cube);
	if (square.Area() < cube.Area())
		Cont.Delete(square);

	cout<<"______   _______   _______   _______  Container _______  _______  _______  ______"<<endl<< Cont;
	return 0;
}
