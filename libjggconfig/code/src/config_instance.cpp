#include "config_instance.hpp"

namespace NST {
unordered_map<string, set<string>> ConfigInstance::getPairKeyValues() {
   return values;
}
set<string>                        ConfigInstance::getKeyValues() {
    return set<string>();
}
}

