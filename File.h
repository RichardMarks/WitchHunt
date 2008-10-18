
// File.h

#ifndef __WHX_FILE_H__
#define __WHX_FILE_H__

struct _IO_FILE;

namespace WHX
{
	// constant open mode flags
	static const unsigned char BINARY_MODE = 'b';
	static const unsigned char TEXT_MODE = 't';
	
	class File
	{
	public:
		// initializes a file handle
		File(const char* pathName, const char* mode);
		
		// release memory used by file
		~File();
		
		// returns a single byte read from the open file
		unsigned char GetByte();
		
		// returns the open status of the file
		bool IsOpen();
		
		// opens a file for reading
		static File* OpenForReading(const char* pathName, const unsigned char mode);
		
		// opens a file for writing
		// *** unimplemented
		static File* OpenForWriting(const char* pathName, const unsigned char mode);
		
		// closes an open file
		static void Close(File* file);
		
	private:
		_IO_FILE* file_; // the actual file 
		bool fileOpen_; // open status of the file
	}; // end class

} // end namespace

#endif

