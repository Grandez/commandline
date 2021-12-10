#include <string>
#include <filesystem>

#include "make_config.h"

using namespace std;

namespace NSCLP {
class PathImpl : public filesystem::path {
public:
   PathImpl();
//   PathImpl(const PathImpl& mPath);
   PathImpl(const char *str);
   PathImpl(std::string str);
   bool isFile();
   bool isDirectory();
   int  exists();
   std::string getPath    ();
   std::string getDrive   ();
   std::string getDir     ();
   std::string getFileName();
   std::string getExt     ();
   std::string getBaseName(); 

   char*       toChar   (char *ptr, size_t size);
   std::string toString ();
private:
   enum class PathType { Unknow, Block, Character, Fifo, File, Dir, Link, Socket};
   path cwd;
   std::string drive;
   std::string dir;
   std::string file;
   std::string ext;
   PathType    type = PathType::Unknow;
   int    valid = 1; // -1 true, 0 = false, 1 = undef
   PathType checkIfExists();
   bool changeDrive(path drive);
   void splitPath();
};
}
