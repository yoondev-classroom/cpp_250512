// 27_다운캐스팅.cpp
#include <iostream>
using namespace std;

// 부모의 소멸자는 반드시 가상 함수 이어야 합니다.
class Animal
{
public:
    int age = 10;

    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    int color = 42;
};

#if 0
int main()
{
    Dog d;
    Animal *p = &d;

    // Upcasting은 암묵적인 변환이 허용되지만,
    // Downcasting은 암묵적인 변환이 허용되지 않습니다.
    // => 명시적인 캐스팅이 필요합니다.
    Dog *pDog = static_cast<Dog *>(p);
    cout << pDog->color << endl;
}
#endif

// 1. static_cast는 다운 캐스팅에 사용할 수 있지만,
//    무조건 성공합니다.
#if 0
int main()
{
    // Dog d;
    Animal d;
    Animal *p = &d;

    Dog *pDog = static_cast<Dog *>(p);
    cout << pDog->color << endl; // 미정의 동작
}
#endif

// 2. dynamic_cast를 이용하면, 잘못된 다운 캐스팅을 판단할 수 있습니다.
//  - 실행 시간에 가상함수테이블을 통해 타입을 조사해서, 판단합니다.

#if 1
int main()
{
    Dog d;
    // Animal d;
    Animal *p = &d;

    Dog *pDog = dynamic_cast<Dog *>(p);
    // 다운 캐스팅이 실패할 경우, nullptr을 반환합니다.
    if (pDog)
    {
        cout << pDog->color << endl;
    }
    else
    {
        cout << "Dog 타입이 아닙니다. " << endl;
    }
}
#endif

// 정리
// 1) 다운 캐스팅은 명시적인 캐스팅이 필요합니다.
// 2) static_cast를 통해 컴파일 시간에 다운 캐스팅을 수행할 수 있지만,
//    잘못된 다운 캐스팅을 확인할 수 없습니다.
// 3) dynamic_cast를 통해 실행 시간에 타입을 조사해서, 다운 캐스팅을 안전하게 수행할 수
//    있습니다.
