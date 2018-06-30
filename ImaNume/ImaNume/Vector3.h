#pragma once
#include <math.h>

#ifndef __VECTOR3__
#define __VECTOR3__

namespace Maths
{
	class Vector3
	{
	private:
		double x, y, z;
	public:
		Vector3();
		Vector3(double x, double y, double z);
		~Vector3() { };

		double length();
		Vector3 normalized();

		double getX();
		double getY();
		double getZ();

		void setX(double x);
		void setY(double y);
		void setZ(double z);

		Vector3 operator+(Vector3);
		Vector3 operator-(Vector3);
		Vector3 operator*(double);
		Vector3 operator/(double);
	};
}

#endif