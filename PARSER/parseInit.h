#ifndef PARSEINIT_H
#define PARSEINIT_H

enum{
    OPADD,OPSUB,OPMUL,OPDIV,OPINT
};

typedef struct node {
    int val;
    int op;
    struct node *left;
    struct node *right;
}node;

#endif