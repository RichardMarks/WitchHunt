
// VirtualScreen.h

#ifndef __WHX_VIRTUAL_SCREEN_H__
#define __WHX_VIRTUAL_SCREEN_H__

namespace WHX
{
	#define WHX_AUTOUPDATE_CURPOS -1
	class Surface;
	class VirtualScreen
	{
	public:
		// initializes the virtual screen
		VirtualScreen(int width, int height);
		
		// releases all memory used by the virtual screen
		~VirtualScreen();
		
		// fills the virtual screen with a specified character
		// passing no param clears the virtual screen
		void Fill(int index = 32);
		
		// fills a rectangluar area of the virtual screen with a specified
		// character. passing no character clears the rect
		void FillRect(int* rect, int index = 32);
		
		// prints the translated string to the virtual screen
		// at the specified location
		// not specifying a location will use the internal virtual
		// cursor position, and will update it
		void Print(unsigned char* data, int column = WHX_AUTOUPDATE_CURPOS, int row = WHX_AUTOUPDATE_CURPOS);
		
		// writes a single byte to the virtual screen at the specified location
		// not specifying a location will use the internal virtual
		// cursor position
		void Write(unsigned char data, int column = WHX_AUTOUPDATE_CURPOS, int row = WHX_AUTOUPDATE_CURPOS);
		
		// renders the virtual screen ram to the specified surface
		void Render(Surface* destination);
		
		// set the virtual cursor position
		void SetCursorPosition(int column, int row);
		
		// get the position of the virtual cursor
		int GetCursorX();
		int GetCursorY();
		
		// translates a string to a chunk of data that can be printed
		// on the virtual screen.
		// make sure that you do not forget to delete the pointer
		// when you are finished with it.
		static unsigned char* TranslateString(const char* text);
		
		// call this for any translated strings you have created and are
		// finished with.
		static void DestroyString(unsigned char* translated);
		
		// call this to create a virtual screen
		static VirtualScreen* Create(int width, int height);
		
		// call this to destroy the virtual screen when you are done with it
		static void Destroy(VirtualScreen* vScreen);
		
	private:
		// hide copy constructor and assignment operators
		// to prevent users from abusing the class
		VirtualScreen(const VirtualScreen& rhs){}
		VirtualScreen& operator=(const VirtualScreen& rhs){return *this;}
		
		unsigned char width_; // number of columns in the virtual screen
		unsigned char height_; // number of rows in the virtual screen
		unsigned char* ram_; // the virtual screen ram
		unsigned char cursorX_; // the column where the virtual cursor is located
		unsigned char cursorY_; // the row where the virtual cursor is located
		Surface** font_; // the list of images that are used to draw each character
		
	}; // end class

} // end namespace

#endif

