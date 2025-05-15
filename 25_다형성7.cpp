// 25_다형성7.cpp
#include <iostream>
using namespace std;

// 핵심: 부모의 소멸자는 반드시 가상 소멸자 이어야 합니다.
//  - 모든 클래스가 상속이 가능한 것이 아닙니다.
//    상속을 위해 설계된 클래스에 대해서만 상속을 사용해야 합니다.

class Animal
{
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal
{
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
};

int main()
{
    Animal *p = new Dog;
    delete p;
}

#if 0
int main()
{
    Dog d;
}
#endif