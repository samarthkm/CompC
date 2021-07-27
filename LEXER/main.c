#include"lex.h"

char *ops[] = { "+", "-", "*", "/", "INTEGER" };

static void scInp() {
  expression e;

  while (scan(&e)) {
    printf("Token %s", ops[e.op]);
    if (INT==e.op)
      printf(", value %d", e.val);
    printf("\n");
  }
}

void main(int argc, char *argv[]) {
  inp = fopen(argv[1], "r");
  scInp();
  exit(0);
}

