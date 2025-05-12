// 6_string2.cpp
#include <iostream>
using namespace std;

#include <string>
// - std::string

// 1. 문자열 연산을 연산자(비교, 복사, 연결)를 통해서 수행할 수 있습니다.
// 2. 메모리 관리가 자동적으로 수행됩니다.
//    SSO(Simple String Optimization)
//    - 짧은 문자열은 스택을 통해서 관리하고, 긴 문자열은 동적으로 처리합니다.

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2)
    {
        cout << "동일한 문자열" << std::endl;
    }

    std::string s3 = s1;      /* 복사 */
    std::string s4 = s1 + s2; /* 연결 */
}