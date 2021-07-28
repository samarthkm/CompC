#ifndef LEX_H
#define LEX_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "lexInit.h"

char *ops[] = { "+", "-", "*", "/", "INTEGER" };

static void Back(int cb) {
    back=cb;
}

static int nextChar() {
    int cb;
    if(back){
        cb=back;
        back=0;
        return cb;
    }

    cb=fgetc(inp);
    if(cb=='\n') line+=1;
    return cb;
}

static int skipWhitespace() {
    int cb=nextChar();
    while(cb==' '||cb=='\n'||cb=='\r'||cb=='\t'||cb=='\f') cb = nextChar();
    return cb;
}

static int chrint(int c,char* str) {
    char* ptr = strchr(str,c);
    if(ptr) {
        return ptr -str;
    }
    else {
        return -1;
    }
}

static int convertToInteger(int ch) {
    int a;
    int v = 0;
    char *str = "0123456789";
    while((a = chrint(ch,str))>-1) {
        v*=10;
        v+=a;
        ch=nextChar();
    }

    Back(ch);
    return v;
}

int scan(expression *e) {
    int ch=skipWhitespace();
    switch(ch) {
        case '+': e->op = ADD;
                  break;
        case '-': e->op = SUB;
                  break;
        case '/': e->op = DIV;
                  break;
        case '*': e->op = MUL;
                  break;
        case EOF: //e->op = NA; /*test*/
                  return 0;
        default : if(ch>='0' && ch<='9') {
                    e->val = convertToInteger(ch);
                    e->op = INT;
                    }
                  else {
                      printf("Character %c (line %d) is not an integer literal, whitespace or operator",ch,line);
                      exit(1);
                    }
                  break;
    }
    return 1;
}

static void scInp() {
  expression e;

  while (scan(&e)) {
    printf("Token %s", ops[e.op]);
    if (INT==e.op)
      printf(", value %d", e.val);
    printf("\n");
  }
}

#endif