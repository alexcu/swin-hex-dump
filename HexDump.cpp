//
//  Assignment 3
//  COS30008 - DSP
//
//  Alex Cummaudo, 1744070
//  2014-03-31
//
#include "HexDump.h"

bool HexDump::open(const std::string &aInputFileName)
{
  // Attempt to open the file name into fInput for reading in binary mode
  fInput.open(aInputFileName, std::ifstream::binary);

  // Return whether or not the file was successfully opened
  return fInput.good();
}

void HexDump::HexDump::close()
{
  // Close the input stream
  fInput.close();
}

void HexDump::processInput()
{
  // We assume that processInput will only be called if HexDump opened succesfully (i.e.,
  // as per the if statement in main.cpp)
  
  // Constants to allow us to change the buffer size
  const int lBufferSz = 16;
  // Where we read our data into
  unsigned char lBuffer[lBufferSz];
  
  // While data is avaliable (i.e., while I haven't reached the eof or I haven't failed)
  while (!fInput.eof() && !fInput.fail())
  {
    // Print out the address of the current position where fInput is getting input from
    std::cout
              // Format eight zeros beforehand for address
              // pointer by setting a fill of 8 '0's
              << std::setfill('0') << std::setw(8)
              // Convert to uppercase hex fInput's get file pointer location
              << std::uppercase << std::hex  << fInput.tellg() << ":  ";
    
    // Read in the input in lBufferSz byte chunks into the buffer at the current location
    // I am up to (moves to the next address after I do this)
    fInput.read((char*)lBuffer, lBufferSz);
    
    // Should print separator if greater than 8 for gcount read
    bool lPrintSeparator = fInput.gcount() >= 8;
    
    // For this chunk read (note, used gcount to show the characters ACTUALLY
    // read, not the n characters desired to be read (i.e., not i < lBufferSz))
    // (note the failbit would be high if lBufferSz was not read (i.e., fInput.fail()))
    for (int i = 0; i < fInput.gcount(); i++)
    {
      std::cout
                // Format w/ 2 zeros beforehand
                << std::setfill('0') << std::setw(2)
                // The hex representation of this character (casted to an int)
                << std::hex << (int)lBuffer[i]
                // Print separator on seventh index if indicated
                // otherwise, just print a one-space separator
                << (lPrintSeparator && i == 7 ? " | " : " ");
    }
    
    // Haven't reached the end? Print a whitespace buffer
    if (fInput.gcount() < lBufferSz)
    {
      // Set whitespace fill to 3 char spaces ("FF ") for every
      // hex byte I missed out on plus one for the separator '|' if
      // we did print the separator, otherwise 3 if we didn't need
      // one to make up for the missing ' | '
      int lWhiteSpaceCount = 3*(lBufferSz - (int)fInput.gcount()) + (lPrintSeparator ? 1 : 3);
      std::cout << std::setfill(' ') << std::setw(lWhiteSpaceCount);
    }
    std::cout << " ";
    
    // For this chunk read (again, using gcount)
    for (int i = 0; i < fInput.gcount(); i++)
    {
      // Print . if not this char is not printable, else print this char
      // casted as a char---use isgraph to disclude spaces from check
      std::cout << ( isgraph((int)lBuffer[i]) ? (char)lBuffer[i] : '.' );
    }
    std::cout << std::endl;
  }
}