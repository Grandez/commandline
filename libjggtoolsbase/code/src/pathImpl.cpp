#include <string>
#include <filesystem>
#include <direct.h>
#include "pathImpl.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 28183)
#endif

using namespace std;
using namespace std::filesystem;

namespace NST {

   PathImpl::PathImpl() : path(filesystem::current_path()) {
      cwd = filesystem::current_path();
      if (has_root_name()) drive = root_name().string();
      dir = relative_path().string();
   }
   PathImpl::PathImpl(const char *str) : path (str) {
       PathType mtype = checkIfExists();
       if (mtype == PathType::Unknow) valid = false;
       valid = true;
       type = mtype;
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
       int rc = stat(this->string().c_str(), &statbuf);
       if (rc) return PathType::Unknow;
       if (statbuf.st_mode & S_IFDIR) return PathType::Dir;
       if (statbuf.st_mode & S_IFREG) return PathType::File;
       return PathType::Unknow;
    }
/*
    void PathImpl::isValidName() {
        char *pat = "[0x00-0x1F<>\:\"\?\*\|]+"

    < (less than)
    > (greater than)
    : (colon)
    " (double quote)
    / (forward slash)
    \ (backslash)
    | (vertical bar or pipe)
    ? (question mark)
    * (asterisk)

    }
*/
}
