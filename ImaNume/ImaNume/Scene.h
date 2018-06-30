#pragma once
#include "Light.h"
#include "Object3D.h"
#include "Color.h"
#include "Camera.h"

namespace CoreModule
{
	class Scene
	{
	private:
		const Color* _backgroundColor = new Color(new Maths::Vector3(0, 0, 0));
		Camera* camera;
		Light* light;
	public:
		Scene();
		Scene(Camera* camera, Light* light);
		~Scene() { }

		void addObject(CoreModule::Object3D* obj);
		void addLight(CoreModule::Light* light);

		void startRendering();
		void saveScene2Image();
	};
}