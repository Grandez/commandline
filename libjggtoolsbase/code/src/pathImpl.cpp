#include <string>
#include <filesystem>
#include <direct.h>
#include "exceptions.hpp"
#include "pathImpl.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 28183)
#endif

using namespace std;
using namespace std::filesystem;

namespace NSCLP {

   PathImpl::PathImpl() : path(filesystem::current_path()) {
      cwd = filesystem::current_path();
      if (has_root_name()) drive = root_name().string();
      dir = relative_path().string();
      splitPath();
   }
   PathImpl::PathImpl(const char *str) : path (str) {
       PathType mtype = checkIfExists();
       valid = (mtype == PathType::Unknow) ? false : true;
       if (valid) type = mtype;
       splitPath();
   }
   PathImpl::PathImpl(std::string str) : path (str.c_str()) {}

//   PathImpl::PathImpl(const PathImpl& mPath) : path(mPath) {
//       int i = 2;
//   }
   bool   PathImpl::isFile()       { return (type == PathType::File); }
   bool   PathImpl::isDirectory()  { return (type == PathType::Dir);  }
   int    PathImpl::exists()       { return valid;      };
   string PathImpl::getPath    ()  { return string(); };
   string PathImpl::getDrive   ()  { return drive; };
   string PathImpl::getDir     ()  { return dir;   };
   string PathImpl::getFileName()  { return file;  };
   string PathImpl::getExt     ()  { return ext;   };
   string PathImpl::getBaseName()  { 
      if (ext.length() == 0) return file;
      return std::string(file).append(".").append(ext);
    }
   char* PathImpl::toChar   (char *ptr, size_t size) {
       char *str = strdup(string().c_str());
       if (strlen(str) >= size) throw new ToolsOutOfSpaceException(size);
       strcpy(ptr, str);
       free(str);
       return ptr;
    }
   string PathImpl::toString   () { return string(); }

   void PathImpl::splitPath()  {
      if (has_root_name())   drive = root_name().string();
      if (has_stem())        file  = stem().string();
      if (has_extension())   ext   = extension().string().substr(1);
      if (has_parent_path()) dir   = parent_path().string();
   } 
/*
    bool PathImpl::checkIfExists() {
        int oldDrive = 0;
//        char cwd[256];
        char *nwd;
        if (cwd == *this) return true; // Is cwd
        bool driveChanged = changeDrive(root_name());
        int rc = chdir(relative_path().string().c_str());
        if (rc == -1) {
            if (driveChanged) changeDrive(cwd.root_name());
            return 0;
        }
        nwd = getcwd( NULL, 0 );
        if (strcmp(cwd.relative_path().string().c_str(), nwd) == 0) return false;
        rc = chdir(cwd.relative_path().string().c_str());
        return true;
    }
*/
    bool PathImpl::changeDrive(path drive) {
        if (!has_root_name()) return 0;
        std::string sDrive = drive.string();
        int newDrive = toupper(sDrive[0]) - 'A' + 1;
        int rc = _chdrive(newDrive); 
        return (rc == 0);
    }
    PathImpl::PathType PathImpl::checkIfExists() {
       // Check if exists and type of path
       struct stat     statbuf;
      cwd = filesystem::current_path();
       std::string p = string();
       int rc = stat(string().c_str(), &statbuf);
       if (rc) return PathType::Unknow;
       if (statbuf.st_mode & S_IFDIR) return PathType::Dir;
       if (statbuf.st_mode & S_IFREG) return PathType::File;
       return PathType::Unknow;
    }
}
