// test1.cpp
#include "test.h"

int add(int a, int b) { return a + b; }

void goo() { foo(); }
void foo() { goo(); }
