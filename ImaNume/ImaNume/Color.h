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

		/*static Color* _RED;
		static Color* _GREEN;
		static Color* _BLUE;*/
	};

	/*const CoreModule::Color* _RED   = new Color(new Maths::Vector3(255, 0, 0));
	const CoreModule::Color* _GREEN = new Color(new Maths::Vector3(0, 255, 0));
	const CoreModule::Color* _BLUE  = new Color(new Maths::Vector3(0, 0, 255));*/
}
