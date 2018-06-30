#pragma once
#include "Vector3.h"

namespace CoreModule
{
	class Color
	{
	private:
		Maths::Vector3* rgb;
		double alpha;
	public:
		Color();
		Color(Maths::Vector3* rgb);
		Color(Maths::Vector3* rgb, double alpha);
		~Color() { };

		double getR();
		double getG();
		double getB();
		double getA();
		Maths::Vector3* getRGB();

		void setR(double red);
		void setG(double green);
		void setB(double blue);
		void setA(double alpha);
		void setRGB(Maths::Vector3* rgb);
		void setRGBA(Maths::Vector3* rgb, double alpha);
	};
}
