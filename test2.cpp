// test2.cpp
#include <iostream>
using namespace std;

// int add(int a, int b); // 선언, 헤더를 통해서 제공됩니다.
#include "test.h"
#include "calc.h"

int main()
{
    int result = add(10, 20);
    cout << result << endl;
}