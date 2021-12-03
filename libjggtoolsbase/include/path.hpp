#pragma once

#include <vector>
#include <string>
#include <memory>

#include "make_config.h"

using namespace std;

namespace NST {
class Path {
public:
   Path();
//   Path(const Path& src);
   Path(string str);
   Path(const char *str);
   bool isFile();
   bool isDirectory();
   bool exists();
   string getDrive();
   string getDir();
   string getFileName();
   string getExt();
   string getBaseName(); 
   string getPath();
private:
   class PathBridge;
   unique_ptr<PathBridge, void (*)(PathBridge *)> _pb;
};
}
