
// FontEngine.cpp
// Bitmapped Font Engine
// by Richard Marks ccpsceo@gmail.com
// (C) Copyright 2008, CCPS Solutions
// http://www.ccpssolutions.com

// FontEngine depends on the Surface and Color classes
// but since we do not have them yet, just define them here
// note: these are non functional placeholder classes


// #include "Color.h"

class Color 
{
public:
	void CloneFrom(Color* source) {}
};

// #include "Surface.h"

#include <cstring>

class Surface 
{
public:
	bool LoadFromImage(char* pathName) { return true; }
	void SetColorKey(Color* color) {}
	int GetWidth() { return 0; }
	int GetHeight() { return 0; }
	void Blit(Surface* desintation, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight) {}
	void SetSize(int width, int height) {}
	void Fill(Color* color) {}
	void ReplaceColor(Color* fromColor, Color* toColor) {}
};

#include "FontEngine.h"

FontEngine::FontEngine() :
	width_(0),
	height_(0),
	letterWidth_(0),
	letterHeight_(0),
	lettersPerRow_(0),
	fontSurface_(0),
	currentColor_(0),
	colorKey_(0),
	loaded_(false)
{
}

FontEngine::~FontEngine()
{
	if (0 != fontSurface_)
	{
		delete fontSurface_;
		fontSurface_ = 0;
	}
	
	if (0 != currentColor_)
	{
		delete currentColor_;
		currentColor_ = 0;
	}
	
	if (0 != colorKey_)
	{
		delete colorKey_;
		colorKey_ = 0;
	}
}

bool FontEngine::LoadFont(char* pathName, int letterWidth, int letterHeight, Color* colorKey)
{
	if ((letterWidth > 4) && (letterHeight > 4))
	{
		fontSurface_ = new Surface();
		if (!fontSurface_->LoadFromImage(pathName))
		{
			loaded_ = false;
		}
		if (0 != colorKey)
		{
			fontSurface_->SetColorKey(colorKey);
			colorKey_ = new Color();
			colorKey_->CloneFrom(colorKey);
		}
		width_ = fontSurface_->GetWidth();
		height_ = fontSurface_->GetHeight();
		letterWidth_ = letterWidth;
		letterHeight_ = letterHeight_;
		lettersPerRow_ = (int)(width_ / letterWidth_);
		loaded_ = true;
	}
	else
	{
		throw FontEngineError("Cannot Create a Font That Small!");
	}
	return loaded_;
}

void FontEngine::Colorize(Color* newColor)
{
	if (!loaded_)
	{
		throw FontEngineError("Cannot Colorize a Font that does not exist!");
	}
	
	if (0 != newColor)
	{
		fontSurface_->ReplaceColor(currentColor_, newColor);
		currentColor_->CloneFrom(newColor);
	}
}

void FontEngine::RenderChar(Surface* surface, int x, int y, char c)
{
	if (!loaded_)
	{
		throw FontEngineError("Cannot Render Characters with a Font that does not exist!");
	}
	
	if (0 == surface)
	{
		throw FontEngineError("Cannot Render to an Invalid Surface!");
	}

	int offsetX = (int)((int)c / lettersPerRow_) * letterHeight_;
	int offsetY = (int)((int)c % lettersPerRow_) * letterHeight_;
	
	surface->Blit(fontSurface_, x, y, offsetX, offsetY, letterWidth_, letterHeight_);
}

void FontEngine::RenderString(Surface* surface, int x, int y, char* text, int gap)
{
	if (!loaded_)
	{
		throw FontEngineError("Cannot Render Characters with a Font that does not exist!");
	}
	
	if (0 == surface)
	{
		throw FontEngineError("Cannot Render to an Invalid Surface!");
	}
	
	int originX = x;
	int nextX = x;
	int textLength = (int)strlen(text);
	
	for (int i = 0; i < textLength; i++)
	{
		switch(text[i])
		{
			case '\n': // handle the new line
			{
				nextX = originX;
				y += (letterHeight_ + 2);
			} break;
			
			default:
			{
				int charX = nextX + (int)(letterWidth_ * i);
				int offsetX = (int)((int)text[i] / lettersPerRow_) * letterHeight_;
				int offsetY = (int)((int)text[i] % lettersPerRow_) * letterHeight_;
				surface->Blit(fontSurface_, charX, y, offsetX, offsetY, letterWidth_, letterHeight_);
				nextX += gap;
			} break;
		}
	}
}

Surface* FontEngine::RenderStringSurface(char* text, int gap)
{
	if (!loaded_)
	{
		throw FontEngineError("Cannot Render Characters with a Font that does not exist!");
	}
	
	Surface* surface = new Surface();
	
	// determine the dimensions of the new surface
	
	// count the number of new lines in the string
	int textLength = (int)strlen(text);
	int newLines = 0;
	for (int i = 0; i < textLength; i++)
	{
		if ('\n' == text[i])
		{
			newLines++;
		}
	}
	
	textLength -= newLines;
	int width = (int)(textLength * letterWidth_) + (int)(gap * (textLength - 1));
	int height = (int)(2 + (int)(letterHeight_ * newLines) + (int)(gap * newLines));
	textLength += newLines;
	
	surface->SetSize(width, height);
	surface->SetColorKey(colorKey_);
	surface->Fill(colorKey_);
	
	int y = 0;
	int originX = 0;
	int nextX = 0;
	
	for (int i = 0; i < textLength; i++)
	{
		switch(text[i])
		{
			case '\n': // handle the new line
			{
				nextX = originX;
				y += (letterHeight_ + 2);
			} break;
			
			default:
			{
				int charX = nextX + (int)(letterWidth_ * i);
				int offsetX = (int)((int)text[i] / lettersPerRow_) * letterHeight_;
				int offsetY = (int)((int)text[i] % lettersPerRow_) * letterHeight_;
				surface->Blit(fontSurface_, charX, y, offsetX, offsetY, letterWidth_, letterHeight_);
				nextX += gap;
			} break;
		}
	}
	
	return surface;
}

bool FontEngine::GetLoaded()
{
	return loaded_;
}

int FontEngine::GetWidth()
{
	return width_;
}

int FontEngine::GetHeight()
{
	return height_;
}

int FontEngine::GetLetterWidth()
{
	return letterWidth_;
}

int FontEngine::GetLetterHeight()
{
	return letterHeight_;
}

int FontEngine::GetLettersPerRow()
{
	return lettersPerRow_;
}

Surface* FontEngine::GetFontSurface()
{
	return fontSurface_;
}

Color* FontEngine::GetFontColor()
{
	return currentColor_;
}

Color* FontEngine::GetFontColorKey()
{
	return colorKey_;
}

