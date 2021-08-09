#include "parse.h"

expression e;

void main(int argc, char *argv[]) {
  inp = fopen(argv[1], "r");
  scan(&e);
  node* n = parse(0);
  printf("%d\n",evalTree(n));
  exit(0);
}

