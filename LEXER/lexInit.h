

#ifndef LEXINIT_H
#define LEXINIT_H
#include <stdio.h>

int back;
int line;
FILE *inp;

enum{
    ADD,SUB,MUL,DIV,INT,NA
};

typedef struct expression {
    int val;
    int op;
}expression;

#endif