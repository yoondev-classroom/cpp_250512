// 13_stack.cpp
#include <iostream>
using namespace std;

// 스택 자료구조를 만들어봅시다.
// - LIFO(Last In First Out)
// - 가장 마지막에 삽입된 요소가 먼저 나옵니다.

// 1. 전역 변수
//  - 문제점: 여러개의 스택을 제공하기 어렵습니다.
int buff[10];
int top = 0;

void Push(int n)
{
    // buff[top] = n;
    // ++top;

    buff[top++] = n;
}

int Pop()
{
    return buff[--top];
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    cout << Pop() << endl;
    cout << Pop() << endl;
    cout << Pop() << endl;
}