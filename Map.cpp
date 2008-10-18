
// Map.cpp

#include "Map.h"
#include "File.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace WHX
{
	// class constructor
	MapCell::MapCell() : value_(0)
	{
	}
	
	// releases all memory used by the map cell
	MapCell::~MapCell()
	{
		value_ = 0;
	}
	
	// sets the value of the map cell
	void MapCell::SetValue(MapValue value)
	{
		value_ = value;
	}
	
	// gets the value of the map cell
	MapValue MapCell::GetValue()
	{
		return value_;
	}
	
	// class constructor
	Map::Map(int width, int height) :
		width_(width),
		height_(height),
		data_(0)
	{
		data_ = new MapCell [width_ * height_];
	}
	
	// releases all memory used by the map
	Map::~Map()
	{
		if (0 != data_)
		{
			delete [] data_;
			data_ = 0;
		}
	}
	
	// loads a map from a file
	// returns false if a failure occured, and true if loading succeeds
	bool Map::Load(const char* pathName)
	{
		File* file = File::OpenForReading(pathName, WHX::BINARY_MODE);
		if (0 != file)
		{
			fprintf(stderr, "Loading Map Data from %s\n", pathName);
			int x = 0, y = 0;
			for (y = 0; y < height_; y++)
			{
				for (x = 0; x < width_; x++)
				{
					// fprintf(stderr, ".");
					data_[x + (y * width_)].SetValue( (MapValue) file->GetByte());
				}
			}
			fprintf(stderr, "%d Bytes of Map Data Loaded\n", (x * y));
			File::Close(file);
			return true;
		}
		return false;
	}
	
	// returns a reference to the requested map cell
	MapCell& Map::GetCell(int x, int y)
	{
		// we assume that the x and y are in range.
		return data_[x + (y * width_)];
	}
	
	// call this to create a map
	// returns 0 if a failure occured, and a pointer to a new map if loading succeeds
	Map* Map::CreateFromFile(int width, int height, const char* pathName)
	{
		Map* map = new Map(width, height);
		
		fprintf(stderr, "New Map Created From File: %s Size %d x %d\n", pathName, width, height);
		
		if (map->Load(pathName))
		{
			return map;
		}
		return 0;
	}
	
	// call this to destroy a map when you are done with it
	void Map::Destroy(Map* map)
	{
		if (0 != map)
		{
			delete map;
			map = 0;
		}
		fprintf(stderr, "Map Destroyed\n");
	}
	
	
	
} // end namespace

