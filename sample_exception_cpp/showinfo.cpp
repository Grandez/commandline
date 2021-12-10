#pragma once
#include <string>
#include <vector>

#include "showinfo.hpp"

using namespace std;

void printOption(string option, vector<string> values) {
   int num = 0;
   cout << "\t" << option << "\t: "; 
   if (values.size() == 1 && values[0].length() == 0) {
       cout << "No default value\n";
       return;
   }
   for (auto str : values) {
        if (num) cout << ", ";
        cout << str;
        num++;
   }
   cout << endl;
}

void showHelp(HelpRequested* help) {
    cout << "A sample program about error management"                << endl;
    cout << "Use: " << help->name << " [options]"                    << endl;
    cout << "Options:"                                               << endl;
    cout << "\t" << VERBOSE   << ":\t"   << "Flag"                              << endl;
    cout << "\t" << SUMMARY   << ":\t"   << "Flag"                              << endl;
    cout << "\t" << FLAG      << ":\t\t" << "Option boolean"                    << endl;
    cout << "\t" << NUMBERS   << ":\t"   << "Integers"                          << endl;
    cout << "\t" << NUMBER    << ":\t\t" << "Just one integer"                  << endl;
    cout << "\t" << DECIMALS  << ":\t"   << "Decimals"                          << endl;
    cout << "\t" << DECIMAL   << ":\t"   << "Just one decimal"                  << endl;
    cout << "\t" << DATE      << ":\t\t" << "Date"                              << endl;
    cout << "\t" << TIME      << ":\t\t" << "Time"                              << endl;
    cout << "\t" << DATETIME  << ":\t"   << "DateTime"                          << endl;
    cout << "\t" << TIMESTAMP << ":\t"   << "Timestamp"                         << endl;
    cout << "\t" << DIRIN     << ":\t\t" << "Existing directories"              << endl;
    cout << "\t" << DIROUT    << ":\t\t" << "A directory"                       << endl;
    cout << "\t" << FILEIN    << ":\t\t" << "Existing files"                    << endl;
    cout << "\t" << FILEOUT   << ":\t"   << "A possible output file"            << endl;
    cout << "\t" << CONFIG    << ":\t\t" << "An existing configuration file"    << endl;
}

void showValues() {
    Flags   flags   = cmdLine->getCurrentFlags();
    Options options = cmdLine->getCurrentOptions();
    cout << "Flags:" << endl;
    for (auto flag : flags) {
       cout << "\t" << flag.first << ": " << std::boolalpha << flag.second << endl;
    }
    cout << "Options:" << endl;
    for (auto option : options) {
        printOption(option.first, option.second);
    }
    
}
