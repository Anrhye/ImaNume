#include "Scene.h"
#include "lib\FreeImage\FreeImage.h"

CoreModule::Scene::Scene() { }

CoreModule::Scene::Scene(Camera * camera, std::vector<CoreModule::Object3D*> objects, std::vector<CoreModule::Light*> lights)
{
	this->camera = camera;
	this->objects = objects;
	this->lights = lights;
}

int CoreModule::Scene::getWidth() { return this->width; }

int CoreModule::Scene::getHeight() { return this->height; }

void CoreModule::Scene::setWidth(int w) { this->width = w; }

void CoreModule::Scene::setHeight(int h) { this->height = h; }

void CoreModule::Scene::addObject(CoreModule::Object3D* obj) { this->objects.push_back(obj); }

void CoreModule::Scene::addSphere(CoreModule::Sphere* sph)
{ 
	this->spheres.push_back(sph); 
	std::cout << "adding one sphere.\n" << std::endl;
}

void CoreModule::Scene::addLight(CoreModule::Light* light) 
{
	this->lights.push_back(light);
	std::cout << "adding one light.\n" << std::endl;
}

void CoreModule::Scene::renderSpheres()
{
	//FreeImage_Initialise();

	FIBITMAP* fiBitMap = FreeImage_Allocate(this->width, this->height, 32,
		FI_RGBA_RED_MASK, FI_RGBA_GREEN_MASK, FI_RGBA_BLUE_MASK);

	if(!fiBitMap)	return;

	BYTE* byteLine;
	CoreModule::Color* color = new Color(new Maths::Vector3(0, 0, 0));
	Maths::Vector3 intersect, tmp_intersect, normdVector;
	int fiWidth  = FreeImage_GetWidth(fiBitMap);
	int fiHeight = FreeImage_GetHeight(fiBitMap);
	int bitPerPixel = FreeImage_GetLine(fiBitMap) / fiWidth;
	int tmpIdx = 0;
	double ratio, tmp_ratio = 0.0f;
	double lengthInter;
	double tmp_lengthInter;
	double const tanh = tan((70.0f * 3.14) / 180.0f);

	std::cout << "\n\nRendering Image.." << std::endl;

	// for each line
	for(int line = 0; line < fiHeight; line++)
	{
		// retrieves line
		byteLine = FreeImage_GetScanLine(fiBitMap, line);

		// each column of the line -> for each pixel
		for( int col = 0; col < fiWidth; col++)
		{
			intersect     = Maths::Vector3(0.0f, 0.0f, 0.0f);
			tmp_intersect = Maths::Vector3(0.0f, 0.0f, 0.0f);

			// for each objects
			// retrieves every intersections, only keeps the one in front of the camera and keeps its index
			for(unsigned int i = 0; i < this->spheres.size(); i++)
			{
				normdVector = Maths::Vector3::normalize( Maths::Vector3( (double)col - (double)(fiWidth / 2.0f),
																		 (double)line - (double)(fiHeight / 2.0f),
																	     tanh * (double)(fiWidth / 2.0f) ) );
				intersect = this->spheres.at(i)->intersectStraightLine(normdVector, Maths::Vector3(0.0f, 0.0f, 0.0f));

				lengthInter = Maths::Vector3::length(intersect);
				tmp_lengthInter = Maths::Vector3::length(tmp_intersect);

				// is the intersection of this objects in front
				if(lengthInter != 0.0f && (tmp_lengthInter == 0.0f || lengthInter < tmp_lengthInter))
				{
					tmp_intersect = intersect;
					// recalculating the normal when updated
					tmp_lengthInter = Maths::Vector3::length(tmp_intersect);
					tmpIdx = i;
				}
			}

			if(tmp_lengthInter != 0.0f)
			{
				// apply light effect
				if(this->lights.at(0)->direct(tmp_intersect, this->spheres))
				{
					tmp_ratio = 0.0f;

					Maths::Vector3 u = Maths::Vector3::normalize(tmp_intersect);

					Maths::Vector3* spherePos = spheres.at(tmpIdx)->getPos();
					Maths::Vector3* ligthPos = lights.at(0)->getPos();

					Maths::Vector3 v = Maths::Vector3::normalize(Maths::Vector3(spherePos->getX() - tmp_intersect.getX(),
																				spherePos->getY() - tmp_intersect.getY(),
																				spherePos->getZ() - tmp_intersect.getZ()));
					Maths::Vector3 s = Maths::Vector3::reflect(u, v);

					Maths::Vector3 reflectedV = Maths::Vector3::normalize(s);
					Maths::Vector3 vDirLight  = Maths::Vector3::normalize( Maths::Vector3(ligthPos->getX() - tmp_intersect.getX(),
																						  ligthPos->getY() - tmp_intersect.getY(),
																						  ligthPos->getZ() - tmp_intersect.getZ()));
					color = spheres.at(tmpIdx)->getColor();

					ratio = Maths::Vector3::scalaire(reflectedV, vDirLight);

					if(ratio < 0.0f)	ratio = 0.0f;

					if(tmp_ratio < ratio)	tmp_ratio = ratio;

					if(color->getR() * tmp_ratio > 255.0f)	byteLine[FI_RGBA_RED] = 255;
					else
						if (color->getR() * tmp_ratio < 0.0f)	byteLine[FI_RGBA_RED] = 0;
						else	byteLine[FI_RGBA_RED] = (int)(color->getR() * tmp_ratio);

					if(color->getG() * tmp_ratio > 255.0f)	byteLine[FI_RGBA_GREEN] = 255;
					else
						if (color->getG() * tmp_ratio < 0.0f)	byteLine[FI_RGBA_GREEN] = 0;
						else	byteLine[FI_RGBA_GREEN] = (int)(color->getG() * tmp_ratio);

					if(color->getB() * tmp_ratio > 255.0f)	byteLine[FI_RGBA_BLUE] = 255;
					else
						if(color->getB() * tmp_ratio < 0.0f)	byteLine[FI_RGBA_BLUE] = 0;
						else	byteLine[FI_RGBA_BLUE] = (int)(color->getB() * tmp_ratio);

				}
				else
				{
					byteLine[FI_RGBA_RED]   = 0;
					byteLine[FI_RGBA_GREEN] = 0;
					byteLine[FI_RGBA_BLUE]  = 0;
				}
			}
			else
			{
				//background color
				byteLine[FI_RGBA_RED]   = 38;
				byteLine[FI_RGBA_GREEN] = 38;
				byteLine[FI_RGBA_BLUE]  = 38;
			}

			// no transparency
			byteLine[FI_RGBA_ALPHA] = 255;

			byteLine += bitPerPixel;
		}

	}

	std::string name = "output/";
	name.append(std::to_string(time(NULL)));
	name.append(".bmp");

	if(!FreeImage_Save(FIF_BMP, fiBitMap, name.c_str(), 0))
		std::cout << "ECHEC CREATION IMAGE" << std::endl;

	FreeImage_Unload(fiBitMap);

	return;
}
