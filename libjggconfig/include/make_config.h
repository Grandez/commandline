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

#ifndef CMDLINE_NSCLP2
#define CMDLINE_NSCLP2 _clp
#define NSCLP2 CMDLINE_NSCLP2
#endif

#ifndef ENV_PREFFIX
#define ENV_PREFFIX "env_preffix"
#endif

#define NST jggtools

#define MAX_PARM_NAME   64

#define OPTION          '/'
#define DEFINITION      '$'
#define FLAG_ACTIVE     '+' 
#define FLAG_INACTIVE   '-' 

#endif