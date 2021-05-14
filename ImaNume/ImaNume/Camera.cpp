#include "Camera.h"

CoreModule::Camera::Camera()
{ }

double CoreModule::Camera::getNear() { return this->nearPlan; }

double CoreModule::Camera::getFar() { return this->farPlan; }

void CoreModule::Camera::setNear(double nearPlan) { this->nearPlan = nearPlan; }

void CoreModule::Camera::setFar(double farPlan) { this->farPlan = farPlan; }
