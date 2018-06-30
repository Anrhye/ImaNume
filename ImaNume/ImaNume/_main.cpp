#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lib/FreeImage/FreeImage.h"
#include "Color.h"

int main( int argc, char* argv[] )
{
	CoreModule::Color color = CoreModule::Color(1, 2, 3, 4);

	std::cout << color.getR() << std::endl;
	std::cout << color.getG() << std::endl;
	std::cout << color.getB() << std::endl;
	std::cout << color.getA() << std::endl;

	system("pause");
	return 0;
}