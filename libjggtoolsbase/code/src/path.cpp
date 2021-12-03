#include <string>

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

#include "path.hpp"
#include "pathImpl.hpp"

using namespace std;

namespace NST {
   class Path::PathBridge : public PathImpl {
   public:
     PathBridge()                  : PathImpl(){}
     PathBridge(const char *str)   : PathImpl(str) {}
     PathBridge(std::string str)   : PathImpl(str.c_str()) {}
//     PathBridge(const Path& mPath) : PathImpl(mPath)       {}
   };
   Path::Path()                   : _pb(new PathBridge(),            [](PathBridge *pb) { delete pb; }) {}  
//   Path::Path(const Path& path)   : _pb(new PathBridge(path),        [](PathBridge *pb) { delete pb; }) {}  
   Path::Path(string str)         : _pb(new PathBridge(str),         [](PathBridge *pb) { delete pb; }) {}  
   Path::Path(const char *str)    : _pb(new PathBridge(str),         [](PathBridge *pb) { delete pb; }) {}  

   bool   Path::isFile()          { return _pb->isFile();      }
   bool   Path::isDirectory()     { return _pb->isDirectory(); }
   bool   Path::exists()          { return _pb->exists();      }
   string Path::getPath()         { return _pb->getPath();     }
   string Path::getDrive()        { return _pb->getDrive();    }
   string Path::getDir()          { return _pb->getDir();      }
   string Path::getFileName()     { return _pb->getFileName(); }
   string Path::getExt()          { return _pb->getExt();      }
   string Path::getBaseName()     { return _pb->getBaseName(); }

 }