#include "Color.h"

CoreModule::Color::Color() { }

CoreModule::Color::Color(Maths::Vector3* rgb) {	this->rgb = rgb; }

CoreModule::Color::Color(Maths::Vector3* rgb, double alpha)
	: Color(rgb) { this->alpha = alpha; }

double CoreModule::Color::getR() {	return this->rgb->getX();	}

double CoreModule::Color::getG() {	return this->rgb->getY();	}

double CoreModule::Color::getB() {	return this->rgb->getZ();	}

double CoreModule::Color::getA() { return this->alpha; }

Maths::Vector3* CoreModule::Color::getRGB() { return this->rgb; }

void CoreModule::Color::setR(double red) { this->rgb->setX(red); }

void CoreModule::Color::setG(double green) { this->rgb->setY(green); }

void CoreModule::Color::setB(double blue) { this->rgb->setZ(blue); }

void CoreModule::Color::setA(double alpha) { this->alpha = alpha; }

void CoreModule::Color::setRGB(Maths::Vector3* rgb) { this->rgb = rgb; }

void CoreModule::Color::setRGBA(Maths::Vector3* rgb, double alpha)
{ 
	this->setRGB(rgb);
	this->alpha = alpha;
}
