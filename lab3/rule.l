%option yylineno

%{
    #include "fhash.cpp"
    HashMap<string, int> *h = new HashMap<string, int>;
  unsigned int col = 0; 
  #define ADD(TOKEN) printf(#TOKEN "\n"); col += yyleng; 
  #define FADD(TOKEN) h->insertNode(yytext, TOKEN); col += yyleng; 
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
    FADD(EQ);
}

{RIM}+ {
    FADD(RIM);
}

{OP} {
    FADD(OP);
}

"else" {
    ADD(ELSE);
}

"then" {
    ADD(THEN);
}

{ID} {
    FADD(ID);
}

{ws} {
    col = *yytext == '\n' ? 0 : col + 1;
}

. {
    printf("Unknown character\n");
}
%%


int main(){
	yylex();
	h->display();
}