#include "Sphere.h"

CoreModule::Sphere::Sphere() {}

CoreModule::Sphere::Sphere(Maths::Vector3 * pos, double radius)
{
	this->pos = pos;
	this->radius = radius;
}

CoreModule::Sphere::Sphere(Maths::Vector3 * pos, double radius, CoreModule::Color* color)
	: Sphere(pos, radius) { this->color = color; }

double CoreModule::Sphere::getRadius() { return this->radius; }

void CoreModule::Sphere::setRadius(double radius) { this->radius = radius; }

Maths::Vector3 CoreModule::Sphere::intersectStraightLine(Maths::Vector3 normdVec, Maths::Vector3 origin)
{
	double d = -99;
	double normdX  = normdVec.getX(),        normdY  = normdVec.getY(),        normdZ  = normdVec.getZ();
	double originX = origin.getX(),          originY = origin.getY(),          originZ = origin.getZ();
	double sphereX = this->getPos()->getX(), sphereY = this->getPos()->getY(), sphereZ = this->getPos()->getZ();

	double x = originX - sphereX;
	double y = originY - sphereY;
	double z = originZ - sphereZ;

	double a = (pow(normdX, 2) + pow(normdY, 2) + pow(normdZ, 2));
	double b = 2 * (normdX * x + normdY * y + normdZ * z);
	double c = pow(x, 2) + pow(y, 2) + pow(z, 2) - pow(this->radius, 2);

	double x1 = 0.0f;
	double x2 = 0.0f;

	Maths::Vector3 intersection = Maths::Vector3(0, 0, 0);

	d = pow(b, 2) - (4 * a * c);

	if(d < 0.0f)	return intersection;

	double deno = 2 * a;
	double sqrtD = sqrt(d);
	
	x1 = (0.0f - b - sqrtD) / deno;
	x2 = (0.0f - b + sqrtD) / deno;

	if (x1 <= 0.0f && x2 <= 0.0f)	return intersection;

	double tmp_xx;

	if(x1 < x2 || x2 <= 0.0f)		tmp_xx = x1;
	else
		if(x2 < x1 || x1 <= 0.0f)	tmp_xx = x2;

	intersection.setX(normdX * tmp_xx + originX);
	intersection.setY(normdY * tmp_xx + originY);
	intersection.setZ(normdZ * tmp_xx + originZ);

	return intersection;
}
