/*DLLBin.h*/
/*
  Programmer : Aether
*/

#ifndef DLLBIN_H
#define DLLBIN_H

#include <string>

template<class std::string>
class DLL {
private:
  const std::string dllname; /*dll file name*/
public:
  /*constructor method*/
  /*loads name*/
  DLL( const std::string dll ) : dllname( dll ){}
  ~DLL(); /*deconstruct*/
};

#endif
