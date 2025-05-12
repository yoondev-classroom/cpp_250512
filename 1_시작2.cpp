// 1_시작2.cpp
#if 0
#include <stdio.h> // C언어 헤더

int main()
{
    printf("Hello, C\n"); // C언어 함수
}
#endif

#if 0
// C++도 표준 입출력 라이브러리가 있습니다.
#include <iostream>
// C++의 표준 입출력 라이브러리 헤더 파일입니다.
// C++의 라이브러리의 헤더 파일은 헤더 파일 확장자가 없는
// 경우가 많습니다.

int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif

#if 0
// C에서 사용하는 표준 입력
#include <stdio.h> // scanf
int main()
{
    int n = 0;
    scanf("%d", &n);
    // * 함수를 통해 변수의 값을 변경하기 위해서는
    //   주소를 전달해야 합니다.
    // * 변수의 주소를 얻는 방법은 & 연산자 입니다.

    printf("n: %d\n", n);
}

#endif

#include <iostream>

// 표준 출력: std::cout
// 표준 입력: std::cin

int main()
{
    int n = 0;
    std::cin >> n;

    std::cout << "n: " << n << std::endl;
}