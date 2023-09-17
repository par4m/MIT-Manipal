#include "stdio.h"

void Ret() { printf("Nothing"); }

int FUnc() { return 0; }

int main(int argc, char *argv[]) {

  printf("AK");
  FUnc();
  Ret();
  return 0;
}
