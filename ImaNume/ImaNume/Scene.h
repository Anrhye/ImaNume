#pragma once
#include <vector>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include "Light.h"
#include "Object3D.h"
#include "Sphere.h"
#include "Color.h"
#include "Camera.h"


namespace CoreModule
{
	class Scene
	{
	private:
		const Color* _backgroundColor = new Color(new Maths::Vector3(0, 0, 0));
		Camera* camera;
		std::vector<CoreModule::Object3D*> objects;
		std::vector<CoreModule::Light*> lights;
		std::vector<CoreModule::Sphere*> spheres;
		int width;
		int height;
	public:
		Scene();
		Scene(Camera* camera, std::vector<CoreModule::Object3D*> objects, std::vector<CoreModule::Light*> lights);
		~Scene() { }

		int getWidth();
		int getHeight();

		void setWidth(int w);
		void setHeight(int h);

		void addObject(CoreModule::Object3D* obj);
		void addSphere(CoreModule::Sphere* sph);
		void addLight(CoreModule::Light* light);
		void renderSpheres();
	};
}