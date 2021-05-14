#include "Object3D.h"

CoreModule::Object3D::Object3D() { }

Maths::Vector3* CoreModule::Object3D::getPos() { return this->pos; }

Maths::Vector3* CoreModule::Object3D::getRot() { return this->rot; }

CoreModule::Color* CoreModule::Object3D::getColor() { return this->color; }

void CoreModule::Object3D::setPos(Maths::Vector3* pos) { this->pos = pos; }

void CoreModule::Object3D::setRot(Maths::Vector3* rot) { this->rot = rot; }

void CoreModule::Object3D::setColor(CoreModule::Color * color) { this->color = color; }
