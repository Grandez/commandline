%{
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#define isatty _isatty
#define fileno _fileno
int mylineno = 0;
char buff[128];

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

int words = 0;

%}

%option noyywrap
%option nounistd
%option stack

ws      [ \t]
word    [a-zA-Z0-9\$_\-]+

%x CMT 
%%
"#"             { BEGIN(CMT); }
{ws}    /* skip blanks and tabs */

{word}  { words++;
          printf("%s", yytext); 
          if (words % 2) printf("\n"); else printf("\t\t");
        }
'='     { /* nada */ }
.       { 
/* printf("JGGERROR: %s-%X", yytext, yytext[0]); */
}
\"      { buff[0] = 0x0; BEGIN(DQUOTE); }
\'      { buff[0] = 0x0; BEGIN(SQUOTE);  }   

<CMT>{
\n     { BEGIN(INITIAL); }
.      
}
<DQUOTE>{
\\     { BEGIN(DCONTINUE); } 
\"     { BEGIN(CONTINUE); } // Check for \
\n     { BEGIN(INITIAL); }
.      
}
<SQUOTE>{
\n     { BEGIN(INITIAL); }
.      
}

%%
/*
int main( int argc, char** argv ) {
    yyin = fopen( argv[1], "r" );
    yylex();
    return 0;
 }
 */
/*
\"      { buff[0] = 0x0; BEGIN(DQUOTE); }
\'      { buff[0] = 0x0; BEGIN(QUOTE);  }   
*/
/*
}
<DQUOTE>{
{word}  { str.append(YYText()); }
{ws}    { str.append(YYText()); }
\\      { BEGIN(CONT2);         }
\'      { str.append(YYText()); }
\"      { //yylval = str; 
return 1; BEGIN(PEND); }
.       { str.append(YYText()); }
}
<QUOTE>{
{word}  { str.append(YYText()); }
{ws}    { str.append(YYText()); }
\\      { BEGIN(CONT1);         }
\"      { str.append(YYText()); }
\'      { // yylval = str; 
return 1; BEGIN(INITIAL); }
.       { str.append(YYText()); }
}
<CONT2>{
{ws}    { str.append(YYText()); }
\"      {yy_pop_state();        }
.       { // yypushback(1);  
yy_pop_state(); }
}
<CONT1>{
{ws}    { str.append(YYText()); }
\'      {yy_pop_state();        }
.       { // yypushback(1)();  
yy_pop_state(); }
}

<PEND>{ // Fin con comillas, miramos si hay \
"\r\n"   { // yylval = str; 
BEGIN(INITIAL); return 1;  }
\r     { // yylval = str; 
BEGIN(INITIAL); return 1;  }
{ws}   
\\     { yy_push_state (CONT); }
}
*/
