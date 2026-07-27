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
  constexpr auto DOS_HEADER = "IMAGE_DOS_HEADER"; //*contains the magic number MZ and a pointer to the PE header.
  constexpr auto PE_HEADER = "IMAGE_NT_HEADERS"; //*contains file signature, machine type, and section info.
  constexpr auto SECTION_TABLE = "IMAGE_SECTION_HEADER"; //*describes code, data, and resource sections.
  constexpr auto EXPORT_TABLE = "0"; //*lists functions the DLL provides.
  constexpr auto IMPORT_TABLE = "-0928"; //*lists functions the DLL calls from other DLLs.
  constexpr auto RESOURCE_SECTION = "-0383"; //* contains icons, dialogs, strings, etc.
  const std::string MZ_PE_SIG = "\0\0"; /*MZ PE signature if its a PE file*/
  size_t SECTIONS = 0;
public:
  /*constructor method*/
  /*loads name*/
  DLL( const std::string dll ) : dllname( dll ){}
  ~DLL(); /*deconstruct*/

  /*get*/
  inline DLL& get() {
      return *this;
  }

  /*getPESignature*/
  /*if dll contains PE signature, return it of this dll file*/
  const std::string& getPESignature() const {
        return MZ_PE_SIG;
  }

  /*sections*/
  const size_t getSections() const {
      return SECTIONS;
  }

  /*is PE format*/
  bool isPEFormat();

  /*DLL BINARY MODE*/
  /*to open and read dll file, we open it in binary mode, as most file :|*/
  constexpr auto doBinaryMode() const {
      return 0x1; //*o's and 1's
  }

  /*begin*/
  /*begin's parsing and reading dll file values and scripts, etc...*/
  inline DLL& begin();

  /*end*/
  /*end the parsing and reading, then save the info to a dump*/
  inline DLL& end();

  /*save*/
  /*saving the info that was read and parsed, *must tell the file to save to**/
  void save(const std::string& dumpFile);

  /*PE*/
  /*get the portable executable format that belongs to the header file*/
  inline auto& getFormat();

};

#endif
