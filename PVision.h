// PVision library for interaction with the Pixart sensor on a WiiMote
// This work was derived from Kako's excellent Japanese website
// http://www.kako.com/neta/2007-001/2007-001.html

// Steve Hobley 2009 - www.stephenhobley.com

#ifndef PVision_h
#define PVision_h

#include "WConstants.h"
#include <Wire.h>

// bit flags for blobs
#define BLOB1 0x01
#define BLOB2 0x02
#define BLOB3 0x04
#define BLOB4 0x08


// Returned structure from a call to readSample()
struct Blob
{
   	int X;
   	int Y;
   	int Size;
   	byte number;
};

class PVision
{

public:
  	PVision();

	void init();   // returns true if the connection to the sensor established correctly
	byte read();   // updated the blobs, and returns the number of blobs detected

	// Make these public
	Blob Blob1;
	Blob Blob2;
	Blob Blob3;
	Blob Blob4;

private:
  	// per object data
	int IRsensorAddress;
	int IRslaveAddress;
	byte data_buf[16];
	int i;
	int s;

	void Write_2bytes(byte d1, byte d2);
	byte blobcount; // returns the number of blobs found - reads the sensor

};

// Arduino 0012 workaround
#undef int
#undef char
#undef long
#undef byte
#undef float
#undef abs
#undef round

#endif
