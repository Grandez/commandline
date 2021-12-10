#include <string>
#include <errno.h>
#include <fstream>

#include <unordered_map>
#include <set>

#include "sstring.hpp"
#include "config_ini.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
#include <stdexcept>
#include <iostream>

using namespace std;

namespace NSCLP {

ConfigIni::ConfigIni (const char *path) {
   this->path = path;
   loadConfigFile();
   parseConfigFile();
}
void ConfigIni::loadConfigFile () {
    struct stat stat_buf;
    int rc = stat(path.c_str(), &stat_buf);
    string line;
    if (rc == 0) {
        ifstream fIn(path.c_str());
        while (getline(fIn, line)) lines.push_back(line);
    }
     if (rc != 0) throw new ToolsNotFoundException(FILE_NOT_FOUND, path.c_str());
}
void ConfigIni::writeConfigFile() {
}
void ConfigIni::parseConfigFile() {
   //TODO esto es un parser de tomo y lomo
   const sstring cmt("#");
   const sstring key("=");
   vector<sstring> prev;
   vector<sstring> keys;
   for (size_t line = 0; line < lines.size(); line++) {
       prev = lines[line].tokenize(cmt);
       prev[0].trim();
       if (prev[0].length() == 0) continue;
       keys = prev[0].tokenize(key);
       if (keys.size() != 2) continue;
       keys[0].trim();
       keys[1].trim();
       try {
		  set<string> *value = &values.at(keys[0]);
          value->insert(keys[1]);
	   }
	   catch (out_of_range ex) {
           set<string> value = {keys[1]};
           values.emplace(keys[0], value);
		}
   }
}

}