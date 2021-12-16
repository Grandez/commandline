#define __MAIN__
#include <iostream>

#include "cmdline_cmdline.hpp"
#include "showinfo.hpp"
#include "labels.hpp"

using namespace std;
using namespace NSCLP;

Parameters  parms { 
    ParmFlag(lbl_verbose,  true)                    
   ,ParmFlag(lbl_summary,  true)                     
   // Strings
   ,ParmOption(lbl_char,  Type::CHAR,      true) 
   ,ParmOption(lbl_byte,  Type::BYTE,      true) 
   // logical
   ,ParmOption(lbl_flag,  "true", Type::BOOL,    false)
   // numbers
   ,ParmOption(lbl_natural,   Type::NATURAL,      true) 
   ,ParmOption(lbl_short,     Type::SHORT,      true) 
   ,ParmOption(lbl_integer,   Type::INTEGER,      false)
   ,ParmOption(lbl_decimal,   Type::DECIMAL,     true) 
   // Datetimes
   ,ParmOption(lbl_date,      Type::DATE,        false)
   ,ParmOption(lbl_time,      Type::TIME,        false)
   ,ParmOption(lbl_datetime,  Type::DATETIME,    false)
   ,ParmOption(lbl_tms,       Type::TMS,         false)
   // Paths
   ,ParmOption(lbl_dirIn,     Type::DIR_EXISTS,  true) 
   ,ParmOption(lbl_dirOut,    Type::DIR,         false)
   ,ParmOption(lbl_fileIn,    Type::FILE_EXISTS, true) 
   ,ParmOption(lbl_fileOut,   Type::FILE,        false) 
   // Configuration
   ,ParmOption(lbl_config,    Type::CONFIG,      false) 
};

int main(int argc, const char **argv) {
    Parameters&  mparms = parms; 
    cout << "Starting " << argv[0] << endl;
    try {
       CmdLine cmdLine(argc, argv, mparms);
       showValues(&cmdLine);
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
