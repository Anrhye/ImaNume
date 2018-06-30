#pragma once
#include "Color.h"

namespace CoreModule
{
	class Camera
	{
	private:
		int near, far, fov;
		Color* backgroundColor;
	public:
		Camera();
		~Camera() { };
	};
}
