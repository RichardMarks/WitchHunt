
// File.cpp

#include "File.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace WHX
{
	
	// initializes a file handle
	File::File(const char* pathName, const char* mode) :
		file_(0),
		fileOpen_(false)
	{
		file_ = fopen(pathName, mode);
		if (0 != file_)
		{
			fileOpen_ = true;
			fprintf(stderr, "File: %s opened\n", pathName);
		}
	}
	
	// release memory used by file
	File::~File()
	{
		if (fileOpen_)
		{
			fclose(file_);
			fprintf(stderr, "File Closed\n");
		}
		file_ = 0;
	}
	
	// returns a single byte read from the open file
	unsigned char File::GetByte()
	{
		if (fileOpen_)
		{
			return (unsigned char) fgetc(file_);
		}
		else
		{
			// fail
			fprintf(stderr, "Fatal Error: Attempted to read a byte from a file that is not open!\n");
			exit(1);
		}
	}
	
	// returns the open status of the file
	bool File::IsOpen()
	{
		return fileOpen_;
	}
	
	// opens a file for reading
	File* File::OpenForReading(const char* pathName, const unsigned char mode)
	{
		File* file = 0;
		switch(mode)
		{
			case WHX::BINARY_MODE:
			{
				file = new File(pathName, "rb");
			} break;
			case WHX::TEXT_MODE:
			{
				file = new File(pathName, "r");
			} break;
			default: break; // error!
		}
		
		fprintf(stderr, "New File Object Created\n");
		
		return file;
	}
	
	// opens a file for writing
	File* File::OpenForWriting(const char* pathName, const unsigned char mode)
	{
		File* file = 0;
		
		return file;
	}
	
	// closes an open file
	void File::Close(File* file)
	{
		if (0 != file)
		{
			delete file;
			file = 0;
		}
		fprintf(stderr, "File Object Destroyed\n");
	}
	
} // end namespace

