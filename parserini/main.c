#include <stdio.h>
#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

#include "lexer.h"

int main( int argc, char** argv ) {
    yyin = fopen( argv[1], "r" );
    yylex();
    return 0;
 }
