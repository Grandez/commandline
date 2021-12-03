/*
#include <cstdarg>
#include <string.h>
#include <typeinfo>
#include <memory>

#include <stdexcept>
#include "msg_locale.hpp"

*/

#include "exceptions.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

// namespace NST {
  class ToolsException::ToolsExceptionImpl {
  public:
    ToolsExceptionImpl() {}
    ~ToolsExceptionImpl() {
       int i = 0;
       while(pointers[i]) free(pointers[i++];
       free(pointers);
    }
//    std::string mountMessage(const char* fmt, va_list list) {
/*
        int szSize = 0;
        int count = 1;
        szWhat = (char *) malloc(szSize);
        do {
           szSize += MAX_SIZE_ERR;
           if (szWhat != 0x0) free (szWhat);
           szWhat = (char *) malloc(szSize);
           count = std::vsnprintf(szWhat, szSize, fmt, list);
        } while (count < 0);
        addPointer(std::addressof(szWhat)); 
		return std::string(TXT_ERROR).append(szWhat);

    }
*/
//    const char* ToolsExceptionImpl::what() { return (const char *) szWhat; }

  private:
    char *szWhat = 0x0;
    int size = 0;
    int act  = 0;
    const int inc = 16;
    char **pointers = 0x0;

    void addPointer(auto ptr) {
         if (act == pointer) {
            size += inc;
            pointers = (char **) realloc(pointers,size * (void *)); 
         }
         pointers[act++] = ptr;
         pointers[act] = 0x0;
    }

}
 ToolsException::ToolsException(const char* fmt, ...) {
   _pImpl = new ToolsExceptionImpl();
}

ToolsException::ToolsException(const ToolsException& op) 
}

ToolsException& ToolsException::operator=(const ToolsException& op) {
    if (this != &op) {
        _pImpl.reset(new ToolsExceptionImpl(*op._pImpl));
    }
    return *this;
}

ToolsException::~ToolsException() {
}
ToolsException::~ToolsException() {
}
ToolsException::ToolsException(const char* fmt, ...) {
}
ToolsException::what() {
    return pImpl->
}

std::string ToolsException::mountMessage(const char* fmt, va_list list) {
	va_list args;
	va_start(args, fmt);
    std::string txt = _pImpl->mountMessage(fmt, args);
    va_end(args);
}
const char* ToolsException::what() {
}
ToolsCastException::ToolsCastException (const char* fmt, ...) {

}

	std::string mountMessage(const char* fmt, va_list list) {
		char t[255];
		std::vsprintf(t, fmt, list);
		return std::string(TXT_ERROR).append(t);
	}

	ToolsCastException::ToolsCastException(const char* fmt, ...) : std::logic_error(fmt) {
		va_list args;
		va_start(args, fmt);
        std::string txt = mountMessage(fmt, args);
        va_end(args);
		this->bad_cast::~bad_cast();
		new (this) bad_cast(txt);
{ return "o noez! an exception!"; }
	}
    const char* ToolsCastException::what() const override {
         return ;
    }

};
// }
