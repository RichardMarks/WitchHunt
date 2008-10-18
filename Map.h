
// Map.h

#ifndef __WHX_MAP_H__
#define __WHX_MAP_H__

namespace WHX
{
	typedef unsigned char MapValue;
	class MapCell
	{
	public:
		MapCell();
		~MapCell();
		void SetValue(MapValue value);
		MapValue GetValue();
	private:
		// hide copy constructor and assignment operators
		// to prevent users from abusing the class
		MapCell(const MapCell& rhs){}
		MapCell& operator=(const MapCell& rhs){return *this;}
		
		MapValue value_;
	}; // end class
	
	class Map
	{
	public:
		// class constructor
		Map(int width, int height);
		
		// releases all memory used by the map
		~Map();
		
		// loads a map from a file
		bool Load(const char* pathName);
		
		// returns a reference to the requested map cell
		MapCell& GetCell(int x, int y);
		
		// call this to create a map
		static Map* CreateFromFile(int width, int height, const char* pathName);
		
		// call this to destroy a map when you are done with it
		static void Destroy(Map* map);
		
	private:
		// hide copy constructor and assignment operators
		// to prevent users from abusing the class
		Map(const Map& rhs){}
		Map& operator=(const Map& rhs){return *this;}
		
		int width_; // width of the map
		int height_; // height of the map
		MapCell* data_; // the actual map data array
	}; // end class

} // end namespace

#endif
