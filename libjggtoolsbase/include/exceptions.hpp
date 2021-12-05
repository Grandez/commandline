#pragma once
#include <stdexcept>
#include <string>

#include "make_config.h"
#include "msg_locale.hpp"

using namespace std;

namespace NST {
   class ToolsException : public std::domain_error {
      public:
         ToolsException(const char *fmt, ...);
         const char* what();
      protected:   
/// \cond DO_NOT_DOCUMENT
         void mountMessage(const char* fmt, va_list list);
         void setMessage(const char *msg);
/// \endcond
      private:
         std::string message;
   };
   class ToolsValueException : public ToolsException {
      public:
         ToolsValueException(const char *fmt, ...);
   };
   class ToolsCastException : public ToolsException {
      public:
         ToolsCastException(const char *fmt, ...);
   };
   class ToolsOutOfRangeException : public ToolsException {
      public:
         ToolsOutOfRangeException(string src, string expected);
   };
   class ToolsOutOfSpaceException : public ToolsException {
      public:
         ToolsOutOfSpaceException(size_t size);
   };
   class ToolsNotSupportedException : public ToolsException {
      public:
         ToolsNotSupportedException(const char *msg);
   };
   class ToolsNotFoundException : public ToolsException {
      public:
         ToolsNotFoundException(const char *fmt, ...);
   };

}