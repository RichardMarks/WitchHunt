
// FontEngine.h
// Bitmapped Font Engine
// by Richard Marks ccpsceo@gmail.com
// (C) Copyright 2008, CCPS Solutions
// http://www.ccpssolutions.com

#ifndef __FONTENGINE_H__
#define __FONTENGINE_H__

class FontEngineError
{
public:
	FontEngineError(const char* message) : message_(message) {}
	~FontEngineError() {}
	const char* GetMessage() const { return message_; }
private:
	const char* message_;
};

class Surface;
class Color;

class FontEngine
{
public:
	FontEngine();
	~FontEngine();
	
	bool LoadFont(char* pathName, int letterWidth, int letterHeight, Color* colorKey = 0);
	void Colorize(Color* newColor = 0);
	void RenderChar(Surface* surface, int x, int y, char c);
	void RenderString(Surface* surface, int x, int y, char* text, int gap = 0);
	Surface* RenderStringSurface(char* text, int gap = 0);
	bool GetLoaded();
	int GetWidth();
	int GetHeight();
	int GetLetterWidth();
	int GetLetterHeight();
	int GetLettersPerRow();
	Surface* GetFontSurface();
	Color* GetFontColor();
	Color* GetFontColorKey();
	
private:
	bool loaded_;
	int width_;
	int height_;
	int letterWidth_;
	int letterHeight_;
	int lettersPerRow_;
	Surface* fontSurface_;
	Color* currentColor_;
	Color* colorKey_;
};

#endif

