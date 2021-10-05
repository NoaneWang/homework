#include <iostream>
#include <cstdio>
int printToken(char *s){
    if(strcmp(s, "if")==0) {printf("If\n");return 1;}
    if(strcmp(s,"else")==0) {printf("Else\n");return 1;}
    if(strcmp(s,"while")==0) {printf("While\n");return 1;}
    if(strcmp(s,"continue")==0) {printf("return\n");return 1;}
    if(strcmp(s,"break")==0) {printf("Break\n");return 1;}
    if(strcmp(s, "return")==0) {printf("Return\n"); return 1;}
    else printf("Ident(%s)\n",s);
    return 0;
}
int printChar(char q){
    if(q=='=') {printf("Assign\n");return 1;}
    if(q==';') {printf("Semicolon\n");return 1;}
    if(q=='(') {printf("LPar\n");return 1;}
    if(q==')') {printf("RPar\n");return 1;}
    if(q=='{') {printf("LBrace\n");return 1;}
    if(q=='}') {printf("RBrace\n");return 1;}
    if(q=='+') {printf("Plus\n");return 1;}
    if(q=='*') {printf("Mult\n");return 1;}
    if(q=='/') {printf("Div\n");return 1;}
    if(q=='<') {printf("Lt\n");return 1;}
    if(q=='>') {printf("Gt\n");return 1;}
    return 0;

}
int main() {
    char c;
    char* num;
    char *s;
    s=(char*)malloc(sizeof(char)*1024);
    num = (char*)malloc(sizeof(char)*1024);
    while((c = getchar()) != EOF){
        if(c=='='){
            int eq = 1;
            while((c=getchar())=='='){
                eq++;
            }
            int j = eq/2;
            for(int i = 0; i < eq/2 ;i++){
                printf("Eq\n");
            }
            if(eq%2==1){
                printf("Assign\n");
            }
            eq = 0;
        }
        else {
            if (isdigit(c)) {
                if (strlen(s) == 0) {
                    num[strlen(num)] = c;
                    num[strlen(num) + 1] = '\0';
                } else {
                    s[strlen(s)] = c;
                    s[strlen(s) + 1] = '\0';
                }
            } else if (isalpha(c) | c == '_') {
                if (strlen(num) != 0) {
                    printf("Number(%s)\n", num);
                    memset(num, 0, sizeof(num));
                }
                s[strlen(s)] = c;
                s[strlen(s) + 1] = '\0';
            } else if (c == ' ') {
                if (strlen(num) > 0) {
                    printf("Number(%s)\n", num);
                    memset(num, 0, sizeof(num));
                } else if (strlen(s) > 0) {
                    printToken(s);
                    memset(s, 0, sizeof(s));
                }
            } else if (c == '\n' | c == '\t') {
                if (strlen(num) > 0) {
                    printf("Number(%s)\n", num);
                    memset(num, 0, sizeof(num));
                } else if (strlen(s) > 0) {
                    printToken(s);
                    memset(s, 0, sizeof(s));
                }
            } else {
                if (strlen(num) > 0) {
                    printf("Number(%s)\n", num);
                    memset(num, 0, sizeof(num));
                } else if (strlen(s) > 0) {
                    printToken(s);
                    memset(s, 0, sizeof(s));
                }
                if (printChar(c))
                    continue;
                else {
                    printf("Err\n");
                    break;
                }
            }
        }


    }
    return 0;
}

