// 25_다형성.cpp
#include <iostream>
using namespace std;

class Animal
{
};

// * 중요: 객체 지향 설계에서 말하는 상속은
//    C++에서의 public 상속입니다.
//    protected 상속 / private 상속은
//    객체 지향에서 말하는 상속과 다릅니다.

class Dog : public Animal
// class Dog
{
};

// is-a 관계
// : <자식 클래스> is a(n) <부모 클래스>
// => Upcasting
//   부모 클래스의 포인터 / 참조 타입을 통해
//   자식 객체를 참조할 수 있습니다.

int main()
{
    Animal a;
    Dog d;

    Animal *pa = &a;
    Animal &ra = a;

    Dog *pd = &d;
    Dog &rd = d;

    // 자식 객체는 부모 포인터/참조 타입으로의 암묵적인
    // 변환이 허용됩니다.
    // => Upcasting
    //  : 부모의 포인터 또는 참조를 통해 자식 객체를 참조할 수 있습니다.
    Animal *pa2 = &d;
    Animal &ra2 = d;

    // => Downcasting은 암묵적으로 허용되지 않습니다.
    //    명시적인 캐스팅이 필요합니다.
    // Dog *p = &a;
}