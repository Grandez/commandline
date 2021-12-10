#include "config_instance.hpp"

namespace NSCLP {
unordered_map<string, set<string>> ConfigInstance::getPairKeyValues() {
   return values;
}
set<string>                        ConfigInstance::getKeyValues() {
    return set<string>();
}
}

