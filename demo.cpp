
// demo.cpp

#include <allegro.h>

#include "Surface.h"
#include "VirtualScreen.h"
#include "Map.h"


#include <cstdlib>
#include <cstdio>
#include <cstring>

#define TILE_SZ			8
#define SCREEN_WIDTH	(TILE_SZ * 80)
#define SCREEN_HEIGHT	(TILE_SZ * 25)
#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600
#define MAP_WIDTH		72
#define MAP_HEIGHT		72
#define CAM_WIDTH		35
#define CAM_HEIGHT		35
using namespace WHX;

class Demo
{
public:
	Demo();
	~Demo();
	
	int Initialize(int argc, char* argv[]);
	int Execute();
	
	void Render();
private:
	Surface* backBuffer_;
	VirtualScreen* display_;
	Map* map_;
	int cameraX_;
	int cameraY_;
};

Demo::Demo() :
	backBuffer_(0),
	display_(0),
	map_(0),
	cameraX_(0),
	cameraY_(0)
{
}

Demo::~Demo()
{
	VirtualScreen::Destroy(display_);
	Surface::Destroy(backBuffer_);
	Map::Destroy(map_);
}

int Demo::Initialize(int argc, char* argv[])
{
	allegro_init();
	install_keyboard();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
	set_window_title("WHX TCT MapViewer v1.0");
	
	fprintf(stderr, "Allegro Initialized.\n");
	
	backBuffer_ = Surface::Create(SCREEN_W, SCREEN_H);
	
	display_ = VirtualScreen::Create(80, 50);
	
	map_ = Map::CreateFromFile(MAP_WIDTH, MAP_HEIGHT, (const char*)argv[1]);
	
	if (0 == map_)
	{
		fprintf(stderr, "Fatal Error. Cannot Load world_map.map!\n");
		exit(1);
	}
	
	fprintf(stderr, "Map File Loaded.\n");
	
	return 1;
}

void Demo::Render()
{
	// clear the backbuffer
	clear(backBuffer_->Image());
	
	for (int y = cameraY_; y < cameraY_ + CAM_HEIGHT; y++)
	{	
		// fprintf(stderr, "Writing Map to VirtualScreen: ROW: %3d\n", y);
	
		for (int x = cameraX_; x < cameraX_ + CAM_WIDTH; x++)
		{
			// fprintf(stderr, "\tWriting Map to VirtualScreen: COLUMN: %3d\n", x);
			MapCell& cell = map_->GetCell(x, y);
			display_->Write((unsigned char)cell.GetValue(), x - cameraX_, y - cameraY_);
		}
	}
	
	// render the virtual screen to the backbuffer
	display_->Render(backBuffer_);
	
	// render the backbuffer to the screen
	blit(backBuffer_->Image(), screen, 0, 0, 0, 0, backBuffer_->Image()->w, backBuffer_->Image()->h);	
}

int Demo::Execute()
{
	while(!key[KEY_ESC])
	{
		if (keyboard_needs_poll())
		{
			poll_keyboard();
		}
		
		if (key[KEY_UP])
		{
			if (cameraY_ - 1 > 0)
			{
				cameraY_--;
			}
		}
		
		if (key[KEY_DOWN])
		{
			if (cameraY_ + 1 < (MAP_HEIGHT - 1) - CAM_HEIGHT)
			{
				cameraY_++;
			}
		}
		
		if (key[KEY_LEFT])
		{
			if (cameraX_ - 1 > 0)
			{
				cameraX_--;
			}
		}
		
		if (key[KEY_RIGHT])
		{
			if (cameraX_ + 1 < (MAP_WIDTH - 1) - CAM_WIDTH)
			{
				cameraX_++;
			}
		}
		
		Render();
		
	}
	
	return 0;
}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, 
			"WHX TCT MapViewer v1.0\n"
			"(C) Copyright 2008, CCPS Solutions\n"
			"Developed by Richard Marks\n"
			"ccpsceo@gmail.com\n"
			"\nRuntime Error: Not Enough Arguments\n"
			"Usage: %s mapfile\n", argv[0]);
		return -1;
	}
	
	fprintf(stderr, 
		"WHX TCT MapViewer v1.0\n"
		"(C) Copyright 2008, CCPS Solutions\n"
		"Developed by Richard Marks\n"
		"ccpsceo@gmail.com\n");
	
	Demo* demo = new Demo();
	int result = demo->Initialize(argc, argv);
	if (result)
	{
		result = demo->Execute();
	}
	delete demo;
	return result;
}

