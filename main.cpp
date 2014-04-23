//
//  Assignment 3
//  COS30008 - DSP
//
//  Alex Cummaudo, 1744070
//  2014-03-31
//
#include <iostream>
#include "HexDump.h"

int main(int argc, const char * argv[])
{
  // Boilerplate for input args
  // Always add one for implicit program path argument
  if (argc < 1 + 1)
  {
      std::cerr   << "Missing arguments: expected"
                  << " HexDump fname"
                  << "Only " << argc << " parameters given:" << std::endl;

      // Failed (invalid arguments)
      return 1;
  }
  
  HexDump lProcessor;
  
  // If successfully opened?
  if ( lProcessor.open( argv[1] ) )
  {
    lProcessor.processInput();
    lProcessor.close();
    return 0;
  }
  
  return 2;
  

}