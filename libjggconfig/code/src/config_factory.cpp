#include "jggtools.hpp"
#include "config_ini.hpp"
#include "config_factory.hpp"

using namespace std;
namespace NST {
   ConfigInstance *ConfigFactory::getInstance(const char *file, const char *type) {
       Path path(file);
       if (!path.exists()) throw new ToolsNotFoundException(FILE_NOT_FOUND, path.getPath());
       switch(getType(path, type)) {
           case 1: return (ConfigInstance *) new ConfigIni(file);
       }
   }
   int ConfigFactory::getType(Path& path, const char* type) {
       
       string mtype;
       if (type != 0x0) {
           mtype = string(type);
       } else {
          mtype = path.getExt();
       }
       for (size_t i = 0; i < mtype.length(); i++) mtype[i] = tolower(mtype[i]);
       if (mtype == "ini") return 1;
       string msg("Configuration files for type ");
       msg.append(mtype).append(" is not implemented");
       throw new ToolsNotSupportedException(msg.c_str());
   }
}

