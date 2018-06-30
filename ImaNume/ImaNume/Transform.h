#pragma once
#include <vector>
#include "Vector3.h"

namespace CoreModule
{
	class Transform
	{
	private:
		Maths::Vector3 position;
		std::vector<int> rotation;
	public:
		Transform();
		~Transform() { };
	};
}
