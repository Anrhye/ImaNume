#pragma once
#include "Vector3.h"
#include "Color.h"

namespace CoreModule
{
	class Object3D
	{
	protected:
		Maths::Vector3* pos;
		Maths::Vector3* rot;
		CoreModule::Color* color;
	public:
		Object3D();
		~Object3D() { }

		Maths::Vector3* getPos();
		Maths::Vector3* getRot();
		CoreModule::Color* getColor();

		void setPos(Maths::Vector3* pos);
		void setRot(Maths::Vector3* rot);
		void setColor(CoreModule::Color* color);
	};
}
