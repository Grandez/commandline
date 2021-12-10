#define __MAIN__
#include <iostream>

#include "..\libcmdline\include\commandline.hpp"
#include "showinfo.hpp"

using namespace std;
using namespace NSCLP;

Parameters  parms { 
    ParmFlag("verbose",  true)                    
   ,ParmFlag("summary",  true)                     
   // Strings
   ,ParmOption("char",  Type::CHAR,      true) 
   ,ParmOption("byte",  Type::BYTE,      true) 
   // logical
   ,ParmOption("flag",  "true", Type::BOOL,    false)
   // numbers
   ,ParmOption("natural",  Type::NATURAL,      true) 
   ,ParmOption("short",   Type::SHORT,      true) 
   ,ParmOption("integer",    Type::INTEGER,      false)
   ,ParmOption("decimal",  Type::DECIMAL,     true) 
   // Datetimes
   ,ParmOption("date",      Type::DATE,        false)
   ,ParmOption("time",      Type::TIME,        false)
   ,ParmOption("datetime",  Type::DATETIME,    false)
   ,ParmOption("tms", Type::TMS,         false)
   // Paths
   ,ParmOption("dirIn",     Type::DIR_EXISTS,  true) 
   ,ParmOption("dirOut",    Type::DIR,         false)
   ,ParmOption("fileIn",    Type::FILE_EXISTS, true) 
   ,ParmOption("fileOut",   Type::FILE,        false) 
   // Configuration
   ,ParmOption("config"    Type::CONFIG,      false) 
};

int main(int argc, char *argv[]) {
    cout << "Starting " << argv[0] << endl;
    try {
       cmdLine = CmdLine::getInstance(argc, argv,parms);
       showValues();
    }
    catch (HelpRequested *help) { 
        showHelp(help); 
    } 
    catch (CmdLineException *ex) {
        cerr << ex->what() << endl;
        cerr << "Exception type: " << ex->type << endl;
        exit(1);
    }
    exit (0);
}
