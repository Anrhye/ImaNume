#pragma once
#include <math.h>

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

		static double length(Vector3 vec);
		static Vector3 normalize(Vector3 vec);
		static double scalaire(Vector3 u, Vector3 v);
		static Maths::Vector3 reflect(Vector3 u, Vector3 v);

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