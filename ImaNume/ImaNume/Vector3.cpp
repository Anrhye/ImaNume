#include "Vector3.h"
#include <iostream>

Maths::Vector3::Vector3() { }

Maths::Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Maths::Vector3::length(Maths::Vector3 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

Maths::Vector3 Maths::Vector3::normalize(Maths::Vector3 vec)
{
	double length = Maths::Vector3::length(vec);
	//return vec.operator/(Maths::Vector3::length(vec)); 
	return Vector3(vec.x / length, vec.y / length, vec.z / length);
}

double Maths::Vector3::getX() {	return this->x;	}

double Maths::Vector3::getY() {	return this->y; }

double Maths::Vector3::getZ() {	return this->z; }

void Maths::Vector3::setX(double x) { this->x = x; }

void Maths::Vector3::setY(double y) { this->y = y; }

void Maths::Vector3::setZ(double z) { this->z = z; }

Maths::Vector3 Maths::Vector3::operator+(Maths::Vector3 vec)
{
	return Vector3(vec.x + this->x, vec.y + this->y, vec.z + this->z);
}

Maths::Vector3 Maths::Vector3::operator-(Maths::Vector3 vec)
{
	return Vector3(vec.x - this->x, vec.y - this->y, vec.z - this->z);
}

Maths::Vector3 Maths::Vector3::operator*(double d)
{
	return Vector3(this->x * d, this->y * d, this->z * d);
}

Maths::Vector3 Maths::Vector3::operator/(double d)
{
	return Vector3(this->x / d, this->y / d, this->z / d);
}

double Maths::Vector3::scalaire(Maths::Vector3 u, Maths::Vector3 v)
{
	return (u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ());
}

Maths::Vector3 Maths::Vector3::reflect(Maths::Vector3 u, Maths::Vector3 v)
{
	double coef = 2 * Maths::Vector3::scalaire(u, v);

	return Maths::Vector3(u.getX() - coef * v.getX(), u.getY() - coef * v.getY(), u.getZ() - coef * v.getZ());
}