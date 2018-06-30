#pragma once
#include "Color.h"

namespace CoreModule
{
	enum LightType
	{
		spot,
		directional,
		point
	};

	class Light
	{
	private:
		int intensity;
		Color* color;
		LightType* lightType;
	public:
		Light();
		~Light() { };
	};
}
