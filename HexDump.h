//
//  Assignment 3
//  COS30008 - DSP
//
//  Alex Cummaudo, 1744070
//  2014-03-31
//
#ifndef __A3__HexDump__
#define __A3__HexDump__

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class HexDump
{
private:
  /// File input stream
  std::ifstream fInput;
  
public:
  /// Opens the file with the given filename for processing
  /// @param  aInputFileName  The file name to process
  /// @return True if opening was successful, false otherwise
  bool open(const std::string& aInputFileName);
  /// Closes the file for processing
  void close();
  /// Processes the file for input
  void processInput();
};

#endif /* defined(__A3__HexDump__) */
