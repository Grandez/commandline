#include <string.h>
#include <ctype.h>

#include "number.hpp"

namespace NSCLP {
int Number::getBase (const char *str) {
     int beg = 0;
     if (strlen(str) < 3) return 10;
     if (str[0] == '-' || str[0] == '+') beg++;
     if (str[beg] != '0') return 10;
     beg++;
     if (str[beg] == 'x' || str[beg] == 'X') return 16;
     for (size_t i = beg; i < strlen(str); i++) if (str[i] != '0' && str[i] != '1') return 10;
     return 2; 
};
}