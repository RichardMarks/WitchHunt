
// VirtualScreen.cpp

#include "Surface.h"
#include "VirtualScreen.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace WHX
{
	// initializes the virtual screen
	VirtualScreen::VirtualScreen(int width, int height) :
		width_(width),
		height_(height),
		ram_(0),
		cursorX_(0),
		cursorY_(0),
		font_(0)
	{
		ram_ = new unsigned char [width * height];
		Fill();// clear the initial screen
		
		font_ = new Surface* [256];
	
		// load the tiles from a single template image
		Surface* tempImage = Surface::LoadBitmap("font.bmp");
		for (int i = 0; i < 256; i++)
		{
			int x = 0 + (i / 16) * 8;
			int y = 0 + (i % 16) * 8;
			font_[i] = Surface::Create(8, 8);
			Surface::Blit(tempImage, font_[i], x, y, 0, 0, 8, 8);
		}
		Surface::Destroy(tempImage);
	}
	
	// releases all memory used by the virtual screen
	VirtualScreen::~VirtualScreen()
	{
		delete [] ram_;
		for (int i = 0; i < 256; i++)
		{
			Surface::Destroy(font_[i]);
		}
		delete [] font_;
	}
	
	// fills the virtual screen with a specified character
	// passing no param clears the virtual screen
	void VirtualScreen::Fill(int index)
	{
		for (int i = 0; i < width_ * height_; i++)
		{
			ram_[i] = (unsigned char) index;
		}
	}
	
	// fills a rectangluar area of the virtual screen with a specified
	// character. passing no character clears the rect
	void VirtualScreen::FillRect(int* rect, int index)
	{
		int l = rect[0];
		int t = rect[1];
		int r = rect[2];
		int b = rect[3];
	
		for (int y = t; y < t + b; y++)
		{
			for (int x = l; x < l + r; x++)
			{
				int p = x + (y * width_);
			
				if (p > width_ * height_ || p < 0)
				{
					fprintf(stderr, "Oh Shit! %8d, %8d = %8d\n", x, y, p);
				}
			
				ram_[p] = (unsigned char) index;
			}
		}
	}
	
	// prints the translated string to the virtual screen
	// at the specified location
	// not specifying a location will use the internal virtual
	// cursor position, and will update it
	void VirtualScreen::Print(unsigned char* data, int column, int row)
	{
		if (WHX_AUTOUPDATE_CURPOS != column)
		{
			int cx = (int)cursorX_;
			int sw = (int)width_;
			if (cx >= 0 && cx < sw)
			{
				cursorX_ = (unsigned char)column;
			}
		}
		
		if (WHX_AUTOUPDATE_CURPOS != row)
		{
			int cy = (int)cursorY_;
			int sh = (int)height_;
			if (cy >= 0 && cy < sh)
			{
				cursorY_ = (unsigned char)row;
			}
		}
		
		int n = 0;
		bool writing = true;
		while(writing)
		{
			switch(data[n])
			{
				case '\0':
				{
					writing = false;
					return;
				} break;
				
				case '\n':
				{
					// handle newlines smartly
					// if we can still move down, then do so,
					// if not, then we need to scroll the display
					// this will be tricky to do...
					cursorX_ = 0;
					
					if (cursorY_ + 1 < height_)
					{
						cursorY_++;
					}
					else
					{
						// scroll display
					}
					n++;
				} break;
				
				default:
				{
					int p = cursorX_ + (cursorY_ * width_);
			
					if (p > width_ * height_ || p < 0)
					{
						fprintf(stderr, "Oh Shit! %8d, %8d = %8d\n", cursorX_, cursorY_, p);
						break;
					}
					else
					{
						ram_[p] = (unsigned char) data[n];
					}
					cursorX_++;
					if (cursorX_ > width_ - 1)
					{
						cursorX_ = 0;
						if (cursorY_ + 1 < height_)
						{
							cursorY_++;
						}
						else
						{
							// scroll display
						}
					}
					
					n++;
				} break;
			} // end switch
		} // end while
	}
	
	// writes a single byte to the virtual screen at the specified location
	// not specifying a location will use the internal virtual
	// cursor position
	void VirtualScreen::Write(unsigned char data, int column, int row)
	{
		if (WHX_AUTOUPDATE_CURPOS != column)
		{
			int cx = (int)cursorX_;
			int sw = (int)width_;
			if (cx >= 0 && cx < sw)
			{
				cursorX_ = (unsigned char)column;
			}
		}
		
		if (WHX_AUTOUPDATE_CURPOS != row)
		{
			int cy = (int)cursorY_;
			int sh = (int)height_;
			if (cy >= 0 && cy < sh)
			{
				cursorY_ = (unsigned char)row;
			}
		}
		
		int p = cursorX_ + (cursorY_ * width_);

		if (p > width_ * height_ || p < 0)
		{
			fprintf(stderr, "Oh Shit! %8d, %8d = %8d\n", cursorX_, cursorY_, p);
			return;
		}
		ram_[p] = data;
	}
	
	// renders the virtual screen ram to the specified surface
	void VirtualScreen::Render(Surface* destination)
	{
		for (int y = 0; y < height_; y++)
		{
			for (int x = 0; x < width_; x++)
			{
				int character = ram_[x + (y * width_)];
			
				Surface::Blit(font_[character], destination, 0, 0, x * 8, y * 8, 8, 8);
			}
		}
	}
	
	// set the virtual cursor position
	void VirtualScreen::SetCursorPosition(int column, int row)
	{
		int cx = (int)cursorX_;
		int cy = (int)cursorY_;
		int sw = (int)width_;
		int sh = (int)height_;
		
		if (cx >= 0 && cx < sw)
		{
			cursorX_ = (unsigned char)column;
		}
		
		if (cy >= 0 && cy < sh)
		{
			cursorY_ = (unsigned char)row;
		}
	}
	
	// get the position of the virtual cursor
	int VirtualScreen::GetCursorX()
	{
		return cursorX_;
	}
	
	int VirtualScreen::GetCursorY()
	{
		return cursorY_;
	}
	
	// translates a string to a chunk of data that can be printed
	// on the virtual screen.
	// make sure that you do not forget to delete the pointer
	// when you are finished with it.
	unsigned char* VirtualScreen::TranslateString(const char* text)
	{
		int textLen = strlen(text);
		unsigned char* translated = new unsigned char [textLen + 1];
		for (int i = 0; i < textLen; i++)
		{
			translated[i] = (unsigned char) text[i];
		}
		translated[textLen + 1] = '\0';
		return translated;
	}
	
	// call this for any translated strings you have created and are
	// finished with.
	void VirtualScreen::DestroyString(unsigned char* translated)
	{
		if (0 != translated)
		{
			delete [] translated;
		}
	}
	
	// call this to create a virtual screen
	VirtualScreen* VirtualScreen::Create(int width, int height)
	{
		fprintf(stderr, "New VirtualScreen Created\n");
		return new VirtualScreen(width, height);
	}
	
	// call this to destroy the virtual screen when you are done with it
	void VirtualScreen::Destroy(VirtualScreen* vScreen)
	{
		if (0 != vScreen)
		{
			delete vScreen;
			vScreen = 0;
			fprintf(stderr, "VirtualScreen Destroyed\n");
		}
	}

}; // end namespace

