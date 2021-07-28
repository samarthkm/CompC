#ifndef PARSE_H
#define PARSE_H
#include "../lexer/lex.h"
#include "../lexer/lexInit.h"
#include "parseInit.h"

extern expression e;

int ex(int op) {
    printf("%d\n",op);
    switch(op) {
        case ADD: return OPADD;
        case MUL: return OPMUL;
        case SUB: return OPSUB;
        case DIV: return OPDIV;
        default: fprintf(stderr,"operand not identified, Line number %d\n",line);
                 exit(1);
    }
}

node* initNode(int op,int val,node* left,node* right) {
    node* n = (node*)malloc(sizeof(node));
    if(n==NULL) {
        fprintf(stderr,"Error in initNode while allocating memory\n");
        exit(1);
    }
    n->op=op;
    n->val=val;
    n->left=left;
    n->right=right;
    return n;
}

node* initLeaf(int op,int val) {
    return initNode(op,val,NULL,NULL);
}

node* unarNode(int op,int val,node* left) {
    return initNode(op,val,left,NULL);
}

node* parseP() {
    node* n;
    switch(e.op) {
        case OPINT: initLeaf(INT,e.val);
                    scan(&e);
                    return n;
        default:    fprintf(stderr,"Error on line %d\n",line);
                    exit(1);
    }
}

node* parse() {
    node* l = parseP();
    if(e.op==NA) return l;
    int operation = ex(e.op);
    scan(&e);
    node* r=parse();
    node* n=initNode(operation,0,l,r);
    return n;
}

int evalTree(node* n) {
    int l,r;
    if(n->left) l=evalTree(n->left);
    if(n->right) r=evalTree(n->right);
    switch(n->op) {
        case OPADD:return l+r;
        case OPSUB:return l-r;
        case OPMUL:return l*r;
        case OPDIV:return l/r;
        case OPINT:return n->val;
        default:fprintf(stderr,"Invalid operator %d\n",n->op);
                exit(1);
    }
}

#endif