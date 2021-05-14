#pragma once
#include "Color.h"
#include "Object3D.h"

namespace CoreModule
{
	class Camera : public Object3D
	{
	private:
		double nearPlan, farPlan;
		Color* backgroundColor;
	public:
		Camera();
		Camera(Maths::Vector3* pos);
		~Camera() { };

		double getNear();
		double getFar();

		void setNear(double nearPlan);
		void setFar(double farPlan);
	};
}
