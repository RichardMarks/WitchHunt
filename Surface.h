
// Surface.h

#ifndef __WHX_SURFACE_H__
#define __WHX_SURFACE_H__
struct BITMAP;

namespace WHX
{	
	class Surface
	{
	public:
		Surface();
		~Surface();
		
		bool Exists();
		BITMAP* Image();
		static Surface* Create(int width, int height);
		static Surface* LoadBitmap(const char* path);
		static void Destroy(Surface* surface);
		static void Blit(Surface* source, Surface* destination, int sourceX, int sourceY, int destX, int destY, int width, int height);
		
	private:
		// hide copy constructor and assignment operators
		// to prevent users from abusing the class
		Surface(const Surface& rhs){}
		Surface& operator=(const Surface& rhs){return *this;}
		
		BITMAP* image_;
		bool exists_;
	}; // end class
} // end namespace

#endif

