#pragma once
#include <iostream>
using namespace std;
class Objects
{
public:
    virtual ~Objects() {}
    virtual float Area() = 0;
    virtual ostream& print(ostream& os) = 0;
    friend ostream& operator<<(ostream& os, Objects& other)
    {
        return other.print(os);
    }
    bool operator > (Objects& other)
    {
        if (this->Area() > other.Area())
            return true;
        return false;
    }
    bool operator < (Objects& other)
    {
        if (this->Area() < other.Area())
            return true;
        return false;
    }
};