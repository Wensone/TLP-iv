%option yylineno

%{
  unsigned int col = 0; 
  #define ADD(TOKEN) printf(#TOKEN "\n"); col += yyleng; 
%}

NUM [0-9]
CHAR [a-z]
RIM [XVI]
ID ({CHAR}|_)({CHAR}|{NUM}|_)* 
ws [ \t\n]
OP [<>=]
DLM [;]
SIGN [-+]
EQ ":="

%%
"if" {
    ADD(IF);
}

{EQ} {
    ADD(EQ);
}

{RIM}+ {
    ADD(RIM);
}

{OP} {
    ADD(OP);
}

"else" {
    ADD(ELSE);
}

"then" {
    ADD(THEN);
}

{ID} {
    ADD(ID);
}

{ws} {
    col = *yytext == '\n' ? 0 : col + 1;
}

. {
    printf("Unknown character\n");
}
%%