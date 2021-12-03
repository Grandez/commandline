#include <string>
#include <unordered_map>
#include <set>

#include "sstring.hpp"
#include "config_ini.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
#include <stdexcept>

using namespace std;

namespace NST {

ConfigIni::ConfigIni (const char *path) {
   this->path = path;
}
void ConfigIni::loadConfigFile () {
    char *buffer = 0x0;;
    struct stat stat_buf;
    FILE * pFile = 0x0;;
    size_t size;
    int rc = stat(path.c_str(), &stat_buf);
    if (rc == 0) {
        pFile = fopen (path.c_str(),"rt");
        if (pFile != NULL) {
            buffer = (char *) malloc(stat_buf.st_size + 1);
            size = fread(buffer,1, stat_buf.st_size, pFile);
            if (size != stat_buf.st_size) rc = -1;
            buffer[stat_buf.st_size] = 0x0;
        } else {
            rc = -1;
        }
     }
     if (pFile) fclose(pFile);
     if (rc == 0) lines = sstring(buffer).tokenize(sstring("\\r\\n|\\r"));
     free(buffer);
     if (rc != 0) throw new exception("File not found ");

}
void ConfigIni::writeConfigFile() {
}
void ConfigIni::parseConfigFile() {
   unordered_map<string, set<string>> values; 
   //TODO esto es un parser de tomo y lomo
   const sstring cmt("#");
   const sstring key("=");
   vector<sstring> prev;
   vector<sstring> keys;
   for (unsigned int line; line < lines.size(); line++) {
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