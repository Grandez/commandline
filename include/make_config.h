/**
 * @file make_config.h
 * @author Grandez
 * @date 10/2021
 * @brief Defines for customize the library
 *
 */
#ifndef __CMDLINE_CONFIG__
#define __CMDLINE_CONFIG__

#ifndef CMDLINE_ERRNO
#define CMDLINE_ERRNO 16000
#endif

#ifndef CMDLINE_NSCLP
#define CMDLINE_NSCLP clp
#define NSCLP CMDLINE_NSCLP
#endif

// Max name for parameters and flags
#ifndef MAX_PARM_NAME
#define MAX_PARM_NAME   64 
#endif

#ifndef MAX_SIZE_ERR
#define MAX_SIZE_ERR   255 
#endif


// Flags for items
#define ITEM_OPTION          '/'
#define ITEM_DEFINITION      '$'
#define ITEM_FLAG_ACTIVE     '+' 
#define ITEM_FLAG_INACTIVE   '-' 
#define ITEM_NAMED           '=' 
#endif