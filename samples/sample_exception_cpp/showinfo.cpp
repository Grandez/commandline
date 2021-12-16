#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "labels.hpp"
#include "showinfo.hpp"

using namespace std;
using namespace NSCLP;

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
    cout << "\t" << lbl_verbose   << ":\t"   << "Flag"                              << endl;
    cout << "\t" << lbl_summary   << ":\t"   << "Flag"                              << endl;
    cout << "\t" << lbl_flag      << ":\t\t" << "Option boolean"                    << endl;
    cout << "\t" << lbl_decimal   << ":\t"   << "Just one decimal"                  << endl;
    cout << "\t" << lbl_date      << ":\t\t" << "Date"                              << endl;
    cout << "\t" << lbl_time      << ":\t\t" << "Time"                              << endl;
    cout << "\t" << lbl_datetime  << ":\t"   << "DateTime"                          << endl;
    cout << "\t" << lbl_tms       << ":\t"   << "Timestamp"                         << endl;
    cout << "\t" << lbl_dirIn     << ":\t\t" << "Existing directories"              << endl;
    cout << "\t" << lbl_dirOut    << ":\t\t" << "A directory"                       << endl;
    cout << "\t" << lbl_fileIn    << ":\t\t" << "Existing files"                    << endl;
    cout << "\t" << lbl_fileOut   << ":\t"   << "A possible output file"            << endl;
    cout << "\t" << lbl_config    << ":\t\t" << "An existing configuration file"    << endl;
}

void showValues(CmdLine *cmdLine) {
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
