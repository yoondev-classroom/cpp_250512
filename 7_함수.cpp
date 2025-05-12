// 7_함수.cpp
#include <iostream>
using namespace std;

// * Default Parameter(파라미터 기본값)
// 정의: 전달되지 않은 함수의 인자를 파라미터 기본값으로 컴파일러가 자동으로 처리합니다.

// 주의사항
// 1) 파라미터 기본값은 마지막 파라미터부터 지정할 수 있습니다.
// 2) 파라미터 기본값에 대한 정보는 선언부에 작성되어 있습니다.

int Add(int a, int b, int c = 0, int d = 0); // 선언

int main()
{
    int result = 0;

    result = Add(10, 20, 30, 40);
    cout << result << endl;

    // result = Add(10, 20, 30, 0);
    result = Add(10, 20, 30);
    cout << result << endl;

    // result = Add(10, 20, 0, 0);
    result = Add(10, 20);
    cout << result << endl;
}

// 구현부(정의부)
int Add(int a, int b, int c /* = 0 */, int d /* = 0 */)
{
    return a + b + c + d;
}
