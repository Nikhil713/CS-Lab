%{
#include<stdio.h>
%}

delim [\t]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
num {digit}+(\.{digit}+)?(E[+|-]?{digit}+)?

%%
ws {printf("no action\n");}
if|else|then {printf("%s is a keyword\n",yytext);}
{id} {printf("%s is a identifier\n", yytext);}
{num} {printf("%s it is a number\n", yytext);}
"+" {printf("%s it is addition operation\n",yytext);}
"-" {printf("%s it is subtraction operation\n",yytext);}
"*" {printf("%s it is multiplication operation\n",yytext);}
"/" {printf("%s it is division operation\n",yytext);}
"<" {printf("%s it is a relational operator less than\n",yytext);}
"<=" {printf("%s it is a relational operator less than or equal\n",yytext);}
">" {printf("%s it is a relational operator greater than\n",yytext);}
">=" {printf("%s it is a relational operator greater than\n",yytext);}
"==" {printf("%s it is a relational operator equal\n",yytext);}
"<>" {printf("%s it is a relational operator not equal\n",yytext);}
%%


int main()
{
yylex();
return 0;
}
