#include "Vector3.h"

Maths::Vector3::Vector3() { }

Maths::Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Maths::Vector3::length()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Maths::Vector3 Maths::Vector3::normalized()
{
	//double length = this->length();
	return this->operator/(this->length()); //Vector3(this->x / length, this->y / length, this->z / length);
}

double Maths::Vector3::getX() {	return this->x;	}

double Maths::Vector3::getY() {	return this->y; }

double Maths::Vector3::getZ() {	return this->z; }

void Maths::Vector3::setX(double x) { this->x = x; }

void Maths::Vector3::setY(double y) { this->y = y; }

void Maths::Vector3::setZ(double z) { this->z = z; }

Maths::Vector3 Maths::Vector3::operator+(Vector3 vec)
{
	return Vector3(vec.x + this->x, vec.y + this->y, vec.z + this->z);
}

Maths::Vector3 Maths::Vector3::operator-(Vector3 vec)
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