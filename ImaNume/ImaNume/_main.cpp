#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Scene.h"

int main( int argc, char* argv[] )
{
	CoreModule::Scene scene = CoreModule::Scene();

	scene.setWidth(1920);
	scene.setHeight(1080);

	CoreModule::Sphere* sphere1 = new CoreModule::Sphere(new Maths::Vector3(-4.0, -2.5, 30.0), 2.0f,
								   new CoreModule::Color(new Maths::Vector3(190.0, 50.0, 120.0)));

	CoreModule::Sphere* sphere2 = new CoreModule::Sphere(new Maths::Vector3(-4.0, 3.5, 50.0), 6.5f,
								   new CoreModule::Color(new Maths::Vector3(100.0, 230.0, 138.0)));

	CoreModule::Sphere* sphere3 = new CoreModule::Sphere(new Maths::Vector3(7.0, 1.0, 35.0), 0.5f,
								   new CoreModule::Color(new Maths::Vector3(10.0, 180.0, 150.0)));

	CoreModule::Light* light   = new CoreModule::Light(new Maths::Vector3(-1500.0f, 2000.0f, -500.0f));

	scene.addSphere(sphere1);
	scene.addSphere(sphere2);
	scene.addSphere(sphere3);

	scene.addLight(light);

	scene.renderSpheres();

	std::cout << "\nImage created in output folder" << std::endl;
	system("pause");
	return 0;
}