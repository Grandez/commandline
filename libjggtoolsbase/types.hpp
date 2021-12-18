#include "make_config.h"

namespace NSCLP {
	enum class Type { CHAR, STRING                                   // String
                     ,BOOL                                           // Boolean
		             ,BYTE, SHORT, NATURAL, INTEGER, LONG, DECIMAL   // Numbers 
		             ,DATE, TIME, DATETIME, TMS                      // Date times
		             ,DIR, DIR_EXISTS, FILE, FILE_EXISTS             // Files and directories
                     ,CONFIG, CONFIG_RELAXED, ENV                    // Configuration and environment
		             ,FLAG                                           // Flag (internal use)
	};
}