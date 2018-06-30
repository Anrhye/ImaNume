#pragma once
#include "Vector3.h"

namespace CoreModule
{
	class Object3D
	{
	private:
		Maths::Vector3* pos;
		Maths::Vector3* rot;
	public:
		Object3D();
		~Object3D() { }

		Maths::Vector3* getPos();
		Maths::Vector3* getRot();

		void setPos(Maths::Vector3* pos);
		void setRot(Maths::Vector3* rot);
	};
}
