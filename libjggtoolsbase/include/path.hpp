#pragma once

#include <vector>
#include <string>
#include <memory>

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class Path : public DataType {
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

   string  toString() override;
   char*   toChar  (char *buff, size_t size) override;

private:
   class PathBridge;
   unique_ptr<PathBridge, void (*)(PathBridge *)> _pb;
};
}
