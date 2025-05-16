// 30_연산자오버로딩9.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 아무일도 하지 않는
//    기본 생성자를 제공합니다.
// 2. 사용자가 생성자를 1개라도 제공하면, 컴파일러는 기본 생성자를 제공하지 않습니다.
// 3. 사용자가 복사 생성자를 제공하지 않으면, 컴파일러는 멤버를 복사하는 복사 생성자를
//    제공합니다.
// 4. 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 멤버를 복사하는 대입 연산자를
//    제공합니다.

class Point
{
    int x;
    int y;

public:
    Point(int a, int b)
        : x{a}, y{b} {}

    Point(const Point &rhs)
        : x{rhs.x}, y{rhs.y}
    {
        cout << "Point(const Point&)" << endl;
    }

    Point &operator=(const Point &rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }
};

int main()
{
    Point pt{10, 20};

    Point pt2{pt}; // 복사 생성자
    pt2 = pt = pt; // 대입 연산자
    // pt2.operator=(pt);
}

// 연산자
// 1) 이항, 단항
// 2) 연산자 우선 순위
// 3) 연산 방향

#if 0
int main()
{
    int n1, n2, n3;

    //  int a = 10 + 20;

    // n1 = n2 = n3 = 10;
    // n1.operator=(n2).operator=(n3)
}
#endif

// * 정리
// 1. 연산자 우선순위는 변경되지 않습니다.
// 2. 연산자의 피 연산자 개수도 변경되지 않습니다.
// 3. 연산자 오버로딩을 통해 새로운 연산자를 제공할 수 없습니다.
// 4. 연산자 오버로딩이 허용되지 않는 연산자도 있습니다.
//     범위 연산자(::), 접근 연산자(a.foo), ?:(3항 연산자)
// 5. 반드시 피 연산자 중 하나는 사용자 정의 타입(구조체, 클래스,..)이어야 합니다.
// 6. 반드시 멤버 함수를 통해서만 제공해야 하는 연산자가 있습니다.
//  => 클래스의 제작자만 해당하는 연산자 오버로딩을 제공할 수 있습니다.
//    - 대입 연산자
//       a = b;
//    - 호출 연산자
//       a()
//    - 포인터 참조 연산 / 객체 포인터 연산
//       *a / a->foo