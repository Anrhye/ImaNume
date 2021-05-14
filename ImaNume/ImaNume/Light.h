#pragma once
#include <vector>
#include "Color.h"
#include "Sphere.h"

namespace CoreModule
{
	enum LightType
	{
		spot,
		directional,
		point
	};

	class Light : public Object3D
	{
	private:
		int intensity;
		LightType* lightType;
	public:
		Light();
		Light(Maths::Vector3* pos);
		~Light() { };

		bool direct(Maths::Vector3 inter, std::vector<Sphere*> spheres);
	};
}
