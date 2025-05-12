// 6_string.cpp
#include <iostream>
using namespace std;

// C 문자열
// * 정의: '\0' 문자로 종료되는 char 배열

#if 0
int main()
{
    char s[6];
    s[0] = 'h';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '\0'; // 널 문자

    printf("%s\n", s);
    cout << s << endl;

    char s2[] = "hello";
}
#endif

// #include <string.h>
#include <cstring>
// C 문자열 문제점
// 1) 널 문자 처리를 신경써야 됩니다.
// 2) 문자열 연산에 대해서 별도의 라이브러리 함수를 이용해야 합니다.
// 3) 문자열 처리를 할때, 메모리 관리도 직접 수행해야 합니다.
//    잘못된 연산을 수행할 경우, 미정의 동작이 발생합니다.

int main()
{
    char s1[] = "hello";
    char s2[] = "hello";

    if (strcmp(s1, s2) == 0)
    {
        printf("동일한 문자열\n");
    }
    else
    {
        printf("동일한 문자열 아닙니다.\n");
    }

    char s3[10];
    strcpy(s3, s1);
    printf("copy: %s\n", s3);

    char s4[20];
    strcpy(s4, s1);
    strcat(s4, s2);

    printf("cat: %s\n", s4);
}