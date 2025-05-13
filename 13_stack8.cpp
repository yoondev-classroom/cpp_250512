// 13_stack8.cpp
#include <iostream>
using namespace std;

// C++ 표준 라이브러리(STL, Standard Template Library)에는 이미 스택이 존재합니다.
#include <stack>

int main()
{
    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    // STL의 스택은 데이터를 참조하는 연산(top)과, 제거하는 연산(pop)이 분리되어 있습니다.
    cout << s1.top() << endl;
    s1.pop();

    cout << s1.top() << endl;
    s1.pop();

    cout << s1.top() << endl;
    s1.pop();
}