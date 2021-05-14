#include "Light.h"

CoreModule::Light::Light()
{
}

CoreModule::Light::Light(Maths::Vector3 * pos) { this->pos = pos; }

bool CoreModule::Light::direct(Maths::Vector3 inter, std::vector<Sphere*> spheres)
{
	Maths::Vector3 tmp_inter = Maths::Vector3(0.0f, 0.0f, 0.0f);
	Maths::Vector3 x = Maths::Vector3( this->pos->getX() - inter.getX(), this->pos->getY() - inter.getY(), this->pos->getZ() - inter.getZ());
	double length_x = Maths::Vector3::length(x);
	Maths::Vector3 y = Maths::Vector3( inter.getX() + (x.getX() / length_x) / 100.0f,
									   inter.getY() + (x.getY() / length_x) / 100.0f,
									   inter.getZ() + (x.getZ() / length_x) / 100.0f );

	for(int i = 0; i < spheres.size(); i++)
	{
		tmp_inter = spheres.at(i)->intersectStraightLine(Maths::Vector3::normalize(x), y);		

		Maths::Vector3* spherePos = spheres.at(i)->getPos();

		if(Maths::Vector3::length(Maths::Vector3( y.getX() - spherePos->getX(),
												  y.getY() - spherePos->getY(),
												  y.getZ() - spherePos->getZ() ) ) < spheres.at(i)->getRadius() )
			return false;


		if((tmp_inter.getX() != 0.0f || tmp_inter.getY() != 0.0f || tmp_inter.getZ() != 0.0f ) &&
		   length_x >= Maths::Vector3::length(Maths::Vector3(tmp_inter.getX() - inter.getX(),
															 tmp_inter.getY() - inter.getY(),
															 tmp_inter.getZ() - inter.getZ() )))
				return false;
	}
	return true;
}
