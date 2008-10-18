
// Surface.cpp

#include <allegro.h>
#include "Surface.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace WHX
{
	Surface::Surface() :
		image_(0),
		exists_(false)
	{
	}
	
	Surface::~Surface()
	{
		if (0 != image_)
		{
			destroy_bitmap(image_);
			image_ = 0;
		}
		exists_ = false;
	}
	
	bool Surface::Exists()
	{
		return exists_;
	}
	
	BITMAP* Surface::Image()
	{
		return image_;
	}
	
	Surface* Surface::Create(int width, int height)
	{
		Surface* newSurface = new Surface();
		newSurface->image_ = create_bitmap(width, height);
		newSurface->exists_ = true;
		
		// fprintf(stderr, "New Surface Created\n");
		
		return newSurface;
	}
	
	Surface* Surface::LoadBitmap(const char* path)
	{
		Surface* newSurface = new Surface();
		newSurface->image_ = load_bitmap(path, 0);
		newSurface->exists_ = true;
		return newSurface;
	}
	
	void Surface::Destroy(Surface* surface)
	{
		if (surface->Exists())
		{
			destroy_bitmap(surface->image_);
			surface->image_ = 0;
			delete surface;
			surface = 0;
		}
		
		// fprintf(stderr, "Surface Destroyed\n");
	}
	
	void Surface::Blit(Surface* source, Surface* destination, int sourceX, int sourceY, int destX, int destY, int width, int height)
	{
		blit(source->image_, destination->image_,
			sourceX, sourceY,
			destX, destY,
			width, height);
	}
			
} // end namespace

