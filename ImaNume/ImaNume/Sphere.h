#pragma once
#include "Object3D.h"
#include <iostream>

namespace CoreModule
{
	class Sphere : public Object3D
	{
	private:
		double radius;
	public:
		Sphere();
		Sphere(Maths::Vector3* pos, double radius);
		Sphere(Maths::Vector3* pos, double radius, CoreModule::Color* color);
		~Sphere() {}

		double getRadius();

		void setRadius(double radius);

		Maths::Vector3 intersectStraightLine(Maths::Vector3 normdVec, Maths::Vector3 origin);
	};
}

