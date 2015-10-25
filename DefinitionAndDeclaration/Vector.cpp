#include "Vector.h"

Vector::Vector(int n)
	:elem{new double[n]}, sz{n} 
{
}

int Vector::size() 
{
	return sz;
}

double& Vector::operator[](int i) 
{
	return elem[i];
}