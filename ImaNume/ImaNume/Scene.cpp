#include "Scene.h"

CoreModule::Scene::Scene() { }

CoreModule::Scene::Scene(Camera* camera, Light* light)
{
	this->camera = camera;
	this->light = light;
}

void CoreModule::Scene::addObject(CoreModule::Object3D* obj) { }

void CoreModule::Scene::addLight(CoreModule::Light* light) { }

void CoreModule::Scene::startRendering() { }

void CoreModule::Scene::saveScene2Image() { }
